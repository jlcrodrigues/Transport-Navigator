#ifndef PATHSTATE_H
#define PATHSTATE_H

#include <iostream>

#include "../src/Navigator/Stop.h"
#include "State.h"
#include "ChooseStartState.h"

class PathState : public State {
public:
   /**
    * Construct a PathState with source and destination stops.
    * @param src The stop where the path begins.
    * @param dest The destination stop.
    */
   PathState(const string& src, const string& dest);

   void step(App* app) override;
   void display() override;
private:
   /**
    * Displays a path.
    * @param path Vector of stops.
    */
   void displayPath(vector<Stop>& path) const;

   /**
    * Choose a new filter or go back to choose different stops.
    * @param app Pointer to the main application.
    */
   void newPath(App* app);

   /**
    * Calculate and display the path with the least stops.
    * @param app Pointer to the main application.
    */
   void fewestStops(App* app);

   string src;
   string dest;
};


#endif
