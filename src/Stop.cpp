#include "Stop.h"

string Stop::getCode() const {return code;}

string Stop::getName() const {return name;}

string Stop::getZone() const {return zone;}

Position Stop::getPosition() const {return position;}
//TODO
void Stop::loadFromCsv(const string &row)
{
    return;
}