#include "State.h"

void State::run(App *app)
{
    display(app);
    step(app);
}

int State::readOption(App* app) const
{
    int option;

    while (!(cin >> option))
    {
        if (cin.eof()) app->setState(nullptr);
        else
        {
            cin.clear();
            cin.ignore(1000000, '\n');
            printInvalidOption();
        }
    }
    return option;
}

string State::readOptionString(App *app) const {
    string option;

    while (!(cin >> option))
    {
        if (cin.eof()) app->setState(nullptr);
        else
        {
            cin.clear();
            cin.ignore(1000000, '\n');
            printInvalidOption();
        }
    }
    return option;

}

void State::printInvalidOption() const
{
    cout << "Invalid option. Try again.\n";
}

string State::chooseStop(App *app) const
{
    vector<string> line_stops;
    string line = "../data/line_" + chooseLine(app) + ".csv";

    line_stops = loadLineStops(line);
    printStops(app, line_stops);
    cout << "\nChoose a code from the stops above.\n";

    string stop = readOptionString(app);
    for_each(stop.begin(), stop.end(), [](char &c) { c = ::toupper(c); });
    while (!checkStop(stop, line_stops))
    {
        cout << "Invalid stop. Please try again.\n";
        stop = readOptionString(app);
        for_each(stop.begin(), stop.end(), [](char &c) { c = ::toupper(c); });
    }

    return stop;
}

string State::chooseLine(App* app, bool directed) const
{
    string line;
    displayLines(app);

    line = readOptionString(app);
    for_each(line.begin(), line.end(), [](char &c) { c = ::toupper(c); });
    while (!checkLine(app, line))
    {
        cout << "Invalid line. Please try again:\n";
        line = readOptionString(app);
        for_each(line.begin(), line.end(), [](char &c) { c = ::toupper(c); });
    }

    if (!directed) return line;

    if (line == "300" || line == "301" || line == "302" || line == "303")
        return (line + "_0");

    cout << "Choose a direction (0 or 1):\n";
    int dir = readOption(app);
    while (dir != 0 && dir != 1) {
        printInvalidOption();
        dir = readOption(app);
    }
    return (line + "_" + to_string(dir));
}

void State::displayLines(App* app) const
{
    cout << endl;
    for (auto l: app->getNavigator()->getLines())
    {
        if (app->getConfig()->isDayTravel() == (l.first.back() == 'M')) continue;
        cout << l.first << ": " << l.second << "\n";
    }
    cout << "\nInsert the code from the lines above:\n";
}

bool State::checkLine(App *app, string option) const {
    for (auto line: app->getNavigator()->getLines()) {
        if (option == line.first) {
            if (app->getConfig()->isDayTravel() == (line.first.back() == 'M')) continue;
            cout << "You chose line: " << line.second << "\n";
            return true;
        }
    }
    return false;
}

bool State::checkStop(const string& stop, const vector<string>& stops) const
{
    for (auto s: stops)
    {
        if (s == stop) return true;
    }
    return false;
}

vector<string> State::loadLineStops(const string& path) const
{
    vector<string> line_stops;
    fstream file(path);
    string row;
    getline(file, row);
    while (getline(file, row)) {
        line_stops.push_back(row);
    }
    file.close();
    return line_stops;
}

void State::printStops(App* app, const vector<string> &stops) const
{
    cout << endl;
    for (auto stop: stops)
    {
        cout << stop << " - " << app->getNavigator()->getStops()[stop].getName() << endl;
    }
}