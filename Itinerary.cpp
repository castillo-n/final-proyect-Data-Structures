//
// Created by Grant on 11/17/2015.
//

#include "Itinerary.h"
#include "Passenger.h"
#include "Flight.h"
#include "Seat.h"

namespace Airline {

    Flight Itinerary::getFlight() {
        return flight;
    }

    Seat Itinerary::getSeat() {
        return seat;
    }
    Passenger Itinerary::getPassenger() {
        return passenger;
    }
    void Itinerary::setFlight(Flight & theFlight) const{
        flight = theFlight;
    }
    void Itinerary::setSeat(Seat & theSeat) const{
        seat = theSeat;
    }
    void Itinerary::setPassenger(Passenger & thePassenger) const{
        passenger = thePassenger;
    }

}