//
// Created by Grant on 11/17/2015.
//

#include "Flight.h"

namespace Airline{
    Flight::Flight(){
    }

    Flight::Flight(string newDepCity, string newArrCity, string newDepDate, string newDepTime, string newArrDate, string newArrTime, char newIdentifier){
        depCity = newDepCity;
        arrCity = newArrCity;
        depDate = newDepDate;
        arrDate = newArrDate;
        depTime = newDepTime;
        arrTime = newArrTime;
        identifier = newIdentifier;
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
    void setArrTime(string newArrTime);
    string getArrTime();
    void setIdentifier(char newIdentifier);
    char getIdentifier();
    void createSeatMap();
    void addPlane();
}