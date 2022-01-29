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
    * Lets the user choose a stop from all the lines.
    * @param app Pointer to the main application.
    * @return Returns a code to a valid stop chosen by the user.
    */
   string chooseStop(App* app) const;

   /**
    * Lets the user choose a valid line.
    * @param app Pointer to the main application.
    * @return Returns a string with the line code and direction.
    */
   string chooseLine(App* app) const;

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

private:
   /**
    * Displays all the available lines.
    * @param app Pointer to the main Application.
    */
   void displayLines(App *app) const;

   /**
    * Checks if inputted line is valid.
    * @param app Pointer to the main application.
    * @param option User input.
    * @return Returns true if the line is valid and false otherwise.
    */
   bool checkLine(App *app, string option) const;

   /**
    * Checks if a stop is valid.
    * @param stop User input stop.
    * @param stops String vector with codes of stops.
    * @return Returns true if the stop exists in the vector and false otherwise.
    */
   bool checkStop(const string& stop, const vector<string>& stops) const;

   /**
    * Inserts in a vector all the stops' code of a certain line.
    * @param path Path to line's file with all the stops.
    */
   vector<string> loadLineStops(const string& path) const;

   /**
    * Displays a vector of stops.
    * @param app Pointer to the main application.
    * @param stops Vector of Stop object.
    */
   void printStops(App* app, const vector<string>& stops) const;

};


#endif
