#include "Config.h"

Config::Config()
{
    this->maximum_walking_distance = 2;
}

double Config::getWalkingDistance() const {return maximum_walking_distance;}

void Config::setWalkingDistance(const double &distance) {maximum_walking_distance = distance;}