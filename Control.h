//the control class' purpose is to be the control structure. This launches throough the public launch function
//the launch function shows the user the menu and the allows the user to input what they want printed out
//In addition, the control dynamically allocates a ResManager and Hotel in its constructor, deleting them in their  destructor
//the launch function initializes everything by calling the private initHotel function

#ifndef CONTROL_H
#define CONTROL_H

#include "ResManager.h"
#include "View.h"
#include "Hotel.h"
#include "Recorder.h"

class Control
{
  public:
    Control();
    ~Control();
    void launch();

  private:
    void initHotel();
    ResManager *resMgr;
    Hotel* hotel;
    View view;

};

#endif
