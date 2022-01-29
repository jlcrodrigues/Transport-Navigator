#include "Navigator.h"

void Navigator::loadStops(const string &file_path)
{
    int i = 1;
    Stop stop;
    string row;
    ifstream file(file_path);
    if (!file.is_open()) return;
    getline(file, row); //ignore first line
    while (getline(file, row))
    {
        stop.loadFromCsv(row);
        //stop.setName(capitalize(stop.getName()));
        stops_code[stop.getCode()] = i;
        stops[stop.getCode()] = stop;
        i++;
    }
    network = Graph(i);
    map<string, int>::iterator it = stops_code.begin();
    for (; it != stops_code.end(); it++)
    {
        network.setNodeCode(it->second, it->first);
    }
}

void Navigator::loadLines(const string &file_path)
{
    string row, code, name;
    ifstream file(file_path);
    if (!file.is_open()) return;
    getline(file, row); //ignore first line
    while (getline(file, row))
    {
        stringstream str(row);
        getline(str, code, ',');
        getline(str, name, ',');
        lines[code] = name;
        //lines[code] = capitalize(name);
    }
}

void Navigator::loadLinesStops(const string& dir_path)
{
    int number_of_stops;
    string row, previous = "";
    for (auto line : lines)
    {
        for (int i = 0; i < 2; i++)
        {
            previous = "";
            ifstream file(dir_path + "line_" + line.first + "_" + to_string(i) + ".csv");
            if (!file.is_open()) continue;
            getline(file, row); //number of stops;
            number_of_stops = stoi(row);
            for (int j = 0; j < number_of_stops; j++)
            {
                getline(file, row);
                if (previous != "") {
                    network.addEdge(stops_code[previous],
                                    stops_code[row],
                                    stops[row].getPosition() - stops[previous].getPosition(),
                                    line.first);
                }
                previous = row;
            }
        }
    }
}

bool Navigator::isClose(const Stop& stop1, const Stop& stop2, const double& distance) const
{
    Position pos1 = stop1.getPosition();
    Position pos2 = stop2.getPosition();
    return (pos2.getLatitude() < pos1.getLatitude() + distance/69
        && pos1.getLatitude() - distance/69 < pos2.getLatitude()
        && pos2.getLongitude() < pos1.getLongitude() + distance/45
        && pos1.getLongitude() - distance/45 < pos2.getLongitude());
}

void Navigator::connectStops(const double& max_distance)
{
    network.setWalkingDistance(max_distance);
    map<string, int>::iterator i = stops_code.begin();
    for (; i != stops_code.end(); i++)
    {
        network.updateWalkingEdges(i->second, max_distance);
        map<string, int>::iterator j = stops_code.begin();
        for (; j != stops_code.end(); j++)
        {
            if (isClose(stops[i->first], stops[j->first], max_distance))
            {
                double distance = stops[i->first].getPosition() - stops[j->first].getPosition();
                if (distance <= max_distance)
                {
                    if (j != i && !network.connected(i->second, j->second))
                    {
                        network.addEdge(i->second, j->second, distance, "_WALK");
                    }
                }
            }
        }
    }
}

void Navigator::setTime(const double &time)
{
    network.setTime(time);
}

vector<Stop> Navigator::getClosestStops(const Position& src, const int& number_of_stops)
{
    map<double, Stop> distances;
    vector<Stop> result;
    for (auto stop: stops)
    {
        distances[src - stop.second.getPosition()] = stop.second;
    }
    map<double, Stop>::iterator it = distances.begin();
    for (int i = 0; i < number_of_stops; i++)
    {
        result.push_back(it->second);
        it++;
    }
    return result;
}

vector<pair<Stop, string> > Navigator::readPath(const vector<pair<string, string> >& path)
{
    vector<pair<Stop, string> > result;
    for (int i = 0; i < path.size(); i++)
    {
        string line = path[i].second;
        if (line != "_WALK") line = lines[line];
        result.push_back({stops[path[i].first], line});
    }
    return result;
}

vector<pair<Stop, string> > Navigator::getFewestStops(const string &src, const string &dest)
{
    return readPath(network.bfsPath(stops_code[src], stops_code[dest]));
}

vector<pair<Stop, string> > Navigator::getFewestDistance(const string &src, const string &dest){
    return readPath(network.dijkstraPath(stops_code[src], stops_code[dest]));
}

vector<pair<Stop, string> > Navigator::getFewestLines(const string &src, const string &dest){
    return readPath(network.leastLinesPath(stops_code[src], stops_code[dest]));
}

unordered_map<string, string> Navigator::getLines() {
    return lines;
}

unordered_map<string, Stop> Navigator::getStops() {
    return stops;
}

string Navigator::capitalize(const string &sentence) const
{
    string word, result = "";
    stringstream s(sentence);
    while (getline(s, word, ' '))
    {
       string new_word = "" + word[0];
       for (int i = 1; i < word.size(); i++)
       {
           new_word += tolower(word[i]);
       }
       result += new_word;
    }
    return result;
}