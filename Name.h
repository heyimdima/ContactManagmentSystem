// Dmytro Bondar
// CST-210 (Tue/Thu) (9:00-10:45am)
// February 6, 2021 (02/06/2022)
// Contact Management System Project
// This is my own work

#ifndef CONTACTMANAGMENTSYSTEM_NAME_H
#define CONTACTMANAGMENTSYSTEM_NAME_H

// Name Class Header
#include <iostream>


class Name {
private:
    std::string first_name;
    std::string last_name;
public:
    Name();
    Name(std::string, std::string);
    Name(const Name& n);
    void setFName(std::string);
    std::string getFName() const;
    void setLName(std::string);
    std::string getLName() const;
    std::string getFullName() const;
    friend std::istream& operator>>(std::istream& in, Name& rhs);
    friend std::ostream& operator<<(std::ostream& o, const Name& rhs);
};


#endif //CONTACTMANAGMENTSYSTEM_NAME_H
