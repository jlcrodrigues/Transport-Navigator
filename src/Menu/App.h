#ifndef APP_H
#define APP_H

#include <set>

#include "../src/Navigator/Navigator.h"
#include "State.h"
#include "Config.h"

class State;

class App
{
public:
   App();

   /**The application main loop.**/
   void run();

   /**
    * Get the app's navigator object.
    * @return Pointer to the app's navigator.
    */
   Navigator* getNavigator() const;

   /**
    * Get the app's configuration.
    * @return Pointer to a config object;
    */
   Config* getConfig() const;

   /**
    * Changes the maximum walking distance.
    * @param distance New maximum distance.
    */
   void setDistance(const double& distance);

   /**
    * Change the time of the day.
    * @param time_frame Either "night" or "day".
    */
   void setTime(const string& time_frame);

   /**
    * Get the set of blocked lines.
    * @return String set with all the blocked lines.
    */
   set<string>* getBlockedLines();

   /**
    * Get the set of blocked stops.
    * @return String set with all the blocked stops.
    */
   set<string>* getBlockedStops();

   /**
    * Change the app's current state.
    * @param state Any state derived class.
    */
   void setState(State* state);

private:
   Config* config;
    Navigator* navigator;
    State* state;

    set<string>* blocked_lines;
    set<string>* blocked_stops;
};


#endif
