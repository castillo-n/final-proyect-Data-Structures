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

    Plane Flight::getPlane(int i){
        return planList[i];
    }

    void Flight::createSeatMap(){
        int i  = 0;
        while(planeList[i]!= null){
            for(int j = 0; j < planeList[i]->getRows(); j++){
                for(int k; k < planeList[i]->getColumns(); k++){
                    if(j < 3){
                        seatMap[i][j][k] = new FirstClass();
                    }
                    else if(j >= 3 && j < 9){
                        seatMap[i][j][k] = new EconomyPlus();
                    }
                    if(j >= 9 && j < planeList[i]->getRows()){
                        seatMap[i][j][k] = new Economy();
                    }
                }
            }
            i++;
        }
    }

}