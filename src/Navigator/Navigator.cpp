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
        stops_code[stop.getCode()] = i;
        stops_number[i] = stop.getCode();
        stops[stop.getCode()] = stop;
        i++;
    }
    network = Graph(i);
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
    }
}

void Navigator::loadLinesStops(const string& dir_path)
{
    int number_of_stops;
    string row, previous = "";
    for (auto line : lines)
    {
        for (int i = 0; i < 1; i++)
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
                                    line.first);
                }
                previous = row;
            }
        }
    }
}

vector<Stop> Navigator::getFewestStops(const string &src, const string &dest)
{
    vector<Stop> path;
    vector<int> path_int = network.bfsPath(stops_code[src], stops_code[dest]);
    for (int i = 0; i < path_int.size(); i++)
    {
        path.push_back(getStop(path_int[i]));
    }
    return path;
}

Stop Navigator::getStop(const int& number)
{
    return stops[stops_number[number]];
    /*
    map<string, int>::iterator it = stops_map.begin();
    for (int i = 0; i < number; i++) it++;
    return stops[it->first];
     */
}

unordered_map<string, string> Navigator::getLines() {
    return lines;
}

unordered_map<string, Stop> Navigator::getStops() {
    return stops;
}