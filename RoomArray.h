#ifndef ROOMARRAY_H
#define ROOMARRAY_H

#include "defs.h"
#include "Room.h"

//the class' purpose stores the rooms as a collection class
//there is a getter for the size of the array and a getter at an index, returning a room pointer
//the print functiobn prints out all the room's information
//the add func takes in a room pointer and adds the room to the collection

class RoomArray{
  public:
    RoomArray();
    ~RoomArray();
    void  add(Room*);
    int   getSize();
    Room* get(int);
    void  print();

  private:
    Room* elements[MAX_ARR];
    int   size;
};

#endif
