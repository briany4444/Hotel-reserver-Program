#include <iostream>
using namespace std;

#include "Control.h"

//purpose: this program's purpose is to create a hotel so that users can reserve rooms as a guest in the hotel
//  and considers if a guest is a premium or not. It records all the user's who reserve a room and
//none of the rooms' reservation dates can overlap. This program also considers what type of room a
//guest desires and how long they would like to stay

//the main method only creates a control object and launches the program

int main(){
  Control control;
  control.launch();
  return 0;
}
