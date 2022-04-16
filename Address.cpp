// Dmytro Bondar
// CST-210 (Tue/Thu) (9:00-10:45am)
// February 6, 2021 (02/06/2022)
// Contact Management System Project
// This is my own work

#include "Address.h"

// Address Class Implementation
#include <iostream>

// default constructor
Address::Address() {
    this->street;
    this->state;
    this->zip;
}

// parameterized constructor
Address::Address(std::string str, std::string st, std::string z) {
    this->street = str;
    this->state = st;
    this->zip = z;
}

// copy constructor
Address::Address(const Address &a) {
    this->street = a.street;
    this->state = a.state;
    this->zip = a.zip;
}

// setter for the street
void Address::setStreet(std::string str) {
    this->street = str;
}

// getter for the street
std::string Address::getStreet() const {
    return street;
}

// setter for the state
void Address::setState(std::string st) {
    this->state = st;

}// getter for the state
std::string Address::getState() const {
    return state;
}

// setter for the zip
void Address::setZip(std::string z) {
    this->zip = z;
}

// getter for the zip
std::string Address::getZip() const {
    return zip;
}

// istream "in" operator modifier to read the contacts from the file
std::istream& operator>>(std::istream& in, Address& a) {
    getline(in, a.street);
    getline(in, a.state);
    getline(in, a.zip);
    return in;
}

std::ostream& operator<<(std::ostream& o, const Address& rhs) {
    o << rhs.street << "\n" << rhs.state << "\n" << rhs.zip;
    return o;
}