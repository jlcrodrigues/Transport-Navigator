#include "SettingsState.h"

void SettingsState::display()
{
    cout << "Settings\n";
    cout << "1) Go back\n";
    cout << "0) Exit\n";
}

void SettingsState::step(App *app)
{
    while (true)
    {
        int option = readOption(app);

        switch (option) {
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
