#ifndef APP_H
#define APP_H

#include "Navigator.h"

class App
{
public:
   App();

   /**The application main loop.**/
   void run();

private:
    Navigator navigator;
};


#endif
