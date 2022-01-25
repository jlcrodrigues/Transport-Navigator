#include "State.h"

void State::run(App *app)
{
    display();
    step(app);
}