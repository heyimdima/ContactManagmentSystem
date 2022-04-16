// Dmytro Bondar
// CST-210 (Tue/Thu) (9:00-10:45am)
// February 6, 2021 (02/06/2022)
// Contact Management System Project
// This is my own work.

#ifndef CONTACTMANAGMENTSYSTEM_CONTACT_H
#define CONTACTMANAGMENTSYSTEM_CONTACT_H

// Contact Class Header
#include <iostream>
#include "Name.h"
#include "Address.h"

class Contact {
private:
    Name name;
    Address address;
    std::string phone;
    int id;
    // update identifier if object doesn't have one
    void setID();
public:
    static int totalCt;
    Contact();
    Contact(std::string, std::string, std::string, std::string, std::string, std::string);
    Contact(const Contact &c);
    void setName(std::string, std::string);
    Name getName() const;
    void setAddress(std::string, std::string, std::string);
    Address getAddress() const;
    void setPhone(std::string);
    std::string getPhone() const;
    int getID() const;
    friend std::ostream& operator<<(std::ostream& out, const Contact& rhs);
    friend std::istream& operator>>(std::istream& in, Contact& rhs);

};


#endif //CONTACTMANAGMENTSYSTEM_CONTACT_H
