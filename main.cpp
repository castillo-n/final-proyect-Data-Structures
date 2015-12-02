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
void getPlaneInfo(int index);
void getFlightInfo(int index);
void getPassengerInfo(int index);
void purchaseSeat();
void printItinerary();
void menu();

//int testItinerary();
vector<Plane> Fleet;
vector<Flight> FlightList;
vector<Passenger> PassengerList;

int main(){
//   int j = testItinerary();

    return 0;
}
//
//int testItinerary(){
//    cout  << "Initiating test on itinirary class" << endl;
//
//    cout  << "Trying to create an itinerary object by calling the constructor" << endl;
//    Itinerary it;
//    cout  << "Constructor worked" << endl;
//
//    cout  << "Trying to set a passenger object pointer to it" << endl;
//    Passenger * aPassenger = new Passenger();
//    it.setPassenger(*aPassenger);
//    cout  << "Passenger object assignment worked" << endl;
//
//
//    cout  << "Trying to set flight object pointer to it" << endl;
//    Flight * aFlight = new Flight();
//    it.setFlight(*aFlight);
//    cout  << "Flight object assignment worked" << endl;
//
//    cout  << "Trying to set seat object pointer to it" << endl;
//    Seat * aSeat = new Seat();
//    it.setSeat(*aSeat);
//    cout  << "Flight object assignment worked" << endl;
//
//    cout  << "Test ended on itinirary class" << endl;
//
//}

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

    Fleet.push_back(*plane);
}

void addFlight(){
    Flight * flight = new Flight();

    FlightList.push_back(*flight);
}

void addPassenger(){
    Passenger * passenger = new Passenger();
    string FirstName;
    string LastName;

    cout << "";

    PassengerList.push_back(*passenger);
}

void connectPlaneToFlight(){

}