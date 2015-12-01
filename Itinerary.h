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
        void setFlight(Flight & theFlight) const;//this function will be receiving a pointer
        void setSeat(Seat & theSeat) const;//this function will be receiving a pointer
        void setPassenger(Passenger & thePassenger) const;//this function will be receiving a pointer
    private:
         Passenger *passenger;
         Flight  *flight;
         Seat *seat;
    };
}

#endif //FINALPROJECT_ITINERARY_H
