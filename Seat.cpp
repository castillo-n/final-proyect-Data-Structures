//
// Created by Grant on 10/22/2015.
//

#include "Seat.h"

namespace Airline {
        Seat::Seat() {
            price = 0;
            NumDays = 0;
            miles = 0;
        }

        Seat::Seat(double newPrice) {
            price = newPrice;
            NumDays = 0;
            miles = 0;
        }

        Seat::Seat(double newPrice, int days) {
            price = newPrice;
            NumDays = days;
            miles = 0;
        }

        Seat::Seat(double newPrice, int days, int newMiles) {
            price = newPrice;
            NumDays = days;
            miles = newMiles;
        }

        void Seat::setSeatAv(char newSeatAv){
            seatAv = newSeatAv;
        }

        char Seat::getSeatAv() const{
            return seatAv;
        }

        double Seat::getPrice() const {
            return price;
        }

        void Seat::setPrice(double newPrice) {
            price = newPrice;
        }

        int Seat::getNumDays() const {
            return NumDays;
        }

        void Seat::setNumDays(int days) {
            NumDays = days;
        }

        int Seat::getMiles() const {
            return miles;
        }

        void Seat::setMiles(int newMiles) {
            miles = newMiles;
        }
        
        double Seat::CalculatePrice() const {
			return price;
		}

    int Seat::getSeatRow() const{
        return rowNumber;
    }
    int Seat::getSeatCol() const{
        return colNumber;
    }
    char Seat::getSeatColChar() const{
        return colChar;
    }
    void Seat::setSeatRow(int const row){
        rowNumber = row;
    }
    void Seat::setSeatCol(int const col){
        colNumber = col;
        colChar = static_cast<int> ('A'+col);
    }
	
}
