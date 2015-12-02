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
        identifier = "";
        
    }

    Plane::Plane(int newColumns, int newRows, string newIdentifier) {
        columns = newColumns;
        rows = newRows;
        identifier = newIdentifier;
        
    }

    void Plane::setColumns(int newColumns){
        columns = newColumns;
        
    }

    int Plane::getColumns() const {
        return columns;
        
    }

    void Plane::setRows(int newRows) {
        rows = newRows;
        
    }

    int Plane::getRows() const {
        return rows;
        
    }

    void Plane::setEconRows(int newEconRows) {
        econRows = newEconRows;
        
    }

    int Plane::getEconRows() const {
        return econRows;
        
    }

    void Plane::setEconPlusRows(int newEconPlusRows) {
        econPlusRows = newEconPlusRows;
        
    }

    int Plane::getEconPlusRows() const {
        return econPlusRows;
        
    }

    void Plane::setFirstClassRows(int newFirstClassRows) {
        firstClassRows = newFirstClassRows;
    }

    int Plane::getFirstClassRows() const {
        return firstClassRows;
    }

    void Plane::setIdentifier(string newIdentifier) {
        identifier = newIdentifier;
        
    }

    string Plane::getIdentifier() const {
        return identifier;
        
    }

}