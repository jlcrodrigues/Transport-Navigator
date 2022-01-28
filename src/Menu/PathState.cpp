#include "PathState.h"

PathState::PathState(const string &src, const string &dest)
{
    this->src = src;
    this->dest = dest;
}

void PathState::display()
{
    cout << "Choose Path option\n";
    cout << "2) Fewest Stops\n";
    cout << "3) Fewest Distance\n";
    cout << "1) Return\n";
    cout << "0) Exit\n";
}

void PathState::step(App *app)
{
    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 3:
                fewestDistance(app);
                return;
            case 2:
                fewestStops(app);
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

void PathState::displayPath(vector<pair<Stop, string> >& path) const
{
    if (path.size() < 2) cout << "Those stops are not connected.\n";
    string previous_line = path[1].second;
    cout << path[1].second << endl;
    printStop(path[0].first);
    cout << "  ...\n";
    for (int i = 1; i < path.size() - 1; i++)
    {
        if (path[i + 1].second != previous_line)
        {
            previous_line = path[i + 1].second;
            printStop(path[i].first);
            cout << endl;
            cout << path[i + 1].second << endl;
            printStop(path[i].first);
            cout << "  ...\n";
        }
    }
    printStop(path[path.size() - 1].first);
}

void PathState::newPath(App *app)
{
    cout << endl;
    cout << "1) Different route\n";
    cout << "2) Different stops\n";
    cout << "0) Exit\n";

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

void PathState::fewestStops(App* app) {
    vector<pair<Stop, string> > path = app->getNavigator()->getFewestStops(src, dest);
    displayPath(path);
    newPath(app);
}

void PathState::fewestDistance(App *app) {
    vector<pair<Stop, string> > path = app->getNavigator()->getFewestDistance(src, dest);
    displayPath(path);
    newPath(app);
}
