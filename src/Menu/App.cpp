#include "App.h"

App::App()
{
    navigator = new Navigator();
    navigator->loadStops("../data/stops.csv");
    navigator->loadLines("../data/lines.csv");
    navigator->loadLinesStops("../data/");
}

void App::run()
{
    while (state != nullptr)
    {
        state->run(this);
    }
}

Navigator* App::getNavigator() const
{
    return navigator;
}

void App::setState(State* state)
{
    this->state = state;
}