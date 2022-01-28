#include "App.h"

App::App()
{
    navigator = new Navigator();
    navigator->loadStops("../data/stops.csv");
    navigator->loadLines("../data/lines.csv");
    navigator->loadLinesStops("../data/");
    config = new Config();
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

Config* App::getConfig() const
{
    return config;
}

void App::setState(State* state)
{
    this->state = state;
}