#ifndef RECORDER_H
#define RECORDER_H

#include "Reservation.h"
#include <vector>

//the recorder class' purpose is to be the base class to the rest of the recorders, which happens to be abstract
//this "abstractness" is defined by the pure virtual member function "update", which is not implemented by the base class
//these derived recorders are the upgradeRecorder, stayRecorder, and guestRecorder.
//the name and records classes are protected so the derived classes can use them

//each derived class's update does something a little differently, which is why polymorphism is nessasry (all of them virtual)

class Recorder{
  public:
    Recorder(string = "unknown");
    virtual ~Recorder();
    void printRecords();
    virtual void update(Reservation*) = 0;

  protected:
    string name;
    vector<string> records;
};

class UpgradeRecorder : public Recorder{
  public:
    UpgradeRecorder(string = "unknown");
    ~UpgradeRecorder();
    virtual void update(Reservation*);
};

class StayRecorder: public Recorder{
  public:
    StayRecorder(string = "unknown");
    ~StayRecorder();
    virtual void update(Reservation*);
};

class GuestRecorder : public Recorder{
  public:
    GuestRecorder(string = "unknown");
    ~GuestRecorder();
    virtual void update(Reservation*);
};

#endif
