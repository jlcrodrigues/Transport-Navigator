#include "InitialState.h"

void InitialState::display()
{
    cout << "Initial Page\n";
    cout << "1) Start\n";
    cout << "2) Exit\n";
}

void InitialState::step(App *app)
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

