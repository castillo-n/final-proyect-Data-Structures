//
// Created by Grant on 11/17/2015.
//

#ifndef FINALPROJECT_PASSENGER_H
#define FINALPROJECT_PASSENGER_H

#include "Passenger.h"

#include <iostream> // std
#include <vector>
#include "Itinerary.h"
#include "Passenger.h"

using namespace std;
using std::vector;

namespace Airline {
    class Passenger{
        
    public:
        Passenger();
        string getName() const;
        Itinerary getItinerary(char flightIdentifier) const;

        void setItinerary(Itinerary &theItine) const;
        void setName(string & fName, string & lName) const;
        void setFirstName(string & fName) const;
        void setLastName(string & lName) const;

    private:
        double balance;
        string firstName;
        string lastName;
        int numberOfItineraries;
        vector<Itinerary> itineraryList;
    };
}

#endif //FINALPROJECT_PASSENGER_H
