#include "App.h"

App::App()
{
    navigator.loadStops("../data/stops.csv");
    navigator.loadLines("../data/lines.csv");
    navigator.loadLinesStops("../data/");
}

void App::run()
{

}