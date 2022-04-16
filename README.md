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


For this project I made the Contact Class which hasthe properties name, address, phone and id: 
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

Contact has an address that is Address class which has the following properties:
```c++
private:
    std::string street;
    std::string state;
    std::string zip;
```
