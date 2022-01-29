#include "SettingsState.h"

void SettingsState::display(App* app)
{
    cout << "Settings\n\n";
    cout << "Maximum walking distance: ";
    cout << fixed << setprecision(3) << app->getConfig()->getWalkingDistance() << " km\n";
    cout << "Time of the day: ";
    if (app->getConfig()->isDayTravel()) cout << "Day.\n";
    else cout << "Night.\n";

    cout << endl;
    cout << "3) Change walking distance\n";
    cout << "2) Change time of the day\n";
    cout << endl;
    cout << "1) Go back\n";
    cout << "0) Exit\n";
}

void SettingsState::step(App *app)
{
    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 3:
                changeDistance(app);
                return;
            case 2:
                changeTime(app);
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
