#include "App.h"

App::App()
{
    navigator = new Navigator();
    navigator->loadStops("../data/stops.csv");
    navigator->loadLines("../data/lines.csv");
    navigator->loadLinesStops("../data/");
    config = new Config();
    //navigator->connectStops(config->getWalkingDistance());
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

void App::setDistance(const double &distance)
{
    config->setWalkingDistance(distance);
    navigator->connectStops(distance);
}

void App::setState(State* state)
{
    this->state = state;
}