#ifndef SETTINGSSTATE_H
#define SETTINGSSTATE_H

#include "State.h"
#include "InitialState.h"

class SettingsState : public State {
public:
   void step(App* app) override;
   void display() override;

};


#endif
