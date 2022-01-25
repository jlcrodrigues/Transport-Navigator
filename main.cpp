#include "Menu/App.h"
#include "Menu/InitialState.h"

int main()
{
    App app;
    app.setState(new InitialState());
    app.run();
    return 0;
}