#ifndef INITIALSTATE_H
#define INITIALSTATE_H

#include <iostream>

#include "State.h"
#include "ChooseStartState.h"
#include "SettingsState.h"

class InitialState : public State {
   void step(App* app) override;
   void display() override;
};


#endif
