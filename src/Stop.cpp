#include "Stop.h"

string Stop::getCode() const {return code;}

string Stop::getName() const {return name;}

string Stop::getZone() const {return zone;}

Position Stop::getPosition() const {return position;}

void Stop::loadFromCsv(const string &row)
{
    string col;
    double latitude, longitude;
    stringstream str(row);
    getline(str, col, ',');
    code = col;
    getline(str, col, ',');
    name = col;
    getline(str, col, ',');
    zone = col;
    getline(str, col, ',');
    latitude = stod(col);
    getline(str, col, ',');
    longitude = stod(col);
    position = Position(latitude, longitude);
}

bool Stop::operator==(const Stop &stop)
{
    return code == stop.getCode();
}