//
// Created by Grant on 10/22/2015.
//

#include "FirstClass.h"
#include "Seat.h"

namespace Airline {
    FirstClass::FirstClass() : Seat() { // Base constructor that calls base seat constructor
    }

    FirstClass::FirstClass(double price, double days) : Seat(price, days) { // FirstClass constructor that calls seat constructor that sets price and days
        
    }

    int FirstClass::CalculatePrice() const{ // Calculates price for First Class
        int days = getNumDays();
        double price = getPrice();

        if (days < 30 && days > 7)
            price = 4.0 * price;
        else if (days < 8)
            price = 5.0 * price;
        else
            price = 3.0 * price;

        return price;
    }
}
