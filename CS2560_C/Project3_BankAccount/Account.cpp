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
#include "Account.h"

//Constructor for account
Account::Account(double bal, double rate) {
	balance = bal;
	annualInterestRate = rate;
	numberOfDeposits = 0;
	numberOfWithdrawals = 0;
	monthlyFee = 0;
	monthlyServiceCharges = 0;
}

//Returns account balance
double Account::getBalance() const {
	return balance;
}

//Returns number of deposits per month
int Account::getNumberOfDeposits() const {
	return numberOfDeposits;
}

//Returns number of withdrawals per month
int Account::getNumberOfWithdrawals() const {
	return numberOfWithdrawals;
}

//Returns annual interest rate
double Account::getAnnualInterestRate() const {
	return annualInterestRate;
}

//Returns service charges per month
double Account::getMonthlyServiceCharges() const {
	return monthlyServiceCharges;
}

//Sets account balance
void Account::setBalance(double bal) {
	balance = bal;
}

//Adds charges to current monthly charges
void Account::setMonthlyServiceCharges(double charges) {
	monthlyServiceCharges += charges;
}

//Adds deposit amount from balance and increments number of deposits
void Account::deposit(double depAmount) {
	balance += depAmount;
	numberOfDeposits += 1;
}

//Subtracts withdrawal amount from balance and increments number of withdrawals
void Account::withdrawal(double withAmount) {
	balance -= withAmount;
	numberOfWithdrawals += 1;
}

//Calculates interest
void Account::calcInt() {
	double monthlyRate, monthlyInterest;
	//12 months in a year
	monthlyRate = (getAnnualInterestRate() / 12);
	//balance * monthlyRate gets the interest amount
	monthlyInterest = balance * monthlyRate;
	//Adds interest to balance
	balance += monthlyInterest;
}

//Calculates monthly charges
void Account::monthlyProc() {
	//Subtracts monthly charges from balance
	balance -= monthlyServiceCharges;
	//Calculates interest from new balance
	calcInt();
	//Resets all counters to 0
	numberOfDeposits = numberOfWithdrawals = monthlyServiceCharges = 0;
}
