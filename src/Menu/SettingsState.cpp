#include "SettingsState.h"

void SettingsState::display(App* app)
{
    cout << "Settings\n\n";
    cout << "Maximum walking distance: ";
    cout << fixed << setprecision(3) << app->getConfig()->getWalkingDistance() << " km\n";

    cout << endl;
    cout << "2) Change walking distance\n";
    cout << "1) Go back\n";
    cout << "0) Exit\n";
}

void SettingsState::step(App *app)
{
    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 2:
                changeDistance(app);
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
