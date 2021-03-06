#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
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
        cout << "       3_ Connect Plains to Flights" << endl;
        cout << "       4_ Add a new passenger to the list of passengers" << endl;
        cout << "       5_ Add a passenger to a flight" << endl;
        cout << "       6_ Change the plane assigned to a flight" << endl;
        cout << "       7_ Print the upcoming flights" << endl;
        cout << "       8_ Print a list of passengers on a given flight" << endl;
        cout << "       9_ Print Interary for passenger" << endl;
        cout << "       10_ Save current information" << endl;
        cout << "       11_ Exit" << endl;
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
                connectPlaneToFlight();
                break;
            case 4:
                addNewPassenger();
                break;
            case 5:
                addPassengerToFlight();
                break;
            case 6:
                connectPlaneToFlight();
                break;
            case 7:
                printFlights();
                break;
            case 8:
                printPassengerListOnFlight();
                break;
            case 9:
                printItinerary();
                break;
            case 10:
                save();
                break;
            case 11:
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
//    cout << "works 1 "<<endl;
    connectPlaneToFlight();
//    cout << "works 2 "<<endl;
    setUpFlights();
    connectPlaneToFlight();
//    cout << "works 3 "<<endl;
}
void lineToFleet(string line){
//    cout << line << endl;
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
//    cout << line << endl;
    Passenger newPassenger = Passenger();
    newPassenger.setName(line);
    PassengerList.push_back(newPassenger);
    //cout << "passenger line done!" << endl;
}
void lineToFlights(string line){
//    cout << line << endl;
    string id, dC, aC, aD, aT, dDateYear, dDateMonth, dDateDay, dDateHour, dDateMin, dDateAmPm, aDateYear, aDateMonth, aDateDay, aDateHour, aDateMin, aDateAmPm;
    int check = 0; ///bemidji 12/12/2015 12:12 am
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
            //cout << "dDateMonth "<< endl;
            aDateMonth += line[i];
        }
        else if(check == 10){
            //cout << "dDateDay "<< endl;
            aDateDay += line[i];
        }
        else if(check == 11){
            //cout << "dDateYear "<< endl;
            aDateYear += line[i];
        }
        else if(check == 12){
            //cout << "aDateHour "<< endl;
            aDateHour += line[i];
        }
        else if(check == 13){
            //cout << "aDateMin "<< endl;
            aDateMin += line[i];
        }
        else if(check == 14){
            //cout << "aDateAmPm "<< endl;
            aDateAmPm += line[i];
        }
        lastChar = line[i];
    }
    Flight *newFlight = new Flight();
    int m=0, d=0,y=0,h=0,mi=0;
    newFlight->setIdentifier(id);
    newFlight->setDepCity(dC);
    if(aDateMonth!="") {
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

    if(aDateMonth!="") {
        m = stoi(aDateMonth);
    }
    if(aDateMonth!="") {
        d = stoi(aDateDay);
    }
    if(aDateMonth!="") {
        y = stoi(aDateYear);
    }
    if(aDateMonth!="") {
        h = stoi(aDateHour);
    }
    if(aDateMonth!="") {
        mi = stoi(aDateMin);
    }
    newFlight->setArrDateTime(m, d , y, h, mi, aDateAmPm);
    newFlight->setArrCity(aC);
    newFlight->setArrDate(aD);
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
    for(int i = 0; i < PassengerList.size(); i++) {
        if (PassengerList[i].getName() != "" && PassengerList[i].getName() != " " && PassengerList[i].getName() != "\n") {
            savingStream << PassengerList[i].getName() << PassengerList[i].dumpItinerary() << endl;
//            PassengerList[i].
        }
    }



    savingStream << endl;


    savingStream << "FLIGHTS" << endl;
    for(int i = 0; i < FlightList.size(); i++) {
        if (FlightList[i].getIdentifier() != "" && FlightList[i].getIdentifier() != "0" && FlightList[i].getIdentifier() != "0 " && FlightList[i].getIdentifier() != " ") {
            savingStream
            << FlightList[i].getIdentifier() << " "
            << FlightList[i].getDepCity() << " "
            << FlightList[i].getDepTime() << " "
            << FlightList[i].getArrCity() << " "
            << FlightList[i].getArrTime() << " "
            << endl;
//            for (int j = 0; j < FlightList[i].numOfPassengers(); j++) {
//                savingStream << FlightList[i].getPassenger(j).getName() << "\n\r";
//            }

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
    int ArrMonth;
    int ArrYear;
    int ArrDay;
    int ArrHour;
    int ArrMin;
    string ArrAmPm;
    string ArrTime;
    string ArrCity;
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
    cout << "Enter the Arrival Month: ";
    cin >> ArrMonth;
    cin.clear();
    cout << "Enter the Arrival Day: ";
    cin >> ArrDay;
    cin.clear();
    cout << "Enter the Arrival Year: ";
    cin >> ArrYear;
    cin.clear();
    cout << "Enter the Arrival Hour: ";
    cin >> ArrHour;
    cin.clear();
    cout << "Enter the Arrival Minute: ";
    cin >> ArrMin;
    cin.clear();
    cout << "Enter the Arrival time (am or pm): ";
    cin >> ArrAmPm;
    cin.clear();
    flight.setArrDateTime(DepMonth, DepDay, DepYear, DepHour, DepMin, DepAmPm);
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
            cout << FlightList.size() << " " << Fleet.size() << endl;
            if(FlightList[i].getIdentifier() == Fleet[j].getIdentifier()){
                if(FlightList[i].getIdentifier()!=" " && FlightList[i].getIdentifier()!="") {
                    cout << FlightList[i].getIdentifier() << " " << Fleet[j].getIdentifier() << endl;
                    FlightList[i].addPlane(Fleet[j]);
                }
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

    Seat * seat;

    int indexFlight=-1;
    int indexFleet=-1;
    int indexPassenger=-1;

    cout << "Enter the Flight's Tag: ";
    cin >> identifier;

    for(int i = 0; i < FlightList.size(); i++){
        if(FlightList[i].getIdentifier() == identifier){
            indexFlight = i;
//            cout << to_string(indexFlight) << endl;
        }
    }

    if(indexFlight != -1) {
        for (int i = 0; i < Fleet.size(); i++) {
            if (Fleet[i].getIdentifier() == identifier) {
                indexFleet = i;
//                cout << to_string(indexFlight) << endl;
            }
        }
        if (indexFleet != 1) {
            int er,ec,pr,pc,fr,fc;
            er = Fleet[indexFleet].getEconRows();
            ec = Fleet[indexFleet].getEconColumns();
            pr = Fleet[indexFleet].getEconPlusRows();
            pc = Fleet[indexFleet].getEconPlusColumns();
            fr = Fleet[indexFleet].getFirstClassRows();
            fc = Fleet[indexFleet].getFirstClassColumns();
            cout << "Enter the Passenger's First Name: ";
            cin >> first;
            cout << "Enter the Passenger's Last Name: ";
            cin >> last;

            name = first + " " + last;
            bool pass = true;
            for (int i = 0; i < PassengerList.size(); i++) {
//                cout << "in for loop " << endl;
//                cout << " ----------------- " << endl;
//                cout << PassengerList[i].getName() << endl;
//                cout << " ----------------- " << endl;
//                cout << name << endl;
                if (PassengerList[i].getName() == name) {
                    cout << PassengerList[i].getName() << endl;
                    indexPassenger = i;
                    pass = false;
                }
            }
//            cout << "done with the loop " << endl;
            if (pass) {
                cout << "there was no passager with that name, creating one..." << endl;
                Passenger p = Passenger();
                p.setName(first, last);
                PassengerList.push_back(p);
                indexPassenger = PassengerList.size() - 1;
            }
            int row, col;
            bool occupied = true;
            FlightList[indexFlight].displaySeatMap();
            Itinerary *it = new Itinerary();
            while (occupied) {
                bool check = false;
                cout << "Enter the Seat Row: ";
                cin >> row;
                cout << "Enter the seat Col: ";
                cin >> col;
                seat = FlightList[indexFlight].getSeat(row-1, col-1);
                seat->setNumDays(FlightList[indexFlight].amountOfDaysTo());
                double price = seat->CalculatePrice();
                if (seat->getSeatAv() != 'X') {
                    string yesNo;
                    cout <<
                    "The seat is available for $" + to_string(price) +
                    ". Do you want to purchase? (yes or no or x to exit)" <<
                    endl;
                    cin >> yesNo;
                    if (yesNo == "YES" || yesNo == "Yes" || yesNo == "yes") {
                        FlightList[indexFlight].occupySeat(row-1, col-1); //ocupy the seat
                        it->setSeat(*seat);
                        PassengerList[indexPassenger].setItinerary(it);
                        occupied = false;
                    }else if(yesNo == "x" || yesNo == "X") {
                        occupied = false;
                    }
                }
                else{
                        cout << "Sorry the seat is taken, try again" << endl;
                }
            }

            cout << "Your seat has been purchased." << endl
            << "Balance: $" << seat->CalculatePrice();
            it->setFlight(FlightList[indexFlight]);
            PassengerList[indexPassenger].setItinerary(it);
            FlightList[indexFlight].addPassenger(PassengerList[indexPassenger]);
        }
        else{
            cout << "There is no flight with that identifier in our Fleet" << endl;
        }
    }
    else{
        cout << "There is no flight with that identifier" << endl;
    }
}

void printItinerary(){

    Itinerary * it;
    int passengerIndex;
    string first;
    string last;
    string name;
    string identifier;
    bool isIt = true;

    cout << "Enter Passenger's First Name: ";
    cin >> first;
    cin.clear();
    cout << "Enter Passenger's Last Name: ";
    cin >> last;
    cin.clear();

    name = first + " " + last;

    for(int i = 0; i < PassengerList.size(); i++){
        if(PassengerList[i].getName() == name){
            passengerIndex = i;
        }
    }

    while(isIt) {
        cout << "Enter the flight identfier for the Itinerary of that flight: ";
        cin >> identifier;
        cin.clear();

        it = PassengerList[passengerIndex].getItinerary(identifier);

        if(it->getFlight()->getIdentifier() == identifier){
            isIt = false;
            cout << "-------------------------------------" << endl
                 << "Name: " << name << endl
                 << "Flight Identifier: " << it->getFlight()->getIdentifier() << endl
                 << "Departing City: " << it->getFlight()->getDepCity() << endl
                 << "Departing Date: " << it->getFlight()->getDepDate() << endl
                 << "Departing Time: " << it->getFlight()->getDepTime() << endl
                 << "Arrival City: " << it->getFlight()->getArrCity() << endl
                 << "Arrival Date: " << it->getFlight()->getArrDate() << endl
                 << "Arrival Time: " << it->getFlight()->getArrTime() << endl
                 << "Seat: Row " << it->getSeat()->getSeatRow() << " Column " << it->getSeat()->getSeatCol() << endl
                 << "Price: " << it->getSeat()->CalculatePrice() << endl
                 << "-------------------------------------" << endl;
        }
        else{
            cout << "Identifier entered in does not match. Please enter a proper identifier." << endl;
        }
    }

}



void printFlights(){
    for(int i = 0; i < FlightList.size(); i++) {
        if (FlightList[i].getIdentifier() != "" && FlightList[i].getIdentifier() != " " &&
            FlightList[i].getIdentifier() != "0") {
            cout << "Flight: " << FlightList[i].getIdentifier() << endl;
            cout << "Departing City: " << FlightList[i].getDepCity() << endl;
            cout << "Departure Time: " << FlightList[i].getDepTime() << endl;
            cout << "Arriving City: " << FlightList[i].getArrCity() << endl;
            cout << "Arrival Time: " << FlightList[i].getArrTime() << endl << endl;
        }
    }
}

void printPassengerListOnFlight(){
    string identifier;
    int index=-1;
    Passenger p;

    cout << "Enter The Flight's Tag: ";
    cin >> identifier;

    for(int i = 0; i < FlightList.size(); i++) {
        if(identifier == FlightList[i].getIdentifier()){
            index = i;
        }
    }
    if(index != -1) {
        cout << "Flight: " << FlightList[index].getIdentifier();
        for (int i = 0; i < FlightList[index].numOfPassengers(); i++) {
            p = FlightList[index].getPassenger(i);
            cout << i << ": " << p.getName() << p.getItinerary(identifier)->getSeat()->getSeatRow() << p.getItinerary(identifier)->getSeat()->getSeatColChar() << endl;
        }
    }else{
        cout << "sorry there is no fly with that id" << endl;
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
