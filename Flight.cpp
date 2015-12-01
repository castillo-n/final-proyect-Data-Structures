//
// Created by Grant on 11/17/2015.
//

#include "Flight.h"
#include "Plane.h"
#include "Passenger.h"
#include "Seat.h"
#include "Economy.h"
#include "EconomyPlus.h"
#include "FirstClass.h"
#include <string>

namespace Airline{

    Flight::Flight(){
        depCity = "";
        arrCity = "";
        depDate = "";
        arrDate = "";
        depTime = "";
        arrTime = "";
        identifier = '0';
        distance = 0;
    }

    Flight::Flight(string newDepCity, string newArrCity, string newDepDate, string newDepTime, string newArrDate, string newArrTime, char newIdentifier, int newDisttance){
        depCity = newDepCity;
        arrCity = newArrCity;
        depDate = newDepDate;
        arrDate = newArrDate;
        depTime = newDepTime;
        arrTime = newArrTime;
        identifier = newIdentifier;
        distance = newDistance;
    }

    void Flight::setDepCity(string newDepCity){
        depCity = newDepCity;
    }

    string Flight::getDepCity(){
        return depCity;
    }

    void Flight::setArrCity(string newArrCity){
        arrCity = newArrCity;
    }

    string Flight::getArrCity(){
        return arrCity;
    }

    void Flight::setDepDate(string newDepDate){
        depDate = newDepDate;
    }

    string Flight::getDepDate(){
        return depDate;
    }

    void Flight::setArrDate(string newArrDate){
        arrDate = newArrDate;
    }

    string Flight::getArrDate(){
        return arrDate;
    }

    void Flight::setDepTime(string newDepTime){
        depTime = newDepTime;
    }

    string Flight::getDepTime(){
        return depTime;
    }

    void Flight::setArrTime(string newArrTime){
        arrTime = newArrTime;
    }

    string Flight::getArrTime(){
        return arrTime;
    }

    void Flight::setIdentifier(char newIdentifier){
        identifier = newIdentifier;
    }

    char Flight::getIdentifier(){
        return identifier;
    }

    void Flight::addPlane(Plane plane, int i){
        planeList[i] = plane;
    }

    Plane Flight::getPlane(){
        return designatedPlane;
    }

    void Flight::createSeatMap( double price) {
        for(int i = 0; i < designatedPlane->getRows(); i++ ){
            for(int j = 0; j < designatedPlane->getColumns(); j++){
                if( i < 3 )
                    seatMap[i][j] = new FirstClass(price);
                    seatMap[i][j]->setSeatPos(i + 'A' + i );
                else if(i >= 3 && i < 9 )
                    seatMap[i][j] = new EconomyPlus(price, 0 , distance);
                else
                    seatMap[i][j] = new Economy(price);
            }
        }
    }

    void Flight::addPassenger(Passenger * p){
        passengerList->emplace_back(p);
    }

    Passenger Flight::getPassenger(int i){
        return passengerList[i];
    }

    // don't know what this does
    int Flight::dateDifferenceToday(const int &year, const int &month, const int &day, const int &hour, const int &minute) {
        time_t timer;
        int second = 0;
        struct tm userTime = {0};
        double seconds;
        userTime.tm_year = year - 1900;//0 is 1900
        userTime.tm_mon = month - 1; //jan is 0
        userTime.tm_mday = day;
        userTime.tm_hour = hour;
        userTime.tm_min = minute;
        userTime.tm_sec = second;
        time_t now = time(0);
        seconds = difftime(now, mktime(&userTime));
        double minutes = seconds / 60;
        double hours = minutes / 60;
        double days = minutes / 24;

        return static_cast<int>(floor(days));
    }
}

