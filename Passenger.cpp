//
// Created by Grant on 11/17/2015.
//

#include <string.h>
#include "Itinerary.h"

using namespace std;

namespace Airline {


    Passenger::Passenger(){
        balance=0;
        firstName = "";
        lastName = "";
        numberOfItineraries=0;
    }
    string Passenger::getName() const{
        return fullName;
    }

    void Passenger::setName(string & fName, string & lName) {
//        int frontName, backName, frontLast, backLast;
//        for(int i=0; i < fName.length(); i++){
//            if(fName[i] != ' '){
//                frontName = i;
//            }
//        }
//        for(int i = fName.length(); i > 0; i++){
//            if(fName[i] != ' '){
//                backName = i;
//            }
//        }for(int i=0; i < lName.length(); i++){
//            if(fName[i] != ' '){
//                frontLast = i;
//            }
//        }
//        for(int i = lName.length(); i > 0; i++){
//            if(fName[i] != ' '){
//                backLast = i;
//            }
//        }
//        for(int i = frontLast; i < backLast+1; i++){
//            lastName += fName[i];
//        }
//        for(int i = frontName; i < backName+1; i++){
//            firstName += fName[i];
//        }
        firstName = fName;
        lastName = lName;
        fullName = fName + " " + lName;
    }
    void Passenger::setName(string & theFullName) {
        fullName = theFullName;
        firstName = "";
        lastName = "";
        bool fn = true;
        for(int i = 0; i < theFullName.length(); i++) {
            if (theFullName[i] == ' ') {
                fn = false;
            }
            if(fn){
                firstName+=theFullName[i];
            }else{
                lastName+=theFullName[i];
            }
        }
    }

    void Passenger::setFirstName(string & fName) {
        firstName = fName;
    }

    void Passenger::setLastName(string & lName) {
        lastName = lName;
    }

    Itinerary Passenger::getItinerary(string flightIdentifier)const{
        for( int it = 0; it != itineraryList.size(); ++it) {
            if (flightIdentifier == itineraryList[it]->getFlight().getIdentifier()) {
                return *itineraryList[it];
            }
        }
        return Itinerary();
    }
    string Passenger::dumpItinerary(){
        string theFuckingDump=" ";
        for( int it = 0; it != itineraryList.size(); ++it) {
                theFuckingDump += itineraryList[it]->getFlight().getIdentifier() + " " + to_string(itineraryList[it]->getSeat().getSeatRow())+to_string(itineraryList[it]->getSeat().getSeatCol()) + "-";
        }
        return theFuckingDump;
    }

    void Passenger::setItinerary(Itinerary * theItine) {
        itineraryList.push_back(theItine);
    }
}