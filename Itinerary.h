//
// Created by Grant on 11/17/2015.
//

#ifndef FINALPROJECT_ITINERARY_H
#define FINALPROJECT_ITINERARY_H

#include "Passenger.h"
#include "Flight.h"
#include "Seat.h"

namespace Airline {
    class Itinerary {
    public:
        Itinerary();
        Flight getFlight();
        Seat getSeat();
        Passenger getPassenger();
        void setFlight(Flight & theFlight) const;
        void setSeat(Seat & theSeat) const;
        void setPassenger(Passenger & thePassenger) const;
    private:
         Passenger *passenger;
         Flight  *flight;
         Seat *seat;
    };
}

#endif //FINALPROJECT_ITINERARY_H
