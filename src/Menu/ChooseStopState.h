#ifndef CHOOSESTOP_H
#define CHOOSESTOP_H

#include "State.h"
#include "ChooseStartState.h"
#include "PathState.h"

class ChooseStopState : public State {
   void step(App* app) override;
   void display(App* app) override;
private:
   void askStop(App* app) const;
};


#endif
