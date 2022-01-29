#ifndef SETTINGSSTATE_H
#define SETTINGSSTATE_H

#include "State.h"
#include "InitialState.h"
#include "Config.h"

class SettingsState : public State {
public:
   void step(App* app) override;
   void display(App* app) override;

private:
   void changeDistance(App* app);

   void changeTime(App* app);

};


#endif
