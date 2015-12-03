#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>
#include "Seat.h"
#include "Plane.h"
#include "Flight.h"
#include "Passenger.h"
#include "Itinerary.h"

using namespace std;
using namespace Airline;

void connect(ifstream file);
void save(ofstream file);
void addNewPlane();
void addNewFLight();
void addNewPassenger();
void connectPlaneToFlight();
void setUpFlights();
void addPassengerToFlight();
void printFlights();
void prinPassengerListOnFlight();
void purchaseSeat();
void printItinerary();
void menu();


vector <Plane> Fleet;
vector <Flight> FlightList;
vector <Passenger> PassengerList;


int main(){
    Seat j;
}
void connect(ifstream file){

}

void save(ofstream file){

}

void addNewPlane(){
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

void addNewFlight(){
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
void addNewPassenger(){
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

void addPassengerToFlight(){

    string identifier;
    string first;
    string last;
    string name;

    int indexFlight;
    int indexPassenger;

    cout << "Enter the Flight's Tag: ";
    cin >> identifier;

    for(int i = 0; i < FlightList.size(); i++){
        if(FlightList[i].getIdentifier() == identifier){
            indexFlight = i;
        }
    }

    cout << "Enter the Paassenger's First Name: ";
    cin >> first;
    cout << "Enter the Paassenger's Last Name: ";
    cin >> last;

    name = first + " " + last;

    for(int i = 0; i < PassengerList.size(); i++){
        if(PassengerList[i].getName() == name){
            indexPassenger = i;
        }
    }

    FlightList[indexFlight].addPassenger(PassengerList[indexPassenger]);
}

void printFlights(){
    for(int i = 0; i < FlightList.size(); i++){
        cout << "Flight: " << FlightList[i].getIdentifier() << endl;
        cout << "Departing City: " << FlightList[i].getDepCity() << endl;
        cout << "Departure Date: " << FlightList[i].getDepDate() << endl;
        cout << "Departure Time: " << FlightList[i].getDepTime() << endl;
        cout << "Arriving City: " << FlightList[i].getArrCity() << endl;
        cout << "Arrival Date: " << FlightList[i].getArrDate() << endl;
        cout << "Arrival Time: " << FlightList[i].getArrTime() << endl << endl;
    }
}

void prinPassengerListOnFlight(){
    string identifier;
    int index=0;
    Passenger p;

    cout << "Enter The Flight's Tag: ";
    cin >> identifier;

    for(int i = 0; i < FlightList.size(); i++) {
        if(identifier == FlightList[i].getIdentifier()){
            index = i;
        }
    }

    cout << "Flight: " << FlightList[index].getIdentifier();

    for(int i = 0; i < FlightList[index].numOfPassengers(); i++){
        p = FlightList[index].getPassenger(i);
        cout << i << ": " << p.getName() << endl;
    }

}

// don't know what this does
// this returns the difference between the date of today and the freaking flight date :) -Nelson
int dateDifferenceToday(const int &year, const int &month, const int &day, const int &hour, const int &minute) {
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