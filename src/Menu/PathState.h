#ifndef PATHSTATE_H
#define PATHSTATE_H

#include <iostream>
#include <utility>
#include <iomanip>

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
   void display(App* app) override;
private:
   /**
    * Prints a stop with the needed formatting.
    * @param stop A stop object to display.
    */
   void printStop(const Stop& stop) const;

   /**
    * Print a line correctly to the screen.
    * @param src The starting stop.
    * @param dest The destination stop.
    * @param line The line being taken.
    */
   void printLine(const Stop& src, const Stop& dest, const string& line) const;

   /**
    * Displays a path.
    * @param path Vector of stops.
    */
   void displayPath(vector<pair<Stop, string> >& path) const;

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

   /**
    * Calculate and display the path with the lowest distance between stops.
    * @param app Pointer to the main application.
    */
   void fewestDistance(App* app);

   /**
    * Calculate and display the path with the lowest amount of lines used between stops.
    * @param app Pointer to the main application.
    */
   void fewestLines(App* app);

   /**
    * Calculate and display the cheapest path between stops.
    * @param app Pointer to the main application.
    */
   void fewestZones(App* app);

   string src;
   string dest;
};


#endif
