#ifndef STOP_H
#define STOP_H

#include "Position.h"

#include <string>
#include <sstream>

using namespace std;

class Stop
{
public:
   Stop() = default;

   string getCode() const;
   string getName() const;
   string getZone() const;
   Position getPosition() const;

   /**
    * Set the name of a stop.
    * @param name New stop name.
    */
   void setName(const string& name);

   /**
    * Defines the Stop from the fields in a csv row.
    * @param row A string with the Stop attributes separated by commas.
    */
   void loadFromCsv(const string& row);

   /**
    * Equal operator. Stops are considered equal if they have the same code.
    * @param stop Stop object to compare.
    * @return Returns true if the stops have the same code, false otherwise.
    */
   bool operator == (const Stop& stop);

private:
   string code;
   string name;
   string zone;
   Position position;
};

#endif
