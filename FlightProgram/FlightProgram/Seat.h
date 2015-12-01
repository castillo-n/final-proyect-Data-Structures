//
// Created by Grant on 10/22/2015.
//

#ifndef CS3528PROGRAM3_SEAT_H
#define CS3528PROGRAM3_SEAT_H

namespace Airline {
    class Seat { // Abstract object to implement to other objects
    public:
        Seat(); // base constructor setting all class variables to 0
        Seat(double newPrice); // Constructor that initializes the price value
        Seat(double newPrice, int days); // Constructor that initializes price and days
        Seat(double newPrice, int days, int newMiles); // Constructor that initializes price, days, and miles
        void setSeatAv(char newSeatAv);
        char getSeatAv();
        char getSeatPos() const;
        double getPrice() const; // gets the price
        void setPrice(double newPrice); // sets a new price
        int getNumDays() const; // gets the number of days before departure
        void setNumDays(int days); // set the number of days before departure
        int getMiles() const; // get the number of miles of travel
        void setMiles(int newMiles); // set the number of miles of travel
	    virtual int CalculatePrice() const; // returns the calculated price of the seat
    private:
        char seatAv;
        double price; // contains the price of the seat
        int NumDays; // contains the number of days before departure
        int miles; // contains the distance of travel
    };
}

#endif //CS3528PROGRAM3_SEAT_H
