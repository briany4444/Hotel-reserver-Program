#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Reservation.h"

Reservation::Reservation(Guest *g, Room* r, Date* d, int days){
  stay = days;
  guest = g;
  date = d;
  room = r;
  setCharge();
}

Reservation::~Reservation() {
  delete date;
}

void Reservation::setCharge(){
  charge = room->getRate() * stay;
}

int Reservation::getStay(){
  return stay;
}

Guest* Reservation::getGuest(){
  return guest;
}

Room* Reservation::getRoom(){
  return room;
}

Date* Reservation::getDate(){
  return date;
}

float Reservation::getCharge(){
  return charge;
}

bool Reservation::lessThan(Reservation* res){
  if(res == nullptr){
    return false;
  }
  if(date->lessThan(*res->getDate())){
    return true;
  }
  return false;
}

void Reservation::print(){
  cout << "- -Guest: " << getGuest()->getName() << setfill(' ') << setw(10-getGuest()->getName().length()) << "; ";
  cout << "Room: " << getRoom()->getRoomNumber() << "; ";
  cout << "  arrival: ";
  getDate()->print();
  cout << "   stay: " << setfill(' ') << setw(2) << getStay();
  cout << "   total: $" << fixed << setprecision(2) << getCharge() << endl;
}
