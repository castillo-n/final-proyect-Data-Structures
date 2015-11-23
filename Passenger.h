//
// Created by Grant on 11/17/2015.
//

#ifndef FINALPROJECT_PASSENGER_H
#define FINALPROJECT_PASSENGER_H

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

//    Passenger
//    -	Name
//    -	Balance
//    -	Itinerary List

}


#endif //FINALPROJECT_PASSENGER_H
