#include "Position.h"

Position::Position(const double &latitude, const double &longitude)
{
    this->latitude = latitude;
    this->longitude = longitude;
}
//TODO
double Position::operator - (const Position &pos) const
{
    return 0;
}
//TODO
bool Position::operator == (const Position &pos) const
{
    return true;
}
