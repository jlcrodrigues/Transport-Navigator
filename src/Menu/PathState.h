#ifndef PATHSTATE_H
#define PATHSTATE_H

#include <iostream>

#include "State.h"
#include "ChooseStartState.h"

class PathState : public State {
   void step(App* app) override;
   void display() override;
};


#endif
