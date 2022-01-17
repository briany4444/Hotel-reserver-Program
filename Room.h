#ifndef ROOM_H
#define ROOM_H

#include "defs.h"

//this class's purpose is to be a room where a guest can reside, with the default room as a regular room
//this class has a roomType (premium, regular, or suite), a rate as a float per night, and room number as an int
//there are getter functions for all of these data memebers

//the points of a guest can be computed depending on the type of room using computePoints, taking in an int reference

//finally, the room's info is printed using the print function

class Room{
  public:
    Room(ReqRoomType = C_REG, int = 0, float = 0.0f);
    ~Room();
    float getRate();
    int getRoomNumber();
    ReqRoomType getRoomType();
    void computePoints(int&);
    void print();

  private:
    ReqRoomType roomType;
    int roomNumber;
    float rate;
};

#endif
