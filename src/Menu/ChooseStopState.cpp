#include "ChooseStopState.h"

void ChooseStopState::display()
{
    cout << "Choose a stop\n";
    cout << "1) Go back\n";
    cout << "0) Exit\n";
}

void ChooseStopState::step(App *app)
{
    while (true)
    {
        int option = readOption(app);

        switch (option) {
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

