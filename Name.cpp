// Dmytro Bondar
// CST-210 (Tue/Thu) (9:00-10:45am)
// February 6, 2021 (02/06/2022)
// Contact Management System Project
// This is my own work

#include "Name.h"

// Name Class Implementation
#include <iostream>

// default constructor
 Name::Name() {
    first_name = "";
    last_name = "";
}

// parameterized constructor
Name::Name(std::string first, std::string last) {
    this->first_name = first;
    this->last_name = last;
}

// copy constructor
Name::Name(const Name &n) {
    this->first_name = n.first_name;
    this->last_name = n.last_name;
}

// setter for the first name
void Name::setFName(std::string first) {
    this->first_name = first;
}

// getter for the first name
std::string Name::getFName() const {
    return first_name;
}

// setter for the last name
void Name::setLName(std::string last) {
    this->last_name = last;
}

// getter for the last name
std::string Name::getLName() const {
    return last_name;
}

// getter for the full name
std::string Name::getFullName() const {
    return first_name + ", " + last_name;
}

// istream "in" operator modifier
// provides ability to read the contact first and last name
// from the file
std::istream& operator>>(std::istream& in, Name& rhs) {
    getline(in, rhs.last_name);
    getline(in, rhs.first_name);
    return in;
}

// istream out operator modifier
// provide the ability to output the first and last name in certain format
std::ostream& operator<<(std::ostream& o, const Name& rhs) {
    o << rhs.last_name << ", " << rhs.first_name;
    return o;
}