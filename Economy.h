//
// Created by Grant on 10/22/2015.
//

#ifndef CS3528PROGRAM3_ECONOMY_H
#define CS3528PROGRAM3_ECONOMY_H

#include "Seat.h"

namespace Airline {
    class Economy : public Seat {
    public:
        Economy(); // Base constructor
        Economy(double price, int days); // Economy constructor that sets price and days
        virtual double CalculatePrice() const; // Calculates the Economy price
    };
}

#endif //CS3528PROGRAM3_ECONOMY_H
