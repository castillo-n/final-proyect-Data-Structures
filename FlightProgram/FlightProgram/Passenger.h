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
        string getName();
        Itinerary getItinerary();

        void setItinerary(Itinerary &theItine) const;
<<<<<<< HEAD
        void setName(string & fName, string & lName) const;
        void setFirstName(string & fName) const;
        void setLastName(string & lName) const;
=======
        Void setName(string & fName, string & lName) const;
        Void setFirstName(string & fName) const;
        Void setLastName(string & lName) const;
>>>>>>> origin/master

    private:
        double balance;
        string firstName;
        string lastName;
        int numberOfItineraries;
        vector<Itinerary> itineraryList;
    };
}

#endif //FINALPROJECT_PASSENGER_H
