#ifndef STATE_H
#define STATE_H

#include "App.h"

class App;

class State {
public:
   void run(App* app);

protected:
   virtual void step(App* app);
   virtual void display();
};


#endif
