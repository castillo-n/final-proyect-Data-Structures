//
// Created by Grant on 11/17/2015.
//

#ifndef FINALPROJECT_FLIGHT_H
#define FINALPROJECT_FLIGHT_H


#include "Plane.h"
#include "Passenger.h"
#include "Seat.h"
#include "Economy.h"
#include "EconomyPlus.h"
#include "FirstClass.h"
#include <string>

using namespace std;

namespace Airline {
    class Flight{
    public:
        Flight();
        Flight(string newDepCity, string newArrCity, string newDepDate, string newDepTime, string newArrDate, string newArrTime, char newIdentifier, int distance);
        void setDepCity(string newDepCity);
        string getDepCity() const;
        void setArrCity(string newArrCity);
        string getArrCity() const;
        void setDepDate(string newDepDate);
        string getDepDate() const;
        void setArrDate(string newArrDate);
        string getArrDate() const;
        void setDepTime(string newDepTime);
        string getDepTime() const;
        void setArrTime(string newArrTime);
        string getArrTime() const;
        void setIdentifier(char newIdentifier);
        char getIdentifier() const;
        void setDistance(int newDistance);
        int getDistance() const;
        void addPlane(Plane plane, int i);
        Plane getPlane() const;
        void createSeatMap();
        Seat getSeat() const;
        void addPassenger(Passenger p);
        Passenger getPassenger(string name) const;
        int dateDifferenceToday(const int &year, const int &month, const int &day, const int &hour, const int &minute);


    private:
        string depCity;
        string arrCity;
        string depDate;
        string depTime;
        string arrDate;
        string arrTime;
        int distance;
        char identifier;
        Plane * designatedPlane;
        vector< vector<Seat> > * seatMap;
        vector<Passenger> * passengerList;
    };
}


#endif //FINALPROJECT_FLIGHT_H
