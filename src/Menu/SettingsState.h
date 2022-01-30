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
   /**
    * Change the maximum walking distance.
    * @param app Pointer to the main application.
    */
   void changeDistance(App* app);

   /**
    * Change the time of the day.
    * @param app Pointer to the main application.
    */
   void changeTime(App* app);

   /**
    * Block lines.
    * @param app Pointer to the main application.
    */
   void blockLines(App* app);

   /**
    * Add a line to the list of blocked ones.
    * @param app Pointer to the main application.
    */
   void addLine(App* app);

   /**
    * Remove a line from the list of blocked ones.
    * @param app Pointer to the main application.
    */
   void removeLine(App* app);

   /**
    * Block stops.
    * @param app Pointer to the main application.
    */
   void blockStops(App* app);

   /**
    * Add a stop to the list of blocked ones.
    * @param app Pointer to the main application.
    */
    void addStop(App* app);

    /**
     * Remove a stop from the list of blocked ones.
     * @param app Pointer to the main application.
     */
    void removeStop(App* app);
};


#endif
