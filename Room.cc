#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Room.h"

Room::Room(ReqRoomType req, int num, float r){
  roomType = req;
  roomNumber = num;
  rate = r;
}

Room::~Room() { }

int Room::getRoomNumber(){
  return roomNumber;
}

float Room::getRate(){
  return rate;
}

ReqRoomType Room::getRoomType(){
  return roomType;
}

void Room::print(){
  cout << "-- " << getRoomNumber() << " ";
  if(getRoomType() == C_SUITE){
    cout << " Suite  ";
  }
  else if(getRoomType() == C_PREM){
    cout << " Premium";
  }
  else{
    cout << " Regular";
  }
  cout << " room:  ";
  cout << "$" << setfill(' ') << setw(7) << fixed << setprecision(2) << getRate() << " per night" << endl;
}

void Room::computePoints(int & pts){
  if(getRoomType() == C_SUITE){
    pts = 0.20 * getRate();
  }
  else if(getRoomType() == C_PREM){
    pts = 0.15 * getRate();
  }
  else{
    pts = 0.10 * getRate();
  }
}
