//
// Created by Grant on 11/17/2015.
//

#include <string.h>
#include "Itinerary.h"

using namespace std;

namespace Airline {

    string Passenger::getName() const{
        return firstName + " " + lastName;
    }

    Void Passenger::setName(string & fName, string & lName) const{
        firstName = fName;
        lastName = lName;
    }

    Void Passenger::setFirstName(string & fName) const{
        firstName = fName;
    }

    Void Passenger::setLastName(string & lName) const{
        lastName = lName;
    }

    Itinerary Passenger::getItinerary(string flightIdentifier){
        char id;
        for(vector<Passenger>::iterator it = itineraryList.begin(); it != itineraryList.end(); ++it) {
            if (id == it->getItinerary().getFlight().getIdentifier()) {
                return *it->getItinerary().getFlight();
            }
        }
        return 0;
    }

    void Passenger::setItinerary(Itinerary &theItine) const{
        numberOfItineraries++;
        itinerary[numberOfItineraries] = theItine;
    }
}