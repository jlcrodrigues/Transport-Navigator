#include "Config.h"

Config::Config()
{
    this->maximum_walking_distance = 0.2;
    this->daytime = true;
}

double Config::getWalkingDistance() const {return maximum_walking_distance;}

void Config::setWalkingDistance(const double &distance) {maximum_walking_distance = distance;}

bool Config::isDayTravel() const {return daytime;}

void Config::setDayTime() {daytime = true;}

void Config::setNightTime() {daytime = false;}