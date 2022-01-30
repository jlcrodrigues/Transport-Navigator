#include "PathState.h"

PathState::PathState(const string &src, const string &dest)
{
    this->src = src;
    this->dest = dest;
}

void PathState::display(App* app)
{
    printBreak();
    cout << "\tChoose a path:\n\n";
    cout << "5) Fewest Stops\n";
    cout << "4) Least Distance\n";
    cout << "3) Least line changes\n";
    cout << "2) Cheapest\n";
    cout << "1) Go back\n";
    cout << "0) Exit\n";
}

void PathState::step(App *app)
{
    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 5:
                fewestStops(app);
                return;
            case 4:
                fewestDistance(app);
                return;
            case 3:
                fewestLines(app);
                return;
            case 2:
                fewestZones(app);
                return;
            case 1:
                app->setState(new ChooseStartState());
                return;
            case 0:
                app->setState(nullptr);
                return;
            default:
                printInvalidOption();
        }
    }
}

void PathState::printStop(const Stop &stop) const
{
    cout << "  " << left << setw(6)  << stop.getCode();
    cout << " - "<< stop.getName() << endl;
}

void PathState::printLine(const Stop &src, const Stop &dest, const string& line) const
{
    if (line == "_WALK")
    {
        cout << "Walk ";
        cout << fixed << setprecision(3) << src.getPosition() - dest.getPosition();
        cout << " km.\n";
    }
    else
    {
        cout << line << endl;
    }
}

void PathState::displayPath(vector<pair<Stop, string> >& path) const
{
    if (path.size() < 2) {
        cout << "Those stops are not connected.\n";
        return;
    }
    string previous_line = path[1].second;
    printLine(path[0].first, path[1].first, path[1].second);
    printStop(path[0].first);
    cout << "  ...\n";
    for (int i = 1; i < path.size() - 1; i++)
    {
        if (path[i + 1].second != previous_line)
        {
            previous_line = path[i + 1].second;
            printStop(path[i].first);
            cout << endl;
            printLine(path[i].first, path[i + 1].first, path[i + 1].second);
            printStop(path[i].first);
            cout << "  ...\n";
        }
    }
    printStop(path[path.size() - 1].first);

    cout << endl;

    //for (auto p: path) cout << p.first.getCode() << " "
    //<< p.first.getName() << " " << p.second << endl;
}

void PathState::newPath(App *app)
{
    cout << endl;
    cout << "New path\n";
    cout << "1) Different route\n";
    cout << "2) Different stops\n";
    cout << "0) Exit\n";

    while(true) {
        int option = readOption(app);

        switch (option) {
            case 1:
                app->setState(new PathState(src, dest));
                return;
            case 2:
                app->setState(new ChooseStartState());
                return;
            case 0:
                app->setState(nullptr);
                return;
            default:
                printInvalidOption();
        }
    }
}

void PathState::fewestStops(App* app) {
    vector<pair<Stop, string> > path = app->getNavigator()->getFewestStops(src, dest);
    displayPath(path);
    if (path.size() > 0)
        cout << "The path with fewest stops goes trough a total of " << path.size() << " stops.\n\n";
    newPath(app);
}

void PathState::fewestDistance(App *app) {
    vector<pair<Stop, string> > path = app->getNavigator()->getFewestDistance(src, dest);
    displayPath(path);
    if (path.size() > 0) {
        cout << "Path calculated with a total distance of ";
        cout << fixed << setprecision(3) << getDistance(path);
        cout << " km.\n\n";
    }
    newPath(app);
}

double PathState::getDistance(vector<pair<Stop, string>> path)
{
    double distance = 0;
    for (int i = 0; i < path.size() - 1; i++)
    {
        distance += path[i].first.getPosition() - path[i + 1].first.getPosition();
    }
    return distance;
}

void PathState::fewestLines(App *app) {
    vector<pair<Stop, string> > path = app->getNavigator()->getFewestLines(src, dest);
    displayPath(path);
    if (path.size() > 0)
        cout << "Path found with a total of " << getLineCount(path) << " different lines taken.\n\n";
    newPath(app);
}

int PathState::getLineCount(vector<pair<Stop, string>> path)
{
    set<string> lines;
    for (int i = 0; i < path.size(); i++)
    {
        lines.insert(path[i].second);
    }
    return lines.size();
}

void PathState::fewestZones(App *app) {
    vector<pair<Stop, string> > path = app->getNavigator()->getFewestZones(src, dest);
    displayPath(path);
    if (path.size() > 0)
        cout << "The cheapest path goes through a total of " << getZoneCount(path) << " different zones.\n\n";
    newPath(app);
}

int PathState::getZoneCount(vector<pair<Stop, string> > path)
{
    set<string> zones;
    for (int i = 0; i < path.size(); i++)
    {
        zones.insert(path[i].first.getZone());
    }
    return zones.size();
}