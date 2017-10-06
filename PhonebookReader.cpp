//============================================================================
// Name        : PhonebookReader.cpp
// Author      : Robin Shaw
// Version     :
// Copyright   : Your copyright notice
// Description : A reader and array builder/editor for phonebook.txt
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include "Contact.h"
using namespace std;



int main() {
	char command;
	Contact phonebook[151430];
	//Contact phonebook[100]; //used for testing with a smaller array
	int counter = 0;
	string name;
	string lname;
	int number;


	cout << "Welcome to My Phonebook Operation!" << endl;
	cout << "Now reading phonebook.txt ..." << endl;
	ifstream book;
	book.open ("phonebook.txt");
	while (!book.eof()) {
		 book >> name;
		 book >> lname;
		 book >> number;
		 name = name + " " + lname;
		 phonebook[counter].setNumber(number);
		 phonebook[counter].setName(name);
		 //These were used for testing to see if it was building right:
//		 cout << phonebook[counter].getName() <<" "<< phonebook[counter].getNumber();
//		 cout << " " << counter<<endl;
	    ++counter;
	}
	book.close();


	for (;;) { //infinite loop until user closes it with Q
		cout << "Please select an operation:" << endl;
		cout << "A (Add) | S (Search) | D (Delete) | L (List) | Q (Quit): ";
		cin >> command;
		cout << endl;


		if (command == 'A') { //Add
			if (counter >= 151430) {
				cout << "You have selected to enter a new name, but regrettably" <<endl;
				cout << "My program has not been built to handle this large of a phone book." <<endl;
				cout << "I recommend getting a new one and using this one as a door stopper." <<endl;
				continue;
			}
			cout << "command = A" << endl;
			cout << "please enter a name: ";
			cin >> name >> lname;
			name = name + " " + lname;
			cout << "please enter a number: ";
			int numberhere;
			cin >> numberhere;
			phonebook[counter].setName(name);
			phonebook[counter].setNumber(numberhere);
			cout << phonebook[counter].getName() << " " << phonebook[counter].getNumber() << " has been added." << endl;
			++counter;


		}
		else if (command == 'S') { //Search
			cout << "command = S" << endl;
			cout << "please enter a name: ";
			cin >> name >> lname;
			name = name + " " + lname;
			int found = 0;
			for (int i = 0; i <= counter-1; i++) {
				if (phonebook[i].compareNames(name) == 0) {
					cout << "Name: "<< name << endl;
					cout << "Number: " << phonebook[i].getNumber() <<endl;
					found = 1;
					break;
				}
			}
			if (found != 1) {
				cout << "Name was not found." <<endl;
				found = 0;
			}



		}
		else if (command == 'D') { //Delete
			cout << "Please enter a name to delete:" << endl;
			cin >> name >> lname;
			name = name + " " + lname;
			int found = 0;
				for (int i = 0; i <= counter-1; i++) {
					if (phonebook[i].compareNames(name) == 0) {
						phonebook[i].blankThis();
						found = 1;
						cout << name << " has been removed." <<endl;
						break;
					}
				}
				if (found != 1) {
					cout << "Name was not found." <<endl;
					found = 0;
			}



		}
		else if (command == 'L') { //List
			for (int i = 0; i < counter; ++i) {
				if (phonebook[i].getNumber() == 0) {
					continue;
				} //This will skip deleted entries
				cout << phonebook[i] << endl;
			}

		}
		else if (command == 'Q') { //Quit
			cout << "The program will now quit." << endl;
			cout << "Thanks for running!" << endl;
			break;

		} else {
			cout << "Valid command not given. Please try again." << endl;
		}
	}
	return 0;
}
