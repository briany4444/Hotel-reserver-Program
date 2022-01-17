#ifndef DATE_H
#define DATE_H

//the date class' purpose is to hold a date for a reservation with default values taking in a day month and year

//the member functions taken in references to other dates so that the times can be compared (lessthan and eqwuals)

//a date's date can also be added with the add member function, by specifiying how many days to increase by as an int

//lastly the date can be printed out and has private helper funcs that help find the last day in a month depending on if its a leap year

class Date{
  public:
    Date(int=0, int=0, int=2000);
    ~Date();
    void print();
    bool lessThan(Date&);
    bool equals(Date&);
    void add(int);

  private:
    int day;
    int month;
    int year;
    void setDate(int, int, int);
    int  lastDayInMonth();
    bool leapYear();
    string getMonthStr();
};

#endif
