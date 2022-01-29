#include "ChooseStopState.h"

void ChooseStopState::display(App* app)
{
    cout << "\nChoose a stop.\n";
    cout << "3) Show available lines\n";
    cout << "2) Go back\n";
    cout << "0) Exit\n";
}

void ChooseStopState::step(App *app) {
    while (true) {
        int option = readOption(app);

        if (option == 2) {
            app->setState(new ChooseStartState());
            return;
        }
        if (option == 0) {
            app->setState(nullptr);
            return;
        }
        if (option == 3)
        {
            askStop(app);
            return;
        }
        printInvalidOption();
    }
}

void ChooseStopState::askStop(App* app) const
{
    string src, dest;

    src = chooseStop(app);
    dest = chooseStop(app);

    while (src != dest)
    {
        cout << "Starting stop and destination stop can't be the same.\n";
        dest = chooseStop(app);
    }

    app->setState(new PathState(src, dest));
}