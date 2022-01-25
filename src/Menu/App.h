#ifndef APP_H
#define APP_H

#include "Navigator/Navigator.h"
#include "Menu/State.h"
//#include "Menu/InitialState.h"

class State;

class App
{
public:
   App();

   /**The application main loop.**/
   void run();

   Navigator* getNavigator() const;

   void setState(State* state);

private:
    Navigator* navigator;
    State* state;
};


#endif
