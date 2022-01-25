#ifndef APP_H
#define APP_H

#include "Navigator/Navigator.h"
#include "Menu/State.h"

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
    * Change the app's current state.
    * @param state Any state derived class.
    */
   void setState(State* state);

private:
    Navigator* navigator;
    State* state;
};


#endif
