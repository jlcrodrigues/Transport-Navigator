#ifndef CHOOSESTART_H
#define CHOOSESTART_H

#include <iostream>

#include "State.h"
#include "InitialState.h"
#include "ChooseStopState.h"
#include "CoordsState.h"

class ChooseStartState : public State {
    void step(App* app) override;
    void display(App* app) override;
};

#endif
