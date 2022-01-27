#include "PathState.h"

PathState::PathState(const string &src, const string &dest)
{
    cout << "helo";
    cout << src << "----" << dest;
    this->src = src;
    this->dest = dest;
    cout << src << " " << dest;
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

void PathState::displayPath(vector<Stop>& path) const
{
    for (auto stop: path)
    {
        cout << stop.getCode() << "  " << stop.getName() << endl;
    }
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
    vector<Stop> path = app->getNavigator()->getFewestStops(src, dest);
    if (path.size() == 0) cout << "Those stops are not connected.\n";
    displayPath(path);
    newPath(app);
}

void PathState::fewestDistance(App *app) {
    vector<Stop> path = app->getNavigator()->getFewestDistance(src, dest);
    if (path.size() == 0) cout << "Those stops are not connected.\n";
    displayPath(path);
    newPath(app);
}
