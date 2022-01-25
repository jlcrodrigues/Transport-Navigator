#include "State.h"

void State::run(App *app)
{
    display();
    step(app);
}

int State::readOption(App* app) const
{
    int option;

    while (!(cin >> option))
    {
        if (cin.eof()) app->setState(nullptr);
        else
        {
            cin.clear();
            cin.ignore(1000000, '\n');
            printInvalidOption();
        }
    }
    return option;
}

void State::printInvalidOption() const
{
    cout << "Invalid option. Try again.\n";
}