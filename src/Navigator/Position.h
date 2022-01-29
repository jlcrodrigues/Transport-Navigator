#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
   Position() = default;

   Position(const double& latitude, const double& longitude);

   double getLatitude() const;

   double getLongitude() const;

   double operator - (const Position& pos) const;

   bool operator == (const Position& pos) const;

private:
   double latitude;
   double longitude;
};

#endif
