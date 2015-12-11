//
// Created by Grant on 10/22/2015.
//

#ifndef CS3528PROGRAM3_ECONOMYPLUS_H
#define CS3528PROGRAM3_ECONOMYPLUS_H

#include "Seat.h"

namespace Airline {
    class EconomyPlus : public Seat {
    public:
        EconomyPlus(); // base constructor
        EconomyPlus(double price, int days, int miles); // constructor that sets price, days, and miles
       virtual double CalculatePrice() const; // Calculates price for EconomyPlus seat
    };
}

#endif //CS3528PROGRAM3_ECONOMYPLUS_H
