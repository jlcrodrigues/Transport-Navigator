#include "ChooseStartState.h"

void ChooseStartState::display()
{
    cout << "Choose Start\n";
    cout << "2) Stop\n";
    cout << "3) Coordinate\n";
    cout << "1) Go back\n";
    cout << "0) Exit\n";
}

void ChooseStartState::step(App *app)
{
    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 2:
                app->setState(new ChooseStopState());
                return;
            case 3:
                app->setState(new CoordsState());
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

