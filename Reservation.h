#ifndef RESERVATION_H
#define RESERVATION_H

#include "Room.h"
#include "Date.h"
#include "Guest.h"

//the Reservation class' purpose is to reserve a room for a guest for a duration starting at a specific date, taking in a
//a guest pointer, a room pointer, date pointer, and int with default constructor below
//this class has getters for data members: guest (guest pointer), date (date pointer), room (room pointer), stay (int), and charge
//the class calculates the charge of a room depending on it's stay and the room night cost, stored as an int
//a reservation is less than another if the date comes before the other, using the date's lessThan function, taking in a reservation pointer

class Reservation{
  public:
    Reservation(Guest* = NULL, Room* = NULL, Date* = NULL, int = 0);
    ~Reservation();
    Guest *getGuest();
    Date *getDate();
    int getStay();
    Room *getRoom();
    float getCharge();
    bool lessThan(Reservation*);
    void print();

  private:
    void setCharge();
    Guest *guest;
    Date *date;
    int stay;
    Room *room;
    float charge;

};

#endif
