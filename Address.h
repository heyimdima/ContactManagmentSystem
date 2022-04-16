// Dmytro Bondar
// CST-210 (Tue/Thu) (9:00-10:45am)
// February 6, 2021 (02/06/2022)
// Contact Management System Project
// This is my own work

#ifndef CONTACTMANAGMENTSYSTEM_ADDRESS_H
#define CONTACTMANAGMENTSYSTEM_ADDRESS_H

// Address Class Header
#include <iostream>

class Address {
private:
    std::string street;
    std::string state;
    std::string zip;
public:
    Address();
    Address(std::string, std::string, std::string);
    Address(const Address& a);
    void setStreet(std::string);
    std::string getStreet() const;
    void setState(std::string);
    std::string getState() const;
    void setZip(std::string);
    std::string getZip() const;
    friend std::istream& operator>>(std::istream& in, Address& a);
    friend std::ostream& operator<<(std::ostream& o, const Address& rhs);

};


#endif //CONTACTMANAGMENTSYSTEM_ADDRESS_H
