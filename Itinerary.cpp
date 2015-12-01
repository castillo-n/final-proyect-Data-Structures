//
// Created by Grant on 11/17/2015.
//

#include "Itinerary.h"
#include "Passenger.h"
#include "Flight.h"
#include "Seat.h"

namespace Airline {

    Flight Itinerary::getFlight() {
        return flight;
    }

    Seat Itinerary::getSeat() {
        return seat;
    }
    Passenger Itinerary::getPassenger() {
        return passenger;
    }
    void Itinerary::setFlight(Flight & theFlight) const{ //this function will be receiving a pointer
        flight = theFlight;
    }
    void Itinerary::setSeat(Seat & theSeat) const{//this function will be receiving a pointer
        seat = theSeat;
    }
    void Itinerary::setPassenger(Passenger & thePassenger) const{//this function will be receiving a pointer
        passenger = thePassenger;
    }
    int Itinerary::TestMe(){
        cout  << "Initiating test on itinirary class" << endl;

        cout  << "Trying to create an itinerary object by calling the constructor" << endl;
        if( Itinerary it = new Itinerary()){
            cout  << "Constructor worked" << endl;

            cout  << "Trying to set a passenger object pointer to it" << endl;
            Passenger * aPassenger = new Passenger();
            if( it.setPassenger(aPassenger)){
                cout  << "Passenger object assignment worked" << endl;


                cout  << "Trying to set flight object pointer to it" << endl;
                Flight * aFlight = new Flight;
                if( it.setFlight(aFlight)){
                    cout  << "Flight object assignment worked" << endl;

                cout  << "Trying to set seat object pointer to it" << endl;
                Seat aSeat = new Seat;
                    if( it.setSeat(aSeat)){
                        cout  << "Flight object assignment worked" << endl;

                        cout  << "Test ended on itinirary class" << endl;
                        return 1;
                    }else{
                        cout  << "Flight object assignment didnt work" << endl;

                        cout  << "Test ended on itinirary class" << endl;
                        return -1;
                    }
                }else{
                    cout  << "Flight object assignment didnt work" << endl;
                    cout  << "Test ended on itinirary class" << endl;
                    return -1;
                }
            }else{
                cout  << "Passenger object assignment didnt work" << endl;
                cout  << "Test ended on itinirary class" << endl;
                return -1;
            }
        }else{
            cout  << "Constructor didnt work" << endl;
            cout  << "Test ended on itinirary class" << endl;
            return -1;
        }

    }


}