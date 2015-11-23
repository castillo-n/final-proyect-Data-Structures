//
// Created by Grant on 11/17/2015.
//

#include "Passenger.h"

#include <iostream> // std
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
        Void setName(string & fName, string & lName) const;
        Void Passenger::setFirstName(string & fName) const;
        Void Passenger::setLastName(string & lName) const;

    private:
        double balance;
        string firstName;
        string lastName;
        Itinerary *itinerary;
        // Itinerary * itineraryList;
    };
}