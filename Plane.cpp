//
// Created by Grant on 11/17/2015.
//

#include "Plane.h"
#include <string>

using namespace std;

namespace Airline {

    Plane::Plane() {
        columns = 0;
        rows = 0;
        econRows = 0;
        econPlusRows = 0;
        firstClassRows = 0;
        price = 0;
        identifier = "";
        
    }

    Plane::Plane(int newColumns, int newRows, string newIdentifier) {
        columns = newColumns;
        rows = newRows;
        identifier = newIdentifier;
        
    }

    void Plane::setColumns(int & newColumns) const{
        columns = newColumns;
        
    }

    int Plane::getColumns() const {
        return columns;
        
    }

    void Plane::setRows(int & newRows) const{
        rows = newRows;
        
    }

    int Plane::getRows() const {
        return rows;
        
    }

    void Plane::setEconRows(int & newEconRows) const{
        econRows = newEconRows;
        
    }

    int Plane::getEconRows() const {
        return econRows;
        
    }

    void Plane::setEconPlusRows(int & newEconPlusRows) const{
        econPlusRows = newEconPlusRows;
        
    }

    int Plane::getEconPlusRows() const {
        return econPlusRows;
        
    }

    void Plane::setFirstClassRows(int & newFirstClassRows) const{
        firstClassRows = newFirstClassRows;
    }

    int Plane::getFirstClassRows() const {
        return firstClassRows;
    }

<<<<<<< Updated upstream
=======
<<<<<<< HEAD
    void Plane::setIdentifier(string & newIdentifier) const{
=======
>>>>>>> Stashed changes
    void Plane::setSeatPrice(double newPrice) {
        price = newPrice;
    }

    double Plane::getPrice() const {
        return price;
    }

    void Plane::setIdentifier(string newIdentifier) {
>>>>>>> origin/master
        identifier = newIdentifier;
        
    }

    string Plane::getIdentifier() const {
        return identifier;
        
    }

}