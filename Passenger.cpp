//
// Created by Grant on 11/17/2015.
//

#include "Passenger.h"

#include <string>
#include "Itinerary.h"
#include "Passenger.h"

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