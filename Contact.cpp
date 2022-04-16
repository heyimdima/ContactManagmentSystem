// Dmytro Bondar
// CST-210 (Tue/Thu) (9:00-10:45am)
// February 6, 2021 (02/06/2022)
// Contact Management System Project
// This is my own work

#include "Contact.h"

// Contact Class Implementation
#include <iostream>

int Contact::totalCt = 0; // initialize the counter

void Contact::setID() { // setter for the id (private)
    totalCt++;
    id = totalCt;

}
// default constructor
Contact::Contact() {
    this->name = Name();
    this->address = Address();
    this->phone = "";

    // do not update totalCt until attributes are assigned
    this->id = -1;
}
// parameterized constructor
Contact::Contact(std::string firstName, std::string lastName, std::string street, std::string state, std::string zip, std::string phone) {
    this->name = Name(firstName, lastName);
    this->address = Address(street, state, zip);
    this->phone = phone;
    totalCt++;

    this->id = totalCt;
}

// copy constructor
Contact::Contact(const Contact &c) {
    this->name = c.name;
    this->address = c.address;
    this->phone = c.phone;
    this->id = c.id;
}

// setter for the name
void Contact::setName(std::string first, std::string last) {
    this->name = Name(first, last);
}

// getter for the name
Name Contact::getName() const {
    return name;
}

// setter for the address
void Contact::setAddress(std::string street, std::string state, std::string zip) {
    this->address = Address(street, state, zip);
}

// getter for the address
Address Contact::getAddress() const {
    return address;
}

// setter for the phone
void Contact::setPhone(std::string phone) {
    this->phone = phone;
}

// getter for the phone
std::string Contact::getPhone() const {
    return phone;
}

// getter for the ID
int Contact::getID() const {
    return id;
}

// modifies ostream "out" operator using a friend function
// modifies the output to have ability
// to print all the info about the contact on each new line and format it
std::ostream& operator<<(std::ostream& out, const Contact& rhs) {
    out << rhs.id << "\n" << rhs.name.getFName() << "\n" << rhs.name.getLName() << "\n" <<
        rhs.address.getStreet() << "\n" << rhs.address.getState() << "\n" <<
        rhs.address.getZip() << "\n" << rhs.phone;
    return out;
}

// modifies the "in" operator of the istream
// to have the ability to read the contacts from the file
std::istream& operator>>(std::istream& in, Contact& rhs) {
    in >> rhs.name;
    in >> rhs.address;
    getline(in, rhs.phone);
    rhs.setID();
    return in;
}