//
// Created by Grant on 11/17/2015.
//
#include <string>
#ifndef FINALPROJECT_PLANE_H
#define FINALPROJECT_PLANE_H

using namespace std;

namespace Airline {
    class Plane {
    public:
        Plane(); // base constructor setting all class variables to 0
        Plane(int newColumns, int newRows, string newIdentifier); // constructor that sets the dimensions of the plane and the plane identifier
        void setColumns(int const & newColumns ) ; // sets the number of columns
        int getColumns() const; // gets the number of columns
        void setRows(int const & newRows); // sets the number of rows
        int getRows() const; // gets the number of rows
        void setEconRows(int const & newEconRows);
        int getEconRows() const;
        void setEconPlusRows(int const & newEconPlusRows);
        int getEconPlusRows() const;
        void setFirstClassRows(int const & newFirstClassRows);
        int getFirstClassRows() const;
        void setIdentifier(string const & newIdentifier); // sets the planes identification tag
        void setSeatPrice(double const & newPrice);
        double getPrice() const;
        string getIdentifier() const; // gets the planes identification tag
    private:
        int columns; // contains the number of columns
        int rows; // contains the number or rows
        int econRows;
        int econPlusRows;
        int firstClassRows;
        double price;
        string identifier; // contains the identification tag of the plane
    };
}

#endif //FINALPROJECT_PLANE_H
