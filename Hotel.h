#ifndef HOTEL_H
#define HOTEL_H

class ResManager;
#include "Guest.h"
#include "RoomArray.h"
#include "ResManager.h"
#include "defs.h"

//this class acts as Hotel for a bunch of guests, forward declaring ResManager because it is bidirectional
//the data members are the hotel's name, the number of guests, guests stored as primitive array, rooms collection, and resManager pointer

//the hotel can add guests and rooms to the class by taking in either a guest or a room pointer (has option to print out both with print functions)

//the hotel can also find and return a guest using the findGuest member func. Guest is returned as a parameter and true returned if found

class Hotel{
  public:
    Hotel(string = "unknown", ResManager* = NULL);
    ~Hotel();
    RoomArray* getRooms();
    void addGuest(Guest*);
    void addRoom(Room*);
    void printGuests();
    void printRooms();
    bool findGuest(string, Guest **);

  private:
    string name;
    int guestNum;
    Guest* guests[MAX_ARR];
    RoomArray rooms;
    ResManager *manager;

};

#endif
