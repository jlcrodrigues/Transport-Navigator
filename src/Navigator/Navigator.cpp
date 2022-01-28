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
        result.push_back({stops[path[i].first], lines[path[i].second]});
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
    return readPath(network.lowestLinesPath(stops_code[src], stops_code[dest]));
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