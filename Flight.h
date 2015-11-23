//
// Created by Grant on 11/17/2015.
//

#ifndef FINALPROJECT_FLIGHT_H
#define FINALPROJECT_FLIGHT_H

#include <string>
#include "Seat.h"
#include "Plane.h"

using namespace std;

namespace Airline {
    class Flight{
    public:
        Flight();
        Flight(string newDepCity, string newArrCity, string newDepDate, string newDepTime, string newArrDate, string newArrTime, char newIdentifier);
        void setDepCity(string newDepCity);
        string getDepCity();
        void setArrCity(string newArrCity);
        string getArrCity();
        void setDepDate(string newDepDate);
        string getDepDate();
        void setArrDate(string newArrDate);
        string getArrDate();
        void setDepTime(string newDepTime);
        string getDepTime();
        void setArrTime(string newArrTime);
        string getArrTime();
        void setIdentifier(char newIdentifier);
        char getIdentifier();
        void createSeatMap();
        void addPlane();
    private:
        string depCity;
        string arrCity;
        string depDate;
        string depTime;
        string arrDate;
        string arrTime;
        char identifier;
        Plane const * planeList[100];
        Seat const * const * seatMap[100][100];
        // Passenger const * passengerList;
    };
}


#endif //FINALPROJECT_FLIGHT_H
