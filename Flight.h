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

//seat setup isn't done, need to get pricing and days

namespace Airline {
    class Flight{
    public:
        Flight();
        Flight(string newDepCity, string newArrCity, string newDepDate, string newDepTime, string newArrDate, string newArrTime, string newIdentifier, int distance);
        void setDepCity(string newDepCity);
        string getDepCity() const;
        void setArrCity(string newArrCity);
        string getArrCity() const;
//        void setDepDate(string newDepDate);
        string getDepDate() const;
        void setArrDate(string newArrDate);
        string getArrDate() const;
        void setDepDateTime(int & month, int & day, int & year, int & hour, int & min, string amPm);
        string getDepTime() const;
        void setArrTime(string newArrTime);
        string getArrTime() const;
        void setIdentifier(string newIdentifier);
        string getIdentifier() const;
        void setDistance(int newDistance);
        int getDistance() const;
        void addPlane(Plane plane);
        Plane getPlane() const;
        void createSeatMap();
        void displaySeatMap();
        void clearSeatMap();
        void occupySeat(int row, int col);
        Seat getSeat(int row, int col) const;
        void seatDumper( istream & file );
        void addPassenger(Passenger p);
        Passenger getAPassenger(string name) const;
        Passenger getPassenger(int i) const;
        int numOfPassengers() const;
//        int dateDifferenceToday(const int &year, const int &month, const int &day, const int &hour, const int &minute);
        int amountOfDaysTo() const;
    private:
        string depCity;
        string arrCity;
        int depDateYear;
        int depDateMonth;
        int depDateDay;
        int depDateHour;
        int depDateMin;
        string depDateAmPm;
        string depDate;
        string depTime;
        string arrDate;
        string arrTime;
        int distance;
        string identifier;
        Plane * designatedPlane;
        vector< vector<Seat *> > seatMap;
        vector<Passenger> passengerList;
    };
}


#endif //FINALPROJECT_FLIGHT_H
