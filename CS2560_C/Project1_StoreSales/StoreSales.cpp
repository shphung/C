/*
 * Name: Steven Phung
 * Project: #1
 * Due: October 9th, 2018
 * Course: cs-2560-01-f18
 *
 * Description:
 * 	A program that keeps track of store sales. User interacts with menu
 * 	system that allows them to add sales, view sales, edit sales, or
 * 	remove sales.
 */

#include <iostream>
#include <vector>
#include <stdbool.h>
#include <string>
#include <iomanip>

using namespace std;

//Functions to add, view, edit, and remove sales.
void addSales(vector<string> &itemName, vector<double> &itemPrice);
void viewSales(vector<string> itemName, vector<double> itemPrice);
void editSales(vector<double> &itemPrice);
void removeSales(vector<string> &itemName, vector<double> &itemPrice);

//Function to print out main menu.
int mainMenu();

int main() {
	//Vectors to hold name of item and item price correspondingly.
	vector<string> itemName;
	vector<double> itemPrice;

	//Boolean to allow looping as well as exitting loop.
	bool quit = false;

	//Loop to continually display menu and receive user input until program exit.
	while (!quit) {
		//Retrieve user input.
		int option = mainMenu();
		cin.ignore();
		switch (option) {
			case 1:
				//If user input is 1, go to addSales function.
				addSales(itemName, itemPrice);
				break;
			case 2:
				//If user input is 2, go to removeSales function.
				removeSales(itemName, itemPrice);
				break;
			case 3:
				//If user input is 3, go to editSales function.
				editSales(itemPrice);
				break;
			case 4:
				//If user input is 4, go to viewSales function.
				viewSales(itemName, itemPrice);
				break;
				//If user input is 0, quit program.
			case 0:
				cout << "\nQuitting program...\n";
				quit = true;
				break;
				//Any other input is considered invalid.
			default:
				cout << "\nInvalid input, please try again: ";
		}
	}
	return 0;
}

//Function that adds one item to both vectors correspondingly.
void addSales(vector<string> &name, vector<double> &price) {
	//Boolean to allow looping as well as exitting loop.
	bool exit = false;
	cout << "Adding sales... Press 0 and then Enter at any point to stop adding sales.\n";

	//Loop that adds user given string to the string vector and a double to the double vector.
	while (!exit) {
		cout << "Please enter the name of the item: ";
		//itemN will hold the string value, the name of the item.
		string itemN;
		//Getline is used in case user enters an item name that requires spaces.
		getline(cin, itemN);
		//When the user enters 0, break out of loop and back to main menu.
		if (itemN == "0") {
			exit = true;
			break;
		}
		//If input is valid, push input onto vector
		name.push_back(itemN);


		cout << "Please enter the price of the item: ";
		//itemP will hold the double value, 'price' of the item.
		double itemP;
		cin >> itemP;
		cin.ignore();
		//If user decides to quit after inputting a value into the name vector,
		//that value will be popped back out so both vectors have corresponding
		//values and program will break out of loop and back to main menu.
		if (itemP == 0) {
			name.pop_back();
			exit = true;
			break;
		}
		//If input is valid, push input onto vector.
		price.push_back(itemP);
	}
}

//Function that displays all values in two columns.
void viewSales(vector<string> name, vector<double> price) {
	//If there are no items in either vector, program will not print out table.
	if (name.size() == 0 || price.size() == 0) {
		cout << "\nError: No items in current list.\n";
	} else {
		//Prints out display .
		cout << fixed << setprecision(2);
		cout << "Item Name	       Item Price";
		cout << "\n---------------------------------\n";
		//Prints out information.
		for (int i = 0; i < name.size() && i < price.size(); i++) {
			cout << left
				<< (i + 1) << "."
				<< setw(12) << name[i]
				<< right
				<< setw(10) << "$"
				<< setw(0) << price[i] << endl;
		}
		cout << endl;
	}
}

//Function that allows user to edit one item's price.
void editSales(vector<double> &price) {
	//If there is no item, program will not allow editting.
	if (price.size() == 0) {
		cout << "\nError: No items in current list.\n";
	} else {
		cout << "Please enter the number of the item you want to edit: ";
		//Index value holds element index of vector.
		int index;
		double input;
		//Input value holds the new number that the user wants to change to.
		cin >> index;
		cin.ignore();
		//Index size that is not within actual vector size is rejected.
		if (index > price.size()) {
			cout << "\nInvalid number\n";
		} else {
			//If index value is valid, user is asked for new double value for item's price.
			cout << "Please enter the new price of this item: ";
			cin >> input;
			cin.ignore();
			//Loops through vector given the desired index and replaces old value with new value.
			for (int i = 0; i < price.size(); i++) {
				if (i == (index - 1)) {
					price[i] = input;
				}
			}
		}
	}
}

//Function that removes the same index element from both vectors.
void removeSales(vector<string> &name, vector<double> &price) {
	//If there are no items in either vector, there is nothing to remove.
	if (name.size() == 0 || price.size() == 0) {
		cout << "\nError: No items in current list.\n";
	} else {
		cout << "Please enter the number of the item you want to remove: ";
		//Index value holds element index of vector.
		int index;
		cin >> index;
		cin.ignore();
		//Index size that is not within actual vector size is rejected.
		if (index > name.size() && index > price.size()) {
			cout << "\nInvalid number\n";
		}
		else {
			//Erases desired element in the vector.
			name.erase(name.begin() + (index - 1));
			price.erase(price.begin() + (index - 1));
		}
	}
}

//Function that prints out a menu and returns an integer chosen by user.
int mainMenu() {
	//Option is -1 instead of 0 to avoid exitting program by default.
	int option = -1;
	cout << "\nMain Menu\n"
		 << "  0. Exit Program\n"
		 << "  1. Add a sale\n"
		 << "  2. Remove a sale\n"
		 << "  3. Edit a sale\n"
		 << "  4. View all sales\n";
	while (true) {
		cin >> option;
		//User input has to be between 0 and 4 in order to continue
		if (option >= 0 && option <= 4)
			break;
		else
			cout << "Invalid input, please try again: ";
	}
	return option;
}
