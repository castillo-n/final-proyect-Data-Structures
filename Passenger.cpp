//
// Created by Grant on 11/17/2015.
//

#include <string.h>
#include "Itinerary.h"

using namespace std;

namespace Airline {

    string Passenger::getName(){
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
    Itinerary Passenger::getItinerary(String flightName){
        for(int i=0; i < iterary.size(); i++){
            if(iterary[i].getFlight().getFlightName() == flightName){
                return iterary[i];
            }
        }
        return false;
    }
    void Passenger::setItinerary(Itinerary &theItine) const{
        numberOfItineraries++;
        itinerary[numberOfItineraries] = theItine;
    }
}