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

        int econRows = designatedPlane->getEconRows();
        int econCol = designatedPlane->getEconColumns();
        int econPlusRows = designatedPlane->getEconPlusRows();
        int econPlusCol = designatedPlane->getEconPlusColumns();
        int firstClassRows = designatedPlane->getFirstClassRows();
        int firstClassCol = designatedPlane->getFirstClassColumns();
        double price = designatedPlane->getPrice();

        for(int i = 0; i < firstClassRows; i++){
            vector<Seat*> firstClassRow;
            for(int j = 0; j < firstClassCol; j++ ){
                FirstClass *f = new FirstClass();
                f->setPrice(price);
                f->setSeatAv('0');
                f->setMiles(distance);
                f->setSeatCol(j+1);
                f->setSeatRow(i+1);
                firstClassRow.push_back(f);
            }
            seatMap.push_back(firstClassRow);
        }

        for(int i = 0; i < econPlusRows; i++){
            vector<Seat*> EconPlusRow;
            for(int j = 0; j < econPlusCol; j++ ){
                EconomyPlus *p = new EconomyPlus();
                p->setPrice(price);
                p->setSeatAv('0');
                p->setMiles(distance);
                p->setSeatCol(j+1);
                p->setSeatRow(i+1);
                EconPlusRow.push_back(p);
            }
            seatMap.push_back(EconPlusRow);
        }

        for(int i = 0; i < econRows; i++){
            vector<Seat*> EconRow;
            for(int j = 0; j < econCol; j++ ){
                Economy *e = new Economy();
                e->setPrice(price);
                e->setSeatAv('0');
                e->setMiles(distance);
                e->setSeatCol(j+1);
                e->setSeatRow(i+1);
                EconRow.push_back(e);
            }
            seatMap.push_back(EconRow);
        }
    }

    void Flight::displaySeatMap() {
        int frows = designatedPlane->getFirstClassRows();
        int fcols = designatedPlane->getFirstClassColumns();
        int erows = designatedPlane->getFirstClassRows();
        int ecols = designatedPlane->getFirstClassColumns();
        int prows = designatedPlane->getFirstClassRows();
        int pcols = designatedPlane->getFirstClassColumns();
        char firstCol = static_cast<int> ('A'+ fcols);
        char plusCol = static_cast<int> ('A'+ pcols);
        char econCol = static_cast<int> ('A'+ ecols);
        cout << "O - vacant seat" << endl;
        cout << "X - occupied seat" << endl;
        cout << "First Class Seats Rows: 1 - " << to_string(frows) << " - Rows: A - "<< firstCol << endl;
        cout << "Economy Plus Seats " << to_string(frows + 1) <<"-" << to_string(frows + prows) << " - Rows: A - "<< plusCol << endl;
        cout << "Economy Seats " << to_string(frows + prows + 1) << "-" <<  to_string(frows + prows + erows) << " - Rows: A - "<< econCol << endl;

        cout << "----------------- First Class -----------------" << endl;
        for(int i = 0; i < frows; i++){
            if(i < 9) {
                cout << " " << i << ": ";
            }else {
                cout << i << ": ";
            }
            for (int j = 0; j < fcols; j++){
                cout << seatMap[i][j]->getSeatAv();
//                cout << seatMap[i][j]->getSeatCol() << ":" << seatMap[i][j]->getSeatAv();
            }
        }
        cout << "-------------- Economy Plus Class --------------" << endl;
        for(int i = 0; i < (prows + frows); i++){
            if(i < 9) {
                cout << " " << i << ": ";
            }else {
                cout << i << ": ";
            }
            for (int j = 0; j < pcols; j++){
                cout << seatMap[i][j]->getSeatAv();
//                cout << seatMap[i][j]->getSeatCol() << ":" << seatMap[i][j]->getSeatAv();
            }
        }
        cout << "---------------- Economy Class ----------------" << endl;

        for(int i = 0; i < (prows + frows + erows); i++){
            if(i < 9) {
                cout << " " << i << ": ";
            }else {
                cout << i << ": ";
            }
            for (int j = 0; j < ecols; j++){
                cout << seatMap[i][j]->getSeatAv();
//                cout << seatMap[i][j]->getSeatCol() << ":" << seatMap[i][j]->getSeatAv();
            }
        }
        cout << "-----------------------------------------------" << endl;
    }

    void Flight::clearSeatMap() {
        int frows = designatedPlane->getFirstClassRows();
        int fcols = designatedPlane->getFirstClassColumns();
        int erows = designatedPlane->getFirstClassRows();
        int ecols = designatedPlane->getFirstClassColumns();
        int prows = designatedPlane->getFirstClassRows();
        int pcols = designatedPlane->getFirstClassColumns();
        int i;
        for(i = 0; i < frows; i++){
            for (int j = 0; j < fcols; j++){
                delete(seatMap[i][j]);
            }
        }
        for(i = frows; i < frows+erows; i++){
            for (int j = 0; j < ecols; j++){
                delete(seatMap[i][j]);
            }
        }
        for(i=frows+erows; i < frows+erows+prows; i++){
            for (int j = 0; j < pcols; j++){
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
    void Flight::seatDumper( istream & file ){

        for(int i = 0; i < seatMap.size(); i++){
           vector<Seat *> s = seatMap.at(i);
            for(int j = 0; j < s.size(); j++){
                Seat *seat = s.at(j);
                seat->getSeatAv();
            }
        }

    }
}
