#include "SettingsState.h"

void SettingsState::display(App* app)
{
    printBreak();
    cout << "Settings\n\n";
    cout << " - Maximum walking distance: ";
    cout << fixed << setprecision(3) << app->getConfig()->getWalkingDistance() << " km\n";
    cout << " - Time of the day: ";
    if (app->getConfig()->isDayTravel()) cout << "Day.\n";
    else cout << "Night.\n";

    cout << endl;
    cout << "5) Change walking distance\n";
    cout << "4) Change time of the day\n";
    cout << "3) Block lines\n";
    cout << "2) Block stops\n";
    cout << "1) Go back\n";
    cout << "0) Exit\n";
}

void SettingsState::step(App *app)
{
    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 5:
                changeDistance(app);
                return;
            case 4:
                changeTime(app);
                return;
            case 3:
                blockLines(app);
                return;
            case 2:
                blockStops(app);
                return;
           case 1:
                app->setState(new InitialState());
                return;
            case 0:
                app->setState(nullptr);
                return;
            default:
                printInvalidOption();
        }
    }
}

void SettingsState::changeDistance(App *app)
{
    cout << "Insert the maximum walking distance allowed (km):\n";
    double distance;

    while (!(cin >> distance))
    {
        if (cin.eof()) app->setState(nullptr);
        else
        {
            cin.clear();
            cin.ignore(1000000, '\n');
            printInvalidOption();
        }
    }

    app->setDistance(distance);
    cout << "\nWalking distance changed to " << distance << " km.\n\n";
    app->setState(new SettingsState());
}

void SettingsState::changeTime(App *app)
{
    cout << "Choose the time you want to travel: (night/day)\n";
    string option = "";
    while (option != "night" && option != "day") {
        while (!(cin >> option)) {
            if (cin.eof()) app->setState(nullptr);
            else {
                cin.clear();
                cin.ignore(1000000, '\n');
                printInvalidOption();
            }
        }
        printInvalidOption();
    }
    app->setTime(option);
    app->setState(new SettingsState());
}

void SettingsState::blockLines(App *app)
{
    while (true)
    {
        printBreak();
        cout << "Blocked lines:\n\n";
        auto it = app->getBlockedLines()->begin();
        for (; it != app->getBlockedLines()->end(); it++)
        {
            cout << " - " << *it << endl;
        }

        cout << endl;
        cout << "3) Add line\n";
        cout << "2) Remove line\n";
        cout << "1) Go back\n";
        cout << "0) Exit\n";

        int option = readOption(app);

        switch (option) {
            case 3:
                addLine(app);
                break;
            case 2:
                removeLine(app);
                break;
            case 1:
                app->setState(new SettingsState());
                return;
            case 0:
                app->setState(nullptr);
                return;
            default:
                printInvalidOption();
        }
    }

}

void SettingsState::addLine(App* app)
{
    string line = chooseLine(app, false);
    app->getBlockedLines()->insert(line);
}

void SettingsState::removeLine(App* app)
{
    string line = chooseLine(app, false);
    app->getBlockedLines()->erase(line);
}

void SettingsState::blockStops(App *app)
{
    while (true)
    {
        printBreak();
        cout << "Blocked stops:\n\n";
        auto it = app->getBlockedStops()->begin();
        for (; it != app->getBlockedStops()->end(); it++)
        {
            cout << " - " << *it << endl;
        }

        cout << endl;
        cout << "3) Add stop\n";
        cout << "2) Remove stop\n";
        cout << "1) Go back\n";
        cout << "0) Exit\n";

        int option = readOption(app);

        switch (option) {
            case 3:
                addStop(app);
                break;
            case 2:
                removeStop(app);
                break;
            case 1:
                app->setState(new SettingsState());
                return;
            case 0:
                app->setState(nullptr);
                return;
            default:
                printInvalidOption();
        }
    }

}

void SettingsState::addStop(App* app)
{
    string stop = chooseStop(app);
    app->getBlockedStops()->insert(stop);
}

void SettingsState::removeStop(App* app)
{
    string stop = chooseStop(app);
    app->getBlockedStops()->erase(stop);
}
