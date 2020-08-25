/*
 * Name: Steven Phung
 * Project: #3
 * Due: December 14th, 2018
 * Course: cs-2560-01-f18
 *
 * Description:
 * 	A bank account program that is implemented using concepts such as
 * 	inheritance, polymorphism, and virtual functions.
 *
 */
#include <string>
#include <iostream>
#include <iomanip>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "Account.h"

using namespace std;

//Prints menu
int menu();

int main2() {
	//Cannot have more than 1 million start value
	double const MAX_AMOUNT = 1000000.00;
	//Cannot have more than 100% interest rate
	double const MAX_RATE = 100.00;
	//Get user input for each value
	string saveBalance, saveRate, checkBalance, checkRate;
	//Amount to be deposited / withdrawn
	double amount;
	//Bool to quit loops
	bool loop, quit = false;


	cout << "Welcome:" << endl;
	cout << "------------------------------------------------------------------------" << endl;

	//Asks user for starting balance for savings account, loop until input is correct
	do {
		loop = true;
		try {
			cout << "\tPlease enter the starting balance for your savings account: " << endl;
			getline(cin, saveBalance);
			//Starting balance must be between 0 and 1 million
			if (stod(saveBalance) > 0 && stod(saveBalance) < MAX_AMOUNT) {
				loop = false;
			}
			else if (stod(saveBalance) < 0) {
				cout << "Cannot start with negative balance." << endl;
			}
			else if (stod(saveBalance) > MAX_AMOUNT) {
				cout << "Start balance too high." << endl;
			}
		}
		//Catches invalid arguements when user inputs characters that cannot be converted
		catch (invalid_argument e) {
			cout << endl << "Invalid input" << endl << endl;
		}
	} while (loop);

	//Asks user for annual interest for savings account, loop until input is correct
	do {
		loop = true;
		try {
			cout << "\tPlease enter the annual interest rate for your savings account: " << endl;
			getline(cin, saveRate);
			//Annual interest cannot be negative or over 100
			if (stod(saveRate) > 0 && stod(saveRate) < MAX_RATE) {
				loop = false;
			}
			else if (stod(saveRate) < 0) {
				cout << "Cannot have negative interest rate." << endl;
			}
			else if (stod(saveRate) > MAX_RATE) {
				cout << "Rate is too high." << endl;
			}
		}
		//Catches invalid arguements when user inputs characters that cannot be converted
		catch (invalid_argument e) {
			cout << endl << "Invalid input" << endl << endl;
		}
	} while (loop);

	//Creates a saving account with the given information
	SavingsAccount savingAcc(stod(saveBalance), stod(saveRate));

	//Asks user for starting balance for checking account, loop until input is correct
	do {
		loop = true;
		try {
			cout << "\tPlease enter the starting balance for your checking accoung: " << endl;
			getline(cin, checkBalance);
			//Starting balance must be between 0 and 1 million
			if (stod(checkBalance) > 0 && stod(checkBalance) < MAX_AMOUNT) {
				loop = false;
			}
			else if (stod(checkBalance) < 0) {
				cout << "Cannot start with negative balance." << endl;
			}
			else if (stod(checkBalance) > MAX_AMOUNT) {
				cout << "Start balance too high." << endl;
			}
		}
		//Catches invalid arguements when user inputs characters that cannot be converted
		catch (invalid_argument e) {
			cout << endl << "Invalid input" << endl << endl;
		}
	} while (loop);

	//Asks user for annual interest for checking account, loop until input is correct
	do {
		loop = true;
		try {
			cout << "\tPlease enter the annual interest rate for your checking account: " << endl;
			getline(cin, checkRate);
			//Annual interest cannot be negative or over 100
			if (stod(checkRate) > 0 && stod(checkRate) < MAX_RATE) {
				loop = false;
			}
			else if (stod(checkRate) < 0) {
				cout << "Cannot have negative interest rate." << endl;
			}
			else if (stod(checkRate) > MAX_RATE) {
				cout << "Rate is too high." << endl;
			}
		}
		//Catches invalid arguements when user inputs characters that cannot be converted
		catch (invalid_argument e) {
			cout << endl << "Invalid input" << endl << endl;
		}
	} while (loop);

	//Creates a checking account with the given information
	CheckingAccount checkingAcc(stod(checkBalance), stod(checkRate));

	while (!quit) {
		int option = menu();
		cin.ignore();
		switch (option) {
			//Make a deposit to savings
			case 1:
				cout << "How much will you deposit into your savings account? " << endl;
				cin >> amount;
				cin.ignore();
				savingAcc.deposit(amount);
				break;
			//Make a deposit to checkings
			case 2:
				cout << "How much will you deposit into your checking account? " << endl;
				cin >> amount;
				cin.ignore();
				checkingAcc.deposit(amount);
				break;
			//Make a withdrawal from savings
			case 3:
				if (savingAcc.getBalance() > 25 && savingAcc.isActive()) {
					cout << "How much are you withdrawing from your savings account? " << endl;
					cin >> amount;
					cin.ignore();
					if ((savingAcc.getBalance() - amount) > 0) {
						savingAcc.withdrawal(amount);
					}
					else {
						cout << "Cannot withdraw, will cause negative balance. \n$" << savingAcc.getBalance() << " is your current savings balance." << endl;
					}
				}
				else {
					cout << "Inactive account, not enough balance. \n$" << savingAcc.getBalance() << " is your current savings balance." << endl;
				}
				break;
			//Make a withdrawal from checkings
			case 4:
				if (checkingAcc.getBalance() > 0) {
					cout << "How much are you withdrawing from your checking account? " << endl;
					cin >> amount;
					cin.ignore();
					checkingAcc.withdrawal(amount);
				}
				else {
					cout << "Cannot withdraw, negative balance. \n$" << checkingAcc.getBalance() << " is your current checkings balance." << endl;
				}
				break;
			//View the balance of either
			case 5:
				cout << setprecision(2) << fixed;
				cout << "Savings Balance: $" << savingAcc.getBalance() << endl;
				cout << "Checkings Balance: $" << checkingAcc.getBalance() << endl << endl;
				break;
			//Indicate that a month has passed (i.e. call the monthlyProc function on each account)
			case 6:
				savingAcc.monthlyProc();
				checkingAcc.monthlyProc();
				cout << "...\tA month has passed\t..." << endl;
				break;
			//Quit
			case 0:
				quit = true;
				break;
			//Invalid input
			default:
				cout << "Invalid input, please try again" << endl;
				break;
		}
	}
	return 0;
}

int menu() {
	int option = -1;
	cout << endl << "Main Menu" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "\t0. Quit" << endl;
	cout << "\t1. Make a deposit to your savings account" << endl;
	cout << "\t2. Make a deposit to your checkings account" << endl;
	cout << "\t3. Make a withdrawal from your savings account" << endl;
	cout << "\t4. Make a withdrawal from your checkings account" << endl;
	cout << "\t5. View balance for both accounts" << endl;
	cout << "\t6. Fast forward a month" << endl;
	cout << "------------------------------------------------------" << endl << endl;
	while (true) {
		//Input must be between 0 and 6
		cin >> option;
		if (option >= 0 && option <= 6) {
			break;
		}
		else {
			cout << "Invalid input, please try again" << endl;
		}
	}
	return option;
}
