#ifndef CHOOSESTOP_H
#define CHOOSESTOP_H

#include "State.h"
#include "ChooseStartState.h"
#include "PathState.h"

class ChooseStopState : public State {
   void step(App* app) override;
   void display() override;
private:
    /**
     * Displays all the available lines.
     * @param app Pointer to the main Application.
     */
    void displayLines(App *app);

    /**
     * Displays all the stops of a certain line.
     * @param app Pointer to the main Application.
     * @param path Path to line's file with the stops to be displayed.
     */
    void displayLinesStops(App *app, string path);

    /**
     * Asks which direction the user wants to go.
     * @param app Pointer to the main application.
     * @return Wanted direction (1 or 0).
     */
    int askDirection(App *app);

    /**
     * Asks which stop the user wants to select.
     * @param app Pointer to the main application.
     * @return String with the code of the stop the user selected.
     */
    string askStop(App *app);

    /**
     * Inserts in a vector all the stops of a certain line.
     * @param path Path to line's file with all the stops.
     */
    void loadLinesStops(string path);

   string Aux(App *app, bool source);

    vector<string> linesStops;


    string src, dest;
};


#endif
