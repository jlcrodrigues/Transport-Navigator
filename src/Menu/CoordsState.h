#ifndef COORDSSTATE_H
#define COORDSSTATE_H

#include <iostream>

#include "State.h"
#include "ChooseStartState.h"
#include "PathState.h"
#include "../src/Navigator/Position.h"

class CoordsState : public State {
public:
   void step(App* app) override;
   void display() override;
private:
   Position getPosition(App* app);
   double getDouble(App* app, const string& message) const;
   string chooseStop(App* app, const Position& position) const;
   bool in(const string& code, const vector<Stop>& stops) const;
   Position position;
};

#endif
