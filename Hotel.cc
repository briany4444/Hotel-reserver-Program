#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Hotel.h"

Hotel::Hotel(string n, ResManager* m){
  guestNum = 0;
  name = n;
  manager = m;
}

Hotel::~Hotel(){
  for(int i = 0; i < guestNum; i++){
    delete guests[i];
  }
}

RoomArray* Hotel::getRooms(){
  return &rooms;
}

void Hotel::printGuests(){
  cout << endl;
  cout << "GUESTS:" << endl;
  for(int i =0; i < guestNum; i++){
    guests[i]->print();
  }
}

void Hotel::printRooms(){
  cout << endl;
  cout << "ROOMS:" << endl;
  rooms.print();
}

bool Hotel::findGuest(string n, Guest **guest){
  for(int i = 0; i < guestNum; i++){
    if(n == guests[i]->getName()){
      *guest = guests[i];
      return true;
    }
  }
  return false;
}

void Hotel::addGuest(Guest* guest){
  if(guest == nullptr || guestNum == MAX_ARR){
    return;
  }
  guests[guestNum] = guest;
  guestNum++;
}

void Hotel::addRoom(Room* room){
  if(room == nullptr){
    return;
  }
  rooms.add(room);
}
