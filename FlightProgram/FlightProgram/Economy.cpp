//
// Created by Grant on 10/22/2015.
//

#include "Seat.h"
#include "Economy.h"

namespace Airline {
    Economy::Economy() : Seat() { // Base constructor of economy that calls the base seat constructor
    }

    Economy::Economy(double price, int days) : Seat(price, days) { // Economy constructor that calls the seat constructor that sets the price and days
        CalculatePrice();
    }

    int Economy::CalculatePrice() const{ // calculates the new price for the Economy object

        int days = getNumDays();
        double price = getPrice();

        if (days < 30 && days > 7)
            price = 1.1 * price;
        else if (days < 8)
            price = 1.2 * price;

        return price;
    }
}
