//
// Created by Grant on 10/22/2015.
//

#ifndef CS3528PROGRAM3_FIRSTCLASS_H
#define CS3528PROGRAM3_FIRSTCLASS_H

#include "Seat.h"

namespace Airline {
    class FirstClass : public Seat {
    public:
        FirstClass(); // base constructor
        FirstClass(double price, double days); // FirstClass constructor sets price and days
        virtual int CalculatePrice() const; // Calculates price for FirstClass
    };
}

#endif //CS3528PROGRAM3_FIRSTCLASS_H
