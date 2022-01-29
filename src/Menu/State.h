#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <iomanip>

#include "App.h"

class App;

class State {
public:
   void run(App* app);

protected:
   /**
    * Reads an integer until valid input.
    * @param app Pointer to the main application.
    * @return - Returns an integer from user input.
    */
   int readOption(App* app) const;

/**
 * Reads a string until valid input.
 * @param app Pointer to the main Application.
 * @return Returns a string from user input
 */
    string readOptionString(App *app) const;


    /**
    * Outputs the invalid option message to the console.
    */
   void printInvalidOption() const;

   /**
    * Handle the specific events in each state.
    * @param app Pointer to the main application.
    */
   virtual void step(App* app) {}

   /**
    * Display the specific contents of each state.
    * @param app Pointer to the main application.
    */
   virtual void display(App* app) {}

};


#endif
