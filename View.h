#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

//this class displays to the user a manu that they can choose from (by taking in an int reference)
//this essentially acts as the interface class and reads in integers and strings

class View
{
  public:
    void showMenu(int&);
    void printStr(string);
    void readInt(int&);
    void readStr(string&);
};

#endif
