#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>
#include <sys/types.h>
#include <dirent.h>
#include "Seat.h"
#include "Plane.h"
#include "Flight.h"
#include "Passenger.h"
#include "Itinerary.h"

using namespace std;
using namespace Airline;

void connect();
void create();
void save();
void addNewPlane();
void addNewFLight();
void addNewPassenger();
void connectPlaneToFlight();
void setUpFlights();
void addPassengerToFlight();
void printFlights();
void printPassengerListOnFlight();
void purchaseSeat();
void removeOldFlights();
void printItinerary();
void menu();
void lineToFleet(string line);
void lineToPassenger(string line);
void lineToFlights(string line);

void menuSelectorOpenNew();
string fileName;
vector <Plane> Fleet;
vector <Flight> FlightList;
vector <Passenger> PassengerList;


int main() {
    int Option = 0;
    bool checker = true;
    int counter = 0;
    string fileName;
    string listOfFiles[1000];
    cout << endl;
    menuSelectorOpenNew();

    while (checker) {
        cout << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "                  Select an option from the following menu " << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "Select: " << endl;
        cout << "       1_ Add a new plane to the fleet" << endl;
        cout << "       2_ Add a new flight to the schedule" << endl;
        cout << "       3_ Add a new passenger to the list of passengers" << endl;
        cout << "       4_ Add a passenger to a flight" << endl;
        cout << "       5_ Change the plane assigned to a flight" << endl;
        cout << "       6_ Print the upcoming flights" << endl;
        cout << "       7_ Print a list of passengers on a given flight" << endl;
        cout << "       8_ Save current information" << endl;
        cout << "       9_ Exit" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "# >> ";
        cin >> Option;
        cin.clear();
        switch (Option)
        {
            case 1:
                addNewPlane();
                break;
            case 2:
                addNewFLight();
                break;
            case 3:
                addNewPassenger();
                break;
            case 4:
                addPassengerToFlight();
                break;
            case 5:
                connectPlaneToFlight();
                break;
            case 6:
                printFlights();
                break;
            case 7:
                printPassengerListOnFlight();
                break;
            case 8:
                save();
                break;
            case 9:
                checker = false;
                break;
            default:
                cout << "The answer is not a valid answer, please try again" << endl;
                break;
        }
        Option = 0;
        cout << "--------------------------------------------------------------------------" << endl;

    }
}
void connect(){

    fstream inputStream;

    inputStream.open(fileName);


    if( !(inputStream.is_open()) ){
        cout << "Sorry but the file: " << fileName <<" doesn't exist" << endl;
    } else {
        //read function call to add inputStream >> Fleet >> FlightList >> PassengerList >> endl;

        ifstream openingStream;
        openingStream.open(fileName);
        string line_;
        bool fleet_ = false;
        bool pass_ = false;
        bool flight_ = false;
        while (getline(openingStream, line_)) {
            //cout << line_ << endl;
            if(line_ == "FLEET"){//if fleet start putting data there
                fleet_ = true;
                pass_ = false;
                flight_ = false;
            }else if(line_ == "PASSENGERS"){ //else if passenger put it there
                fleet_ = false;
                pass_ = true;
                flight_ = false;
            }else if(line_ == "FLIGHTS"){ /// else if flights put it there
                fleet_ = false;
                pass_ = false;
                flight_ = true;
            }
            else if(fleet_){lineToFleet(line_);}
            else if(pass_){lineToPassenger(line_);}
            else if(flight_){lineToFlights(line_);}
        }

        //cout << "Everythign is done!" << endl;
        //get fleet
    }
}
void lineToFleet(string line){
    //cout << line << endl;
    string id = "", econRow = "0", econCol = "0", plusRow = "0", plusCol = "0", firstRow = "0", firstCol = "0", price = "0";
    int check = 0;
    bool firstChar = false;
    for(int i = 0; i < line.length(); i++){
        if(line[i] == ' ' && firstChar){
            check++;
        }
        else if(check == 0){
            firstChar = true;
            id +=line[i];
        }
        else if(check == 1){
            econRow +=line[i];
        }
        else if(check == 2){
            econCol +=line[i];
        }
        else if(check == 3){
            plusRow +=line[i];
        }
        else if(check == 4){
            plusCol +=line[i];
        }
        else if(check == 5){
            firstRow +=line[i];
        }
        else if(check == 6){
            firstCol +=line[i];
        }
        else if(check == 7){
            price +=line[i];
        }
    }

    int a;
    Plane *newPlane = new Plane();
    if(id!="") {
        newPlane->setIdentifier(id);
        a = stoi(plusRow);
        newPlane->setEconPlusRows(a);
        a = stoi(plusCol);
        newPlane->setEconPlusColumns(a);
        a = stoi(econRow);
        newPlane->setEconRows(a);
        a = stoi(econCol);
        newPlane->setEconColumns(a);
        a = stoi(firstRow);
        newPlane->setFirstClassRows(a);
        a = stoi(firstCol);
        newPlane->setFirstClassColumns(a);
        a = stoi(econRow);
        double b = stod(price);
        newPlane->setSeatPrice(b);
        Fleet.push_back(*newPlane);
    }
    //cout << "fleet line done!" << endl;

}
void lineToPassenger(string line){
    //cout << line << endl;
    Passenger newPassenger = Passenger();
    newPassenger.setName(line);
    PassengerList.push_back(newPassenger);
    //cout << "passenger line done!" << endl;
}
void lineToFlights(string line){
    //cout << line << endl;
    string id, dC, aC, aD, aT, dDateYear, dDateMonth, dDateDay, dDateHour, dDateMin, dDateAmPm;
    int check = 0;
    char lastChar = ' ';
    for(int i = 0; i < line.length(); i++){
        //cout << line[i] << endl;
        if((line[i] == ' ' && lastChar!= ' ') || line[i] == '/' || line[i] == ':'){
            check++;
        }
        else if(line[i] == ' '){
            string doNothing= ":)";
        }
        else if(check == 0){
            //cout << "id "<< endl;
            id +=line[i];
        }
        else if(check == 1){
            //cout << "dC "<< endl;
            dC +=line[i];
        }
        else if(check == 2){
            //cout << "dDateMonth "<< endl;
            dDateMonth += line[i];
        }
        else if(check == 3){
            //cout << "dDateDay "<< endl;
            dDateDay += line[i];
        }
        else if(check == 4){
            //cout << "dDateYear "<< endl;
            dDateYear += line[i];
        }
        else if(check == 5){
            //cout << "dDateHour "<< endl;
            dDateHour += line[i];
        }
        else if(check == 6){
            //cout << "dDateMin "<< endl;
            dDateMin += line[i];
        }
        else if(check == 7){
            //cout << "dDateAmPm "<< endl;
            dDateAmPm += line[i];
        }
        else if(check == 8){
            //cout << "aC "<< endl;
            aC +=line[i];
        }
        else if(check == 9){
            //cout << "aD "<< endl;
            aD +=line[i];
        }
        else if(check >= 10){
            //cout << "aT "<< endl;
            aT +=line[i];
        }
        lastChar = line[i];
    }
    Flight *newFlight = new Flight();
    int m=0, d=0,y=0,h=0,mi=0;
    newFlight->setIdentifier(id);
    newFlight->setDepCity(dC);
    if(dDateMonth!="") {
        m = stoi(dDateMonth);
    }
    if(dDateMonth!="") {
        d = stoi(dDateDay);
    }
    if(dDateMonth!="") {
        y = stoi(dDateYear);
    }
    if(dDateMonth!="") {
        h = stoi(dDateHour);
    }
    if(dDateMonth!="") {
        mi = stoi(dDateMin);
    }
    newFlight->setDepDateTime(m, d , y, h, mi, dDateAmPm);
    newFlight->setArrCity(aC);
    newFlight->setArrDate(aD);
    newFlight->setArrTime(aT);
    FlightList.push_back(*newFlight);
    //cout << "flights line done!" << endl;
}

void create(){

    ofstream savingStream;
    savingStream.open(fileName);
    savingStream.close();

}

void save(){
    ofstream savingStream;
    savingStream.open(fileName);
    savingStream << "FLEET" << endl;
    for(int i = 0; i < Fleet.size(); i++){
        if(Fleet[i].getIdentifier()!= "0") {
            savingStream
            << Fleet[i].getIdentifier() << " "
            << Fleet[i].getEconRows() << " "
            << Fleet[i].getEconColumns() << " "
            << Fleet[i].getEconPlusRows() << " "
            << Fleet[i].getEconPlusColumns() << " "
            << Fleet[i].getFirstClassRows() << " "
            << Fleet[i].getFirstClassColumns() << " "
            << Fleet[i].getPrice() << " " << endl;
        }
    }
    savingStream << endl;
    savingStream << "PASSENGERS" << endl;
    for(int i = 0; i < PassengerList.size(); i++){
            cout << PassengerList[i].getName() << endl;
        savingStream << PassengerList[i].getName()  << endl;
    }

        savingStream << endl;

    savingStream << "FLIGHTS" << endl;
    for(int i = 0; i < FlightList.size(); i++){
        savingStream
            << FlightList[i].getIdentifier() << " "
            << FlightList[i].getDepCity() << " "
            << FlightList[i].getDepTime() << " "
            << FlightList[i].getArrCity() << " "
            << FlightList[i].getArrDate() << " "
            << FlightList[i].getArrTime() << " "
            << endl;
        for(int j = 0; j < FlightList[i].numOfPassengers(); j++){
            savingStream  << FlightList[i].getPassenger(j).getName() << "\n\r";
        }

    }

    savingStream << endl;
    savingStream.close();

}

void addNewPlane(){
    Plane plane = Plane();
    string identifier;
    int numFCROws;
    int numPCROws;
    int numECROws;
    int numFCols;
    int numPCols;
    int numECols;
    double price;

    cout << "Enter the Plane's Tag: ";
    cin >> identifier;
    cin.clear();
    plane.setIdentifier(identifier);
    cout << "Enter the number of First Class rows: ";
    cin >> numFCROws;
    cin.clear();
    plane.setFirstClassRows(numFCROws);
    cout << "Enter the number of First Class columns: ";
    cin >> numFCols;
    cin.clear();
    plane.setFirstClassColumns(numFCols);
    cout << "Enter the number of Economy Plus Rows: ";
    cin >> numPCROws;
    cin.clear();
    plane.setEconPlusRows(numPCROws);
    cout << "Enter the number of Economy Plus Columns: ";
    cin >> numPCols;
    cin.clear();
    plane.setEconPlusColumns(numPCols);
    cout << "Enter the number of Economy Rows: ";
    cin >> numECROws;
    cin.clear();
    plane.setEconRows(numECROws);
    cout << "Enter the number of Economy Columns: ";
    cin >> numECols;
    cin.clear();
    plane.setEconColumns(numECols);
    cout << "Enter the Base Price of the Seat: ";
    cin >> price;
    cin.clear();
    plane.setSeatPrice(price);
    Fleet.push_back(plane);
}

void addNewFLight(){
    Flight flight = Flight();
    string identifier;
    string DepCity;
    int DepMonth;
    int DepYear;
    int DepDay;
    int DepHour;
    int DepMin;
    string DepAmPm;
    string DepTime;
    string ArrCity;
    string ArrDate;
    string ArrTime;
    int distance;

    cout << "Enter the Flight's tag: ";
    cin >> identifier;
    flight.setIdentifier(identifier);
    cin.clear();
    cout << "Enter the Departing City: ";
    cin >> DepCity;
    flight.setDepCity(DepCity);
    cin.clear();
    cout << "Enter the Departure Month: ";
    cin >> DepMonth;
    cin.clear();
    cout << "Enter the Departure Day: ";
    cin >> DepDay;
    cin.clear();
    cout << "Enter the Departure Year: ";
    cin >> DepYear;
    cin.clear();
    cout << "Enter the Departure Hour: ";
    cin >> DepHour;
    cin.clear();
    cout << "Enter the Departure Minute: ";
    cin >> DepMin;
    cin.clear();
    cout << "Enter the Departure time (am or pm): ";
    cin >> DepAmPm;
    cin.clear();
    flight.setDepDateTime(DepMonth, DepDay, DepYear, DepHour, DepMin, DepAmPm);
    cout << "Enter the Arrival City: ";
    cin >> ArrCity;
    cin.clear();
    flight.setArrCity(ArrCity);
    cout << "Enter the Arrival Date: ";
    cin >> ArrDate;
    cin.clear();
    flight.setArrDate(ArrDate);
    cout << "Enter the Arrival Time: ";
    cin >> ArrTime;
    cin.clear();
    flight.setArrTime(ArrTime);
    cout << "Enter the distance in miles of the Flight: ";
    cin >> distance;
    cin.clear();
    flight.setDistance(distance);

    FlightList.push_back(flight);
}
void addNewPassenger(){
    Passenger pa = Passenger();
    string FirstName;
    string LastName;

    Passenger p = Passenger();
    cout << "Enter the passengers First Name: ";
    cin >> FirstName;
    cout << "Enter the passenger's Last Name: ";
    cin >> LastName;
    p.setName(FirstName, LastName);

    PassengerList.push_back(p);
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

    int indexFlight=-1;
    int indexPassenger=-1;

    cout << "Enter the Flight's Tag: ";
    cin >> identifier;

    for(int i = 0; i < FlightList.size(); i++){
        if(FlightList[i].getIdentifier() == identifier){
            indexFlight = i;
        }
    }

    cout << "Enter the Passenger's First Name: ";
    cin >> first;
    cout << "Enter the Passenger's Last Name: ";
    cin >> last;

    name = first + " " + last;
    bool pass = true;
    for(int i = 0; i < PassengerList.size(); i++){
        if(PassengerList[i].getName() == name){
            indexPassenger = i;
            pass = false;
        }
    }
    if(pass){
        Passenger p = Passenger();
        p.setName(first, last);
        PassengerList.push_back(p);
    }
    cout << "here 1" <<endl;
    FlightList[indexFlight].addPassenger(PassengerList[indexPassenger]);
    cout << "here 2" <<endl;
}

void purchaseSeat(){
    string identifier;
    Flight flight;
    Seat seat;
    int row;
    int col;

    cout << "Enter the Flight's Tag: ";
    cin >> identifier;

    for(int i = 0; i < FlightList.size(); i++){
        if(FlightList[i].getIdentifier() == identifier){
            flight = FlightList[i];
        }
    }

    flight.displaySeatMap();

    cout << "Enter the Seat Row: ";
    cin >> row;
    cout << "Enter the seat Col: ";
    cin >> col;

    seat = flight.getSeat(row, col);
    flight.occupySeat(row, col);

    //needs to get current date and calculate price for when the passenger purchased the seat
    //seat.setNumDays();

    cout << "Your seat has been purchased." << endl
         << "Balance: $" << seat.CalculatePrice();

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

void printPassengerListOnFlight(){
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


void menuSelectorOpenNew(){
    int counter = 0;
    int Option = 0;
    bool checker = true;
    string listOfFiles[1000];
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "--------------------- Thank you for using our program --------------------" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "------------------------- Flight reservation tool ------------------------" << endl;
    cout << "--------------------------------------------------------------------------" << endl << endl;
    cout << endl;

    while (checker) {
        cout << "--------------------------------------------------------------------------" << endl << endl;
        cout << "                  Select an option from the following menu " << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "Select: " << endl;
        cout << "       1_ Open a saved file" << endl;
        cout << "       2_ Create a new file" << endl;
        cout << "# >> ";
        cin >> Option;

        if (Option == 1 || Option == 2) {

            if (counter == 0) {
                DIR *dir;
                struct dirent *ent;
                if ((dir = opendir(".")) != NULL) {
                    /* print all the files and directories within directory */
                    while ((ent = readdir(dir)) != NULL) {
                        string nameOfThisFile = ent->d_name;
//                        cout << nameOfThisFile <<endl;
//                        cout << nameOfThisFile.substr(nameOfThisFile.length()-5, nameOfThisFile.length()) << endl;
                        if (nameOfThisFile.length() > 5 && nameOfThisFile.substr(nameOfThisFile.length() - 4, nameOfThisFile.length()) == ".pla") {
                            listOfFiles[counter] = nameOfThisFile;
                            counter++;

//                            cout << nameOfThisFile.substr((nameOfThisFile.length()-4), nameOfThisFile.length()) << endl;
                        }
                    }
                }
                    closedir(dir);
            }


            if (Option == 1) {
                if (counter == 0) {
                    char a;
                    cout << "Sorry, there are no .pla files in the directory" << endl;
                    cout << "Would you like us to search again?" << endl;
                    cout << "y or n >> ";
                    cin >> a;
                    if(a == 'y' || a == 'Y'){
                        counter = 0;//there are no files so dont go there again to check for files
                    }else if( a != 'n' || a != 'N'){
                        counter = -1;
                    }else{
                        if(counter == 0){
                            counter =-1;
                        }
                    }
                } else if(counter>0){
                    int n;
                    cout << "--------------------------------------------------------------------------" << endl;
                    cout << "Select one of the files from the following list" << endl;
                    cout << "--------------------------------------------------------------------------" << endl;
                    for(int i=0; i<listOfFiles->size(); i++) {
                        if (listOfFiles[i] != "") {
                            cout << (i + 1) << "_ " << listOfFiles[i] << endl;
                        }
                    }
                    cout << "# >> ";
                    cin >> n;
                    if(listOfFiles[ n -1 ]!= ""){
                        fileName = listOfFiles[n - 1];
                        checker = false;
                        cout << "Opening " + fileName << endl;
                        connect();
                    }else{
                        cout << "The option number was invalid, returning to previous menu. " << endl;
                    }
                    cout << "--------------------------------------------------------------------------" << endl;
                }
            } else {
                string f;
                cout << "--------------------------------------------------------------------------" << endl;
                cout << "Type the name of the file" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                cout << "name >> ";
                cin >> f;

                if(f != ""){
                    if(f.length() > 4 && f.substr(f.length() - 4, f.length()) == ".pla") {
                        fileName = f;
                    }else{
                        fileName = f + ".pla";
                    }
                    checker = false;
                    cout << "Creating " + fileName << endl;
                    create();
                }else{
                    cout << "The file name was invalid, returning to previous menu. " << endl;
                }

            }


        }else {
            cout << "The # option was invalid, try again. " << endl;
        }

    }
}
