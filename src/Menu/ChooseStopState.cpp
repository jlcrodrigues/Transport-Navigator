#include "ChooseStopState.h"

void ChooseStopState::display(App* app)
{
    printBreak();
    cout << "\tChoosing a stop.\n\n";
    cout << "2) Show available lines\n";
    cout << "1) Go back\n";
    cout << "0) Exit\n";
}

void ChooseStopState::step(App *app) {
    while (true) {
        int option = readOption(app);

        if (option == 2)
        {
            askStop(app);
            return;
        }
        if (option == 1) {
            app->setState(new ChooseStartState());
            return;
        }
        if (option == 0) {
            app->setState(nullptr);
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

    while (src == dest)
    {
        cout << "Starting stop and destination stop can't be the same.\n";
        dest = chooseStop(app);
    }

    app->setState(new PathState(src, dest));
}