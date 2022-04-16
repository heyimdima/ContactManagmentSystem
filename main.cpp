// Dmytro Bondar
// CST-210 (Tue/Thu) (9:00-10:45am)
// February 6, 2021 (02/06/2022)
// Contact Management System Project
// This is my own work

// References
// Had to research about exit() function of C++ on the C++ reference website
// Link provided below
// https://www.cplusplus.com/reference/cstdlib/exit/

// imports
#include <iostream>
#include <fstream>
#include <vector>
#include "Contact.h"

// function to read in contacts from the input file and add them to the vector of contacts
// so that we can test the contact search and potentially load contacts user might have prior to creating new ones
void loadContacts(std::istream& in, std::vector<Contact>& list);

// function to write all the contacts in the vector to the output file
// essentially transfer all the contacts into the output.txt file
void saveContacts(std::ostream& out, const std::vector<Contact>& list);

// function to add individual contact (prompts the user to enter information) and adds the contact to vector
void addContact(std::vector<Contact>& list);

// search for certain contact (based off user input) in the vector of contacts
// and print it to the console
void searchContact(std::vector<Contact>& list);

int main() {
    // initialize the files for input and output
    std::ifstream input("/Users/dimabondar/Desktop/School/Year1S2/CST-210/CST-210_WorkSpace/ContactManagmentSystem/input.txt");
    std::ofstream output("/Users/dimabondar/Desktop/School/Year1S2/CST-210/CST-210_WorkSpace/ContactManagmentSystem/output.txt");

    // initialize the vector of the class Contact to store the contacts
    std::vector<Contact> myContacts;

    // initialize a variable to hold user input so the loop can break upon certain input
    std::string userInput;

    // while loop to enter contacts until user types in "-1" to end the loop
    while(userInput != "-1") {
        addContact(myContacts); // create contact
        std::cout << "   ---Enter -1 to search contacts, enter 1 to add another contact: ";
        std::getline(std::cin, userInput); // read in input and store it as userInput
    }

    // read in the contacts from the input file and add them to the vector of contacts
    loadContacts(input, myContacts);

    // write all the contacts to the output file
    saveContacts(output, myContacts);

    // search for certain contacts(based off user input)
    searchContact(myContacts);

    return 0;
}

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

void saveContacts(std::ostream& out, const std::vector<Contact>& list) {
    // write all the contacts to the file output
    for(const auto & i : list) {
        out << i << std::endl;
    }
}

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
}

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