#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
   Position() = default;

   Position(const double& latitude, const double& longitude);

   double getLatitude() const;

   double getLongitude() const;

   /**
    * Subtraction operator. Uses the Haversine formula to calculate the distance between Positions.
    * @param pos Position object to subtract.
    * @return Returns a double with the value of the distance between the 2 Positions.
    */
   double operator - (const Position& pos) const;

   /**
    * Equal operator. Positions are considered equal if they have the same latitude and longitude.
    * @param pos Position object to compare.
    * @return Returns true if the stops positions have the same latitude and longitude, false otherwise.
    */
   bool operator == (const Position& pos) const;

private:
   double latitude;
   double longitude;
};

#endif
