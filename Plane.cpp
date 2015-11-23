//
// Created by Grant on 11/17/2015.
//

#include "Plane.h"

namespace Airline {

    Plane::Plane() {
        columns = 0;
        rows = 0;
        identifier = 0;
    }

    Plane::Plane(int newColumns, int newRows, char newIdentifier) {
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

    void Plane::setIdentifier(char newIdentifier) {
        identifier = newIdentifier;
    }

    char Plane::getIdentifier() const {
        return identifier;
    }

}