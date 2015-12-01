//
// Created by Grant on 11/17/2015.
//

#ifndef FINALPROJECT_PLANE_H
#define FINALPROJECT_PLANE_H

namespace Airline {
    class Plane {
    public:
        Plane(); // base constructor setting all class variables to 0
        Plane(int newColumns, int newRows, char newIdentifier); // constructor that sets the dimensions of the plane and the plane identifier
        void setColumns(int newColumns); // sets the number of columns
        int getColumns() const; // gets the number of columns
        void setRows(int newRows); // sets the number of rows
        int getRows() const; // gets the number of rows
        void setEconRows(int newEconRows);
        int getEconRows() const;
        void setEconPlusRows(int newEconPlusRows);
        int getEconPlusRows() const;
        void setFirstClassRows(int newFirstClassRows);
        int getFirstClassRows() const;
        void setIdentifier(char newIdentifier); // sets the planes identification tag
        char getIdentifier() const; // gets the planes identification tag
    private:
        int columns; // contains the number of columns
        int rows; // contains the number or rows
        int econRows;
        int econPlusRows;
        int firstClassRows;
        char identifier; // contains the identification tag of the plane
    };
}

#endif //FINALPROJECT_PLANE_H
