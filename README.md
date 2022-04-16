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

***
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
***

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
***

### Driver

I needed a way to put it all together(in other words, I needed a driver), I could have made another class that would specifically be resposible to drive all of the component of this contact manager, but I decided to just use the main method and implement my functions there.
(Side note: I did not do it because my proffessor said it was not required, but I made sure to keep my main method clean)

Based on the objective, which was mentioned at the beginning, I made 4 functions that provide the user ability to:

* Load Contacts (see comments for explanation)
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
* Save Contacts (see comments for explanation)
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
* Add Contact (see comments for explanation)
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
* Search Contact (see comments for explanation)
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

Those 4 functions come together in my main method, 
```c++
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
```
***
### Screenshots / Project Functionality

Here are some screenshots on functionality of this application:

* This is me adding 2 random contacts:

<img width="606" alt="Screen Shot 2022-04-15 at 8 05 08 PM" src="https://user-images.githubusercontent.com/59861277/163659137-b660d9ef-06d7-4d7d-839a-fff42a97dcdd.png">

* Once we type in "-1" to search contacts, we can find those 2 contacts with their corresponding ID's:

<img width="601" alt="Screen Shot 2022-04-15 at 8 06 53 PM" src="https://user-images.githubusercontent.com/59861277/163659186-ed226a42-8a00-41b6-bc17-6dfb4214fe8e.png">

* If we attempt to find contact by ID that is out-of-bound we get the following message:

<img width="573" alt="Screen Shot 2022-04-15 at 8 08 31 PM" src="https://user-images.githubusercontent.com/59861277/163659225-9cbe3409-8283-4911-b10a-32298d94981d.png">

* If you noticed, the number of avaliable contacts is 45 but we only added 2.
* Reasoning for this is once you are done adding your own contacts, it loads 43 contacts from a text file in order to test the loadContacts function, and see if the operator overloading is working.

* This is the first 2 contacts that are loaded after I added 2 contacts manually.
<img width="237" alt="Screen Shot 2022-04-15 at 8 14 42 PM" src="https://user-images.githubusercontent.com/59861277/163659383-24e3c752-c996-45c3-a066-3623a0319497.png">

* Those 2 contacts get assinged a unique identifier in order they are loaded, so that we can search for them:

<img width="581" alt="Screen Shot 2022-04-15 at 8 16 23 PM" src="https://user-images.githubusercontent.com/59861277/163659423-31a9a42e-02fb-4886-8081-76ff3c2ab9f6.png">

* Once all of the contact searching is done, we can exit the program by typing "-1", which results in the following message:

<img width="577" alt="Screen Shot 2022-04-15 at 8 17 44 PM" src="https://user-images.githubusercontent.com/59861277/163659476-b2d6907b-04ee-474b-967f-137643158cb3.png">

* And we can confirm that the contacts we added + the contacts that were loaded, are succesfully saved to a file "output.txt":

<img width="295" alt="Screen Shot 2022-04-15 at 8 18 58 PM" src="https://user-images.githubusercontent.com/59861277/163659503-d65fb3ec-91cc-4cc5-9553-b04501213622.png">

***

## What I Learned

I learned a lot about operator overloading and how to implement this concept into a real solution, and I find operator overloading very useful and necessary.

