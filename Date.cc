#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

Date::Date(int d, int m, int y){
  setDate(d, m, y);
}

Date::~Date() { }

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

bool Date::lessThan(Date& date){
  if(year < date.year){
    return true;
  }
  else if(year == date.year && month < date.month){
    return true;
  }
  else if(year == date.year && month == date.month && day < date.day){
    return true;
  }
  else{
    return false;
  }
}

void Date::print(){
  cout << setfill('0') << setw(4) << year << "-";
  cout << setfill('0') << setw(2) << month << "-";
  cout << setfill('0') << setw(2) << day;
}

void Date::add(int duration){
  if(duration < 0){
    return;
  }
  day += duration;
  if(day > lastDayInMonth()){
    day -=lastDayInMonth();
    month++;
  }
  if(month > 12){
    month -= 12;
    year++;
  }
}

bool Date::equals(Date& date){
  if(year == date.year && month == date.month && day == date.day){
    return true;
  }
  return false;
}

int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr()
{
  string monthStrings[] = {
    "January", "Februrary", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}
