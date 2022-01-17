#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "ResManager.h"

ResManager::ResManager(Hotel* h){
  setHotel(h);
  numReserved = 0;
}

ResManager::~ResManager(){
  for(int i =0; i < numReserved; i++){
    delete reservations[i];
  }
  for(int i =0; i < recorders.size(); i++){
    delete recorders[i];
  }
}

void ResManager::setHotel(Hotel* h){
  if(h == nullptr){
    return;
  }
  hotel = h;
}

void ResManager::addReservation(string name, int yr, int mth, int day, int stay, ReqRoomType req){
  if(stay >= 31 || stay <= 0){
    return;
  }
  Date *newDate = new Date(day, mth, yr);
  if(newDate == nullptr){
    return;
  }
  RoomArray* rooms = hotel->getRooms();
  Room *room;
  bool found = false;
  for(int i = 0; i < rooms->getSize(); i++){
    if(rooms->get(i)->getRoomType() == req && checkRoom(rooms->get(i), newDate, stay)){
      room = rooms->get(i);
      found = true;
      break;
    }
  }
  if(found == false){
    cout << "ERROR:   Registration request " << name << ", ";
    newDate->print();
    cout << ": No Room of Matching Type Exists" << endl;
    delete newDate;
    return;
  }
  Guest *guest;
  if(!hotel->findGuest(name, &guest)){
    cout << "ERROR:   " << name << " does not exist" << endl;
    delete newDate;
    return;
  }
  Reservation *newRes = new Reservation(guest, room, newDate, stay);
  if(newRes == nullptr){
    delete newDate;
    return;
  }
  shift(newRes);
  numReserved++;
  int pts;
  room->computePoints(pts);
  guest->addPts(pts * stay);
  notify(newRes);
}

bool ResManager::checkRoom(Room *room, Date* date, int stay){
  if(room == nullptr || date == nullptr){
    return false;
  }
  for(int i =0; i < numReserved; i++){
    Date startDate = *date;
    Date endDate = *date;
    endDate.add(stay);
    Date resStart = *reservations[i]->getDate();
    Date resEnd = *reservations[i]->getDate();
    resEnd.add(reservations[i]->getStay());
    if(reservations[i]->getRoom() == room){
      if(resStart.equals(startDate) || resEnd.equals(endDate) || resStart.equals(endDate) || resEnd.equals(startDate)){
        return false;
      }
      else if((startDate.lessThan(resStart) && resStart.lessThan(endDate)) || (startDate.lessThan(resEnd) && resEnd.lessThan(endDate))){
        return false;
      }
      else if(resStart.lessThan(*date) && endDate.lessThan(resEnd)){
        return false;
      }
    }
  }
  return true;
}

void ResManager::shift(Reservation* res){
  if(res == nullptr){
    return;
  }
  for(int i =0; i < numReserved; i++){
    if(res->lessThan(reservations[i])){
      for(int j = numReserved-1; j >= i; j--){
        reservations[j+1] = reservations[j];
      }
      reservations[i] = res;
      return;
    }
  }
  reservations[numReserved] = res;
}

void ResManager::subscribe(Recorder* rec){
  if(rec == nullptr){
    return;
  }
  recorders.push_back(rec);
}

void ResManager::printRecords(){
  cout << endl;
  cout << "EVENT RECORDS:" << endl;
  for(int i =0; i < recorders.size(); i++){
    recorders[i]->printRecords();
  }
}

void ResManager::print(){
  cout << endl;
  cout << "RESERVATIONS: " << endl;
  for(int i =0; i < numReserved; i++){
    reservations[i]->print();
  }
}

void ResManager::notify(Reservation* res){
  if(res == nullptr){
    return;
  }
  for(int i =0; i < recorders.size(); i++){
    recorders[i]->update(res);
  }
}
