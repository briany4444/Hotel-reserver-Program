#ifndef RESMANAGER_H
#define RESMANAGER_H

#include "Hotel.h"
#include "Recorder.h"
#include "Reservation.h"
#include "defs.h"
#include <vector>

//the REsManager class' managers all the hotel's reservations and adds a reservation to the primitive reservations array of pointers with the addReservation
//the addReservation takes in a string, 4 ints, then a roomtype, inrementing number reserved
//the print and printRecords functions display the reservation info and records info to the user respectively
//this class takes in a hotel in the constructor, stored as a hotel poiner
//all the recorders are stored as pointers in a vector, and they can be upgrade, guest, or stay recorders
//the setHotel must be used because of the bi-directional relationship between hotel and resManager (why we need forward declaration)

//all the helper funcions (shift and cehckROom) help with the addReservation. The shift helpers add a reservation to a specific spot in the array,
//while the checkRoom checks if a room is a avaiable, looking a date overlaps for a room

class Hotel;

class ResManager{
  public:
    ResManager(Hotel* = NULL);
    ~ResManager();
    void addReservation(string, int,int, int, int , ReqRoomType);
    void subscribe(Recorder*);
    void print();
    void printRecords();
    void setHotel(Hotel*);

  private:
    vector<Recorder*> recorders;
    Hotel* hotel;
    int numReserved;
    Reservation* reservations[MAX_ARR];
    void notify(Reservation*);
    void shift(Reservation*);
    bool checkRoom(Room*, Date *, int);
};

#endif
