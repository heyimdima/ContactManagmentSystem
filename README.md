# Contact Managment System

## Overview
This was the project I did for my CST-210 class, operator overloading was hard to figure out at first, but I was able to figure it out. I found this project to be fun and easy to implement.

## Objective
* Implement a software solution that creates a contact management system. 
* The contact management system will use file input/output to store user-inputted names, addresses, and phone numbers.  
* The user can choose to input new contact or search for a contact using a unique identifier. 
* When the program is terminated, the contacts are saved in a .txt file so they are available the next time the program is run.


## Purpose
The purpose of this assignment is to assess the ability to:
* Use multiple levels of abstraction in software design.
* Utilize file input/output in a C++ program.
* Utilize operator overloading in a C++ program.

## My approach
### Object-Oriented Solution

For this project I made the Contact Class which has the properties name, address, phone and id: 
```c++
class Contact {
private:
    Name name;
    Address address;
    std::string phone;
    int id;
    // update identifier if object doesn't have one
    void setID(); // sets the ID when the contact is created
```

So, the Contact has a name that is a Name class which has the followoing properties:
```c++
class Name {
private:
    std::string first_name;
    std::string last_name;
```

and Contact has an address that is Address class which has the following properties:
```c++
class Address {
private:
    std::string street;
    std::string state;
    std::string zip;
```

and that's how I broke down the Contact class, in order to overload the input and output operators in the future.

### Operator Overloading

In order to read/write contacts to a file, I had to overload the input and output operators

I started by overloading the input(istream) and output(ostream) operators in the Name class,
```c++
...
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
```

After that I overloaded the input(istream) and output(ostream) operators in the Address class,
```c++
// istream "in" operator modifier
// provides ability to read the contact street, state and zip
// from the file
std::istream& operator>>(std::istream& in, Address& a) {
    getline(in, a.street);
    getline(in, a.state);
    getline(in, a.zip);
    return in;
}

// istream out operator modifier
// provide the ability to output the street, state and zip in certain format
std::ostream& operator<<(std::ostream& o, const Address& rhs) {
    o << rhs.street << "\n" << rhs.state << "\n" << rhs.zip;
    return o;
}
```

And finally, I had to put it all together in the Contact class,
```c++
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
```
