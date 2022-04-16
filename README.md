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

### Driver

To put it all together, I needed a way to put it all together, I could have made another class that would specifically be resposible
to drive all of the component of this contact manager, but I decided to just use the main method and implement my function there.

Based the objective, which was mentioned at the beginning, I made 4 functions that provide the user ability to:

* Load Contacts
```c++
// function to read in contacts from the input file and add them to the vector of contacts
// so that we can test the contact search and potentially load contacts user might have prior to creating new ones
void loadContacts(std::istream& in, std::vector<Contact>& list) {
    // check if the file is open/found
    if(!in) {
        std::cout << "File not found" << std::endl;
    }
    // initialize contact
    Contact c;

    // add contacts to the vector from the file until there are no more contacts in the file
    // using modified istream
    while(in >> c) {
        list.push_back(c);
    }
}
```
* Save Contacts
```c++
// function to write all the contacts in the vector to the output file
// essentially transfer all the contacts into the output.txt file
void saveContacts(std::ostream& out, const std::vector<Contact>& list) {
    // write all the contacts to the file output
    for(const auto & i : list) {
        out << i << std::endl;
    }
}
```
* Add Contact
```c++
// function to add individual contact (prompts the user to enter information) and adds the contact to vector
void addContact(std::vector<Contact>& list) {
    // initialize variables to take in the information about a contact
    std::string first, last, street, state, zip, phone;

    // get contact information from the user
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "   --- Enter the following information for your contact ---\n";
    std::cout << "   --- Enter first name: ";
    std::getline(std::cin, first); // read in first name and store it as "first"
    std::cout << "   --- Enter last name: ";
    std::getline(std::cin, last); // read in last name and store it as "last"
    std::cout << "   --- Enter street address: ";
    std::getline(std::cin, street); // read in street address and store it as "street"
    std::cout << "   --- Enter state: ";
    std::getline(std::cin, state); // read in state and store it as "state"
    std::cout << "   --- Enter zip: ";
    std::getline(std::cin, zip); // read in zip code and store it as "zip"
    std::cout << "   --- Enter phone: ";
    std::getline(std::cin, phone); // read in phone number and store it as "phone"

    // initialize contact with the information provided by the user
    Contact c(first, last, street, state, zip, phone);

    // add the contact to the vector of contacts
    list.push_back(c);

    // notify the user that the contact has been successfully added
    // specify what contact was added and provide the id
    // format (Contact:|first_name, last_name| ID:|id of that contact|)
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "   --- Contact:|" << first << ", " << last << "| " <<
        "ID:|" << c.getID() << "| has been successfully added ---" << std::endl;
    std::cout << "-------------------------------------------------------------------------" << std::endl;
```
* Search Contact
```c++
// search for certain contact (based off user input) in the vector of contacts
// and print it to the console
void searchContact(std::vector<Contact>& list) {
    // initialize ID variable to search for certain contact
    int ID = 0;

    // while loop that will break upon input of "-1"
    while(ID != -1) {
        // tell the user how to stop searching if they would like to
        std::cout << "-------------------------------------------------------------------------" << std::endl;
        std::cout << "   --- Enter -1 to STOP, number of available contacts:|" << list.size() <<"|" << std::endl;

        // ask the user to input the contact number to search
        std::cout << "   --- Enter number to search: ";

        // store input as contactID
        std::cin >> ID;

        // line of dashed lines for better format of the app
        std::cout << "-------------------------------------------------------------------------" << std::endl;

        // only print contacts within the range of the vector
        if(ID >= 1 && ID <= list.size()) {
            // print out the contact that user is looking for
            std::cout << "-------------------------------" << std::endl;
            std::cout << list[ID - 1]; // subtract 1 to account for the way index works
            std::cout << "\n-------------------------------" << std::endl;
        }
        // if user decides to stop, exit the program with exit code 0 (successful)
        else if(ID == -1) {
            // notify the user that program is terminating
            std::cout << "   --- Exiting program... ";

            // terminate the program
            exit(0);
        }
        // if contact ID is out of range, tell the user that contact with that ID does not exist
        // else statement will also cause the loop to iterate again, asking for new input
        else {
            std::cout << "   --- Contact number |" << ID << "| does not exist, try again.." << std::endl;
        }
    }
}
```

