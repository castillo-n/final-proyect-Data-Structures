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
#include <math.h>

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

    Flight::Flight(string newDepCity, string newArrCity, string newDepDate, string newDepTime, string newArrDate, string newArrTime, string newIdentifier, int newDistance){
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

    string Flight::getDepCity() const{
        return depCity;
    }

    void Flight::setArrCity(string newArrCity){
        arrCity = newArrCity;
    }

    string Flight::getArrCity() const{
        return arrCity;
    }

//    void Flight::setDepDate(string newDepDate){
//        depDate = newDepDate;
//    }
//
    string Flight::getDepDate() const{
        return depDate;
    }

    void Flight::setArrDate(string newArrDate){
        arrDate = newArrDate;
    }

    string Flight::getArrDate() const{
        return arrDate;
    }

    void Flight::setDepDateTime(int & month, int & day, int & year, int & hour, int & min, string amPm) {
        bool a = false;
        if (year > 2014 && month < 2025) { // at this time they should pay us to make an upgrade :)
            if (month > 0 && month < 13) {
                depDateMonth = month;
                if (day > 0 && day <
                               32) { // we could be more specific and check fo year and month to check for 2/29 instead of 2/28 or for the mothns with 30 days instead of 31
                    depDateDay = day;
                    if (hour > -1 && hour < 13) {
                        depDateHour = min;
                        if (min > -1 && min < 60) {
                            depDateMin = min;
                            if (amPm == "AM" || amPm == "Am" || amPm == "am" || amPm == "PM" || amPm == "Pm" ||
                                amPm == "pm") {
                                depDateAmPm = amPm;
                                depTime = to_string(month) + "/" + to_string(month) + "/" + to_string(month) + " " +
                                          to_string(hour) + ":" + to_string(min) + " " + amPm;
                            } else {
//                                cout << "wrong time stamp" << endl;
                                a = true;
                            }
                        } else {
//                            cout << "wrong minutes" << endl;
                            a = true;
                        }
                    } else {
//                        cout << "wrong minutes" << endl;
                        a = true;
                    }
                } else {
//                    cout << "wrong day" << endl;
                    a = true;
                }
            } else {
//                cout << "wrong month" << endl;
                a = true;
            }
        } else {
//            cout << "wrong year" << endl;
            a = true;
        }
        if (a) {
            depTime ="";
        }
    }

    string Flight::getDepTime() const{
        return depTime;
    }

    void Flight::setArrTime(string newArrTime){
        arrTime = newArrTime;
    }

    string Flight::getArrTime() const{
        return arrTime;
    }

    void Flight::setIdentifier(string newIdentifier){
        identifier = newIdentifier;
    }

    string Flight::getIdentifier() const{
        return identifier;
    }

    void Flight::setDistance(int newDistance) {
        distance = newDistance;
    }

    int Flight::getDistance() const {
        return distance;
    }

    void Flight::addPlane(Plane plane){
        *designatedPlane = plane;
    }

    Plane Flight::getPlane() const{
        return *designatedPlane;
    }

    void Flight::createSeatMap() {

        int EconRows = designatedPlane->getEconRows();
        int EconPlusRows = designatedPlane->getEconPlusRows();
        int FirstClassRows = designatedPlane->getFirstClassRows();
        int col = designatedPlane->getColumns();
        double price = designatedPlane->getPrice();
        int rows = designatedPlane->getRows();

        for(int i = 0; i < FirstClassRows; i++){
            vector<Seat*> FirstClassRow;
            for(int j = 0; j < col; j++ ){
                FirstClassRow.push_back(new FirstClass());
            }
            seatMap.push_back(FirstClassRow);
        }

        for(int i = 0; i < EconPlusRows; i++){
            vector<Seat*> EconPlusRow;
            for(int j = 0; j < col; j++ ){
                EconPlusRow.push_back(new EconomyPlus());
            }
            seatMap.push_back(EconPlusRow);
        }

        for(int i = 0; i < EconRows; i++){
            vector<Seat*> EconRow;
            for(int j = 0; j < col; j++ ){
                EconRow.push_back(new Economy());
            }
            seatMap.push_back(EconRow);
        }

        for(int i = 0; i < rows; i++){
            for (int j = 0; j < col; j++){
                seatMap[i][j]->setSeatAv('O');
                seatMap[i][j]->setPrice(price);
                seatMap[i][j]->setMiles(distance);
            }
        }
    }

    void Flight::displaySeatMap() {
        int rows = designatedPlane->getRows();
        int cols = designatedPlane->getColumns();

        cout << "O - vacant seat" << endl;
        cout << "X - occupied seat" << endl;
        cout << "First Class Seats 0-" << designatedPlane->getFirstClassRows() - 1 << endl;
        cout << "Economy Plus Seats " << designatedPlane->getFirstClassRows() <<"-" << designatedPlane->getFirstClassRows() + designatedPlane->getEconPlusRows() - 1 << endl;
        cout << "Economy Seats " << designatedPlane->getFirstClassRows() + designatedPlane->getEconPlusRows() <<"-" << designatedPlane->getColumns() - 1 << endl;

        for(int i = 0; i < rows; i++){
            cout << i << ": ";
            for (int j = 0; j < cols; j++){
                cout << seatMap[i][j]->getSeatAv();
            }
        }
    }

    void Flight::clearSeatMap() {
        int rows = designatedPlane->getRows();
        int cols = designatedPlane->getColumns();

        for(int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                delete(seatMap[i][j]);
            }
        }
        seatMap.clear();
    }

    void Flight::occupySeat(int row, int col) {
        seatMap[row][col]->setSeatAv('X');
    }

    Seat Flight::getSeat(int row, int col) const {
        return *seatMap[row][col];
    }

    void Flight::addPassenger(Passenger p){
        passengerList.push_back(p);
    }

    Passenger Flight::getAPassenger(string name) const{
        for(int it = 0; it != passengerList.size(); ++it) {
            if (name == passengerList[it].getName()) {
                return passengerList[it];
            }
        }
        return Passenger();
    }

    Passenger Flight::getPassenger(int i) const {
        return passengerList[i];
    }

    int Flight::numOfPassengers() const {
        return passengerList.size();
    }

    // don't know what this does 
    // this returns the difference between the date of today and the freaking flight date :) -Nelson
    int Flight::amountOfDaysTo() const{
        time_t timer;
        int second = 0;
        struct tm userTime = {0};
        double seconds;


        userTime.tm_year = depDateYear - 1900;//0 is 1900
        userTime.tm_mon = depDateMonth - 1; //jan is 0
        userTime.tm_mday = depDateDay;
        userTime.tm_hour = depDateHour;
        userTime.tm_min = depDateMin;
        userTime.tm_sec = second;
        time_t now = time(0);
        seconds = difftime(now, mktime(&userTime));
        double minutes = seconds / 60;
        double hours = minutes / 60;
        double days = minutes / 24;

        return static_cast<int>(floor(days));
    }
}
