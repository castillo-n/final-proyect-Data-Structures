//
// Created by Grant on 11/17/2015.
//

#include <string.h>
#include "Itinerary.h"

using namespace std;

namespace Airline {


    Passenger::Passenger(){
        balance=0;
        firstName = "";
        lastName = "";
        numberOfItineraries=0;
    }
    string Passenger::getName() const{
        return firstName + " " + lastName;
    }

    void Passenger::setName(string & fName, string & lName) {
        firstName = fName;
        lastName = lName;
    }

    void Passenger::setFirstName(string & fName) {
        firstName = fName;
    }

    void Passenger::setLastName(string & lName) {
        lastName = lName;
    }

    Itinerary Passenger::getItinerary(string flightIdentifier) const{
        for( int it = 0; it != itineraryList.size(); ++it) {
            if (flightIdentifier == itineraryList[it]->getFlight().getIdentifier()) {
                return *itineraryList[it];
            }
        }
        return Itinerary();
    }

    void Passenger::setItinerary(Itinerary * theItine) {
        itineraryList.push_back(theItine);
    }
}