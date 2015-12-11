//
// Created by Grant on 11/17/2015.
//

#include "Plane.h"
#include <string>

using namespace std;

namespace Airline {

    Plane::Plane() {
        econRows = 0;
        econPlusRows = 0;
        firstClassRows = 0;
        price = 0;
        identifier = "";
        
    }

    Plane::Plane(string newIdentifier) {
//        columns = newColumns;
//        rows = newRows;
        identifier = newIdentifier;
        
    }

//    void Plane::setColumns(int const & newColumns ){
//        columns = newColumns;
//
//    }
//
//    int Plane::getColumns() const {
//        return columns;
//
//    }

//    void Plane::setRows(int const & newRows){
//        rows = newRows;
//
//    }
//
//    int Plane::getRows() const {
//        return rows;
//
//    }

    void Plane::setEconRows(int const & newEconRows){
        econRows = newEconRows;
        
    }

    int Plane::getEconRows() const {
        return econRows;
        
    }

    void Plane::setEconPlusRows(int const & newEconPlusRows){
        econPlusRows = newEconPlusRows;
        
    }

    int Plane::getEconPlusRows() const {
        return econPlusRows;
        
    }

    void Plane::setFirstClassRows(int const & newFirstClassRows){
        firstClassRows = newFirstClassRows;
    }

    int Plane::getFirstClassRows() const {
        return firstClassRows;
    }

    void Plane::setIdentifier(string const & newIdentifier) {
        identifier = newIdentifier;
    }

    void Plane::setSeatPrice(double const & newPrice){
        price = newPrice;
    }

    double Plane::getPrice() const {
        return price;
    }

    string Plane::getIdentifier() const {
        return identifier;
        
    }

    void Plane::setEconColumns(int const & newEconColumns){
        econColumns = newEconColumns;
    }
    int Plane::getEconColumns() const{
        return  econColumns;
    }
    void Plane::setEconPlusColumns(int const & newEconPlusColumns){
        econPlusColumns = newEconPlusColumns;
    }
    int Plane::getEconPlusColumns() const{
        return econPlusColumns;
    }
    void Plane::setFirstClassColumns(int const & newFirstClassColumns){
        firstClasColumns = newFirstClassColumns;
    }
    int Plane::getFirstClassColumns() const{
        return firstClasColumns;
    }

}