//
// Created by Grant on 11/17/2015.
//

#include "Itinerary.h"

namespace Airline {

    Flight Itinerary::getFlight() const {
        return *flight;
    }

    Seat Itinerary::getSeat() const {
        return *seat;
    }
    Passenger Itinerary::getPassenger() const {
        return *passenger;
    }
    void Itinerary::setFlight(Flight theFlight) { //this function will be receiving a pointer
        *flight = theFlight;
    }
    void Itinerary::setSeat(Seat theSeat) {//this function will be receiving a pointer
        *seat = theSeat;
    }
    void Itinerary::setPassenger(Passenger thePassenger) {//this function will be receiving a pointer
        *passenger = thePassenger;
    }


}