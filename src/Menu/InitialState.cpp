#include "InitialState.h"

void InitialState::display(App* app)
{
    printBreak();
    cout << "\tMenu\n\n";
    cout << "2) Start\n";
    cout << "1) Settings\n";
    cout << "0) Exit\n";
}

void InitialState::step(App *app)
{
    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 2:
                app->setState(new ChooseStartState());
                return;
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

