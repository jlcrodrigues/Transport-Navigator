#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
   /**
    * Position's default constructor.
    */
   Position() = default;

   /**
    * Create a position from a set of coordinates.
    * @param latitude The latitude value.
    * @param longitude The longitude value.
    */
   Position(const double& latitude, const double& longitude);

   /**
    * Get the position's latitude.
    * @return Double with the position's latitude.
    */
   double getLatitude() const;

   /**
    * Get the position's longitude.
    * @return Double with the position's longitude.
    */
   double getLongitude() const;

   /**
    * Get the distance between positions. It is calculated with the Haversine formula.
    * @param pos Position object.
    * @return Absolute value of the distance between positions (double).
    */
   double operator - (const Position& pos) const;

   /**
    * Equality comparator for position.
    * @param pos Position object.
    * @return Returns true if the positions are the same and false otherwise.
    */
   bool operator == (const Position& pos) const;

private:
   double latitude;
   double longitude;
};

#endif
