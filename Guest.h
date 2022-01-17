#ifndef GUEST_H
#define GUEST_H

//the guest class serves to represent a guest at the hotel, with default constructor (initalizes everything)
//they have a name as string, # of loyalty pts, and whether they are premium
//every one of these data members have getter functions
//lastly there is a print function to print out all the data members

class Guest{
  public:
    Guest(string = "unknown", bool = false);
    ~Guest();
    string getName();
    bool getPremium();
    void addPts(int);
    void print();

  private:
    string name;
    bool premium;
    int loyaltyPts;

};

#endif
