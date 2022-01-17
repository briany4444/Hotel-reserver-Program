#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "Recorder.h"

Recorder::Recorder(string n){
  name = n;
}

Recorder::~Recorder() { }

void Recorder::printRecords(){
  cout << endl << "Records for " << name << " Recorder:" << endl;
  for(int i = 0; i < records.size(); i++){
    cout << records[i] << endl;
  }
}

UpgradeRecorder::UpgradeRecorder(string n): Recorder(n) { }

UpgradeRecorder::~UpgradeRecorder() { }

void UpgradeRecorder::update(Reservation* res){
  if(res == nullptr){
    return;
  }
  if(!res->getGuest()->getPremium() && res->getCharge() > 1500){
    stringstream ss;
    ss << res->getCharge();
    string stay;
    ss >> stay;
    string s = name + " Recorder:  Guest " + res->getGuest()->getName() + ",  $" + stay;
    records.push_back(s);
  }
}

GuestRecorder::GuestRecorder(string n): Recorder(n) { }

GuestRecorder::~GuestRecorder() { }

void GuestRecorder::update(Reservation* res){
  if(res == nullptr){
    return;
  }
  ReqRoomType type = res->getRoom()->getRoomType();
  if(!res->getGuest()->getPremium() && (type == C_SUITE || type == C_PREM)){
    string s = name + " Recorder:  premium guest offer for " + res->getGuest()->getName();
    records.push_back(s);
  }
}

StayRecorder::StayRecorder(string n): Recorder(n) { }

StayRecorder::~StayRecorder() { }

void StayRecorder::update(Reservation* res){
  if(res == nullptr){
    return;
  }
  if(res->getStay() > 3){
    stringstream ss;
    stringstream days;
    ss << res->getGuest()->getName() << setfill(' ') << setw(16-res->getGuest()->getName().length());
    days <<res->getStay();
    string stay;
    string strng;
    ss >> strng;
    days >> stay;
    string s = name + " Recorder: " + "Guest" + ", " + strng + ", "+stay + " nights";
    records.push_back(s);
  }
}
