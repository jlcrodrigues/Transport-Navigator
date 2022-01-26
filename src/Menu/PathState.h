#ifndef PATHSTATE_H
#define PATHSTATE_H

#include <iostream>

#include "../src/Navigator/Stop.h"
#include "State.h"
#include "ChooseStartState.h"

class PathState : public State {
public:
   PathState(const string& src, const string& dest);
   void step(App* app) override;
   void display() override;
private:
   void displayPath(vector<Stop>& path) const;
   void newPath(App* app);
   void fewestStops(App* app);
   string src;
   string dest;
};


#endif
