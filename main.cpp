#include <iostream>
#include <fstream>
#include <string>
#include "Seat.h"
#include "Plane.h"
#include "Flight.h"
#include "Passenger.h"
#include "Itinerary.h"

using namespace std;
using namespace Airline;

void connect(ifstream file);
void save(ofstream file);
void addPlane();
void addFLight();
void addPassenger();
void connectPlaneToFlight();
void setUpFlights();
void getPlaneInfo();
void getFlightInfo();
void getPassengerInfo();
void purchaseSeat();
void printItinerary();
void menu();
//


int main(){
    Airline::Itinerary i;
}
void connect(ifstream file){

}

void save(ofstream file){

}

void addPlane(){
    Plane * plane = new Plane();
    string identifier;
    int numFCROws;
    int numEPRows;
    int numEcRows;
    int cols;
    int rows;
    double price;

    cout << "Enter the Plane's Tag: ";
    cin >> identifier;
    plane->setIdentifier(identifier);
    cout <<  "Enter the number of rows the plane contains: ";
    cin >> rows;
    plane->setRows(rows);
    cout << "Enter the number of columns the plane contains: ";
    cin >> cols;
    cout << "Enter the number of First Class rows: ";
    cin >> numFCROws;
    plane->setFirstClassRows(numFCROws);
    cout << "Enter the number of Economey Plus Rows: ";
    cin >> numEPRows;
    plane->setEconPlusRows(numEPRows);
    cout << "Enter the number of Economy Rows: ";
    cin >> numEcRows;
    plane->setEconRows(numEcRows);
    cout << "Enter the Base Price of the Seat: ";
    cin >> price;
    plane->setSeatPrice(price);

    Fleet.push_back(*plane);
}

void addFlight(){
    Flight * flight = new Flight();
    string identifier;
    string DepCity;
    string DepDate;
    string DepTime;
    string ArrCity;
    string ArrDate;
    string ArrTime;
    int distance;

    cout << "Enter the Flight's tag: ";
    cin >> identifier;
    flight->setIdentifier(identifier);
    cout << "Enter the Departing City: ";
    cin >> DepCity;
    flight->setDepCity(DepCity);
    cout << "Enter the Departure Date: ";
    cin >> DepDate;
    flight->setDepDate(DepDate);
    cout << "Enter the Departure Time: ";
    cin >> DepTime;
    flight->setDepTime(DepTime);
    cout << "Enter the Arrival City: ";
    cin >> ArrCity;
    flight->setArrCity(ArrCity);
    cout << "Enter the Arrival Date: ";
    cin >> ArrDate;
    flight->setArrDate(ArrDate);
    cout << "Enter the Arrival Time: ";
    cin >> ArrTime;
    flight->setArrTime(ArrTime);
    cout << "Enter the distance in miles of the Flight: ";
    cin >> distance;
    flight->setDistance(distance);

    FlightList.push_back(*flight);
}

void addPassenger(){
    Passenger * passenger = new Passenger();
    string FirstName;
    string LastName;

    cout << "Enter the passengers First Name: ";
    cin >> FirstName;
    passenger->setFirstName(FirstName);
    cout << "Enter the passenger's Last Name: ";
    cin >> LastName;
    passenger->setLastName(LastName);

    PassengerList.push_back(*passenger);
}

void connectPlaneToFlight(){

    for(int i = 0; i < FlightList.size(); i++){
        for(int j = 0; j < Fleet.size(); j++){
            if(FlightList[i].getIdentifier() == Fleet[j].getIdentifier()){
                FlightList[i].addPlane(Fleet[j]);
            }
        }
    }
}

void setUpFlights(){
    for(int i = 0; i < FlightList.size(); i++){
        FlightList[i].createSeatMap();
    }
}

void getPlaneInfo(){

    string identifier;
    Plane plane;

    cout << "Enter the Plane's Tag: ";
    cin >> identifier;

    for(int i = 0; i < Fleet.size(); i++){
        if(Fleet[i].getIdentifier() == identifier){

        }
    }


}