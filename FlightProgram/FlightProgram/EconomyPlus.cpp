//
// Created by Grant on 10/22/2015.
//

#include "EconomyPlus.h"
#include "Seat.h"

namespace Airline {
    EconomyPlus::EconomyPlus() : Seat() { // EconomyPlus base constructor that calls seat base constructor
    }

    EconomyPlus::EconomyPlus(double price, int days, int miles) : Seat(price, days, miles) { // EconomyPlus constructor that calls the seat constructor that sets price, days, and miles
        
    }

    int EconomyPlus::CalculatePrice() const { // Calculates price of EconomyPlus seat
        int days = getNumDays();
        double price = getPrice();
        int miles = getMiles();

        if (days < 30 && days > 7)
            price = 1.1 * price;
        else if (days < 8)
            price = 1.2 * price;

        if (miles < 800)
            price = price + 75;
        else
            price = price + 125;

        return price;
    }
}
