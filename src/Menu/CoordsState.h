#ifndef COORDSSTATE_H
#define COORDSSTATE_H

#include <iostream>

#include "State.h"
#include "ChooseStartState.h"
#include "PathState.h"
#include "../src/Navigator/Position.h"

class CoordsState : public State {
public:
   void step(App* app) override;
   void display() override;
private:
   /**
    * Read a position from user input.
    * @param app Pointer to the main application.
    * @return Returns a position object made from user input.
    */
   Position getPosition(App* app);

   /**
    * Reads a double from user input.
    * @param app Pointer to the main application.
    * @param message String to be displayed while asking for input.
    * @return Returns a double object.
    */
   double getDouble(App* app, const string& message) const;

   /**
    * Choose a stop from user input.
    * @param app Pointer to the main application.
    * @param position Position to search for the closest stops.
    * @return Returns a string with the chose stop's code.
    */
   string chooseStop(App* app, const Position& position) const;

   /**
    * Check if the code of a stop is in a stop's vector.
    * @param code A stop code.
    * @param stops Vector with Stop object.
    * @return Returns true if the stop is in the vector and false otherwise.
    */
   bool in(const string& code, const vector<Stop>& stops) const;


   Position position;
};

#endif
