#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Guest.h"

Guest::Guest(string n, bool prem){
  name = n;
  premium = prem;
  loyaltyPts = 0;
}

Guest::~Guest() { }

string Guest::getName(){
  return name;
}

bool Guest::getPremium(){
  return premium;
}

void Guest::addPts(int pts){
  loyaltyPts += pts;
}

void Guest::print(){
  cout << "-- " << getName();
  cout<< setfill(' ') << setw(10-getName().length()) << " ";
  if(getPremium()){
    cout << "Premium";
  }
  else{
    cout << "Regular";
  }
  cout << " guest: ";
  cout << setfill(' ') << setw(5) << loyaltyPts << " pts" << endl;
}
