#ifndef COORDSSTATE_H
#define COORDSSTATE_H

#include <iostream>

#include "State.h"
#include "ChooseStartState.h"
#include "PathState.h"

class CoordsState : public State {
   void step(App* app) override;
   void display() override;
};

#endif
