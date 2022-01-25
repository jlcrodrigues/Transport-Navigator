#include "PathState.h"

void PathState::display()
{
    cout << "Choose Path option\n";
    cout << "2) Fewest Stops\n";
    cout << "1) Return\n";
    cout << "0) Exit\n";
}

void PathState::step(App *app)
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

