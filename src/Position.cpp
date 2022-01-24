#include <cmath>
#include "Position.h"
Position::Position(const double &latitude, const double &longitude)
{
    this->latitude = latitude;
    this->longitude = longitude;
}
double Position::operator - (const Position &pos) const
{
    double dLat = (this->latitude - pos.latitude) * M_PI / 180.0;
    double dLon = (this->longitude - pos.longitude) * M_PI / 180.0;

    double r_lat1 = (this->latitude) * M_PI / 180.0;
    double r_lat2 = (pos.latitude) * M_PI / 180.0;

    double rav = pow(sin(dLat/2),2) + pow(sin(dLon/2),2) * cos(r_lat1) * cos(r_lat2);
    double rad = 6371;
    double d = 2 * rad * asin(sqrt(rav));
    return d;
}
//TODO
bool Position::operator == (const Position &pos) const
{
    return true;
}
