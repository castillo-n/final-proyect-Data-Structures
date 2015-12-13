//
// Created by Grant on 11/17/2015.
//

#ifndef FINALPROJECT_PASSENGER_H
#define FINALPROJECT_PASSENGER_H

#include "Passenger.h"
#include <iostream>
#include <vector>
#include "Itinerary.h"
#include "Passenger.h"

using namespace std;
using std::vector;

namespace Airline {
    class Itinerary;
    class Passenger{

    public:
        Passenger();
        string getName() const;
        Itinerary* getItinerary(string flightIdentifier )const;
        string dumpItinerary();
        void setItinerary(Itinerary * theItine);
        void setName(string & fName, string & lName);
        void setName(string & theFullName);
        void setFirstName(string & fName) ;
        void setLastName(string & lName) ;

    private:
        double balance;
        string firstName;
        string lastName;
        string fullName;
        int numberOfItineraries;
        vector<Itinerary * > itineraryList;
    };
}

#endif //FINALPROJECT_PASSENGER_H
