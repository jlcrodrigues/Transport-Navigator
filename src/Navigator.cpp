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
        stops_map[stop.getCode()] = i;
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
        getline(str, code);
        getline(str, name);
        lines[code] = name;
    }
}

void Navigator::loadLinesStops(const string& dir_path)
{
    string row, previous = "";
    for (auto line : lines)
    {
        for (int i = 0; i < 2; i++)
        {
            ifstream file(dir_path + "lines_" + line.first + "_" + to_string(i) + ".csv");
            if (!file.is_open()) continue;
            getline(file, row); //ignore number of stops;
            while (getline(file, row))
            {
                if (previous != "")
                    network.addEdge(stops_map[previous],
                                    stops_map[row],
                                    line.first);
                previous = row;
            }
        }
    }
}
