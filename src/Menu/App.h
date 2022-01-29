#ifndef APP_H
#define APP_H

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
    * Change the app's current state.
    * @param state Any state derived class.
    */
   void setState(State* state);

private:
   Config* config;
    Navigator* navigator;
    State* state;
};


#endif
