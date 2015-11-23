//
// Created by Grant on 11/17/2015.
//

#ifndef FINALPROJECT_PASSENGER_H
#define FINALPROJECT_PASSENGER_H

#include <string>
#include "Itinerary.h"

using namespace std;

namespace Airline {
    class Passenger{
    public:
        Passenger();
    private:
        string name;
        double balance;
        // Itinerary * itineraryList;
    };
}


#endif //FINALPROJECT_PASSENGER_H
