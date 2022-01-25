#include "CoordsState.h"

void CoordsState::display()
{
    cout << "Input coords\n";
    cout << "1) Go back\n";
    cout << "0) Exit\n";
}

void CoordsState::step(App *app)
{
    while (true)
    {
        int option = readOption(app);

        switch (option) {
            case 1:
                app->setState(new  ChooseStartState());
                return;
            case 0:
                app->setState(nullptr);
                return;
            default:
                printInvalidOption();
        }
    }
}

