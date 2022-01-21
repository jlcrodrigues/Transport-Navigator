#ifndef STOP_H
#define STOP_H

#include "Position.h"

#include <string>

using namespace std;

class Stop
{
public:
   Stop() = default;

   string getCode() const;
   string getName() const;
   string getZone() const;
   Position getPosition() const;

   void loadFromCsv(const string& row);

private:
   string code;
   string name;
   string zone;
   Position position;
};

#endif
