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
#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>
#include <new>

using namespace std;

//Saving Account's constructor calls base class' (account) constructor
SavingsAccount::SavingsAccount(double bal, double rate) {
	new (this) Account(bal, rate);
	//If balance is greater than $25, account is active
	if (bal >= 25) {
		active = true;
	}
	//If balance is less than $25, account is inactive
	else if (bal < 25) {
		active = false;
	}
}

//Virtual deposit function
void SavingsAccount::deposit(double depAmount) {
	deposit(depAmount);
	//Once new balance is calculated, account will be made active if balance is >= 25
	if (getBalance() >= 25) {
		active = true;
	}
	//Account will be inactive is balance is < 25
	else if (getBalance() < 25) {
		active = false;
	}
}

//Virtual withdrawal function
void SavingsAccount::withdrawal(double withAmount) {
	//Checks if account is active or inactive before withdrawing from account
	if (getBalance() >= 25) {
		active = true;
	}
	else if (getBalance() < 25) {
		active = false;
	}
	if (active)
		withdrawal(withAmount);
}

//Virtual monthlyproc function
void SavingsAccount::monthlyProc() {
	//Needs more than 3 withdrawals
	if (getNumberOfWithdrawals() > 3) {
		//Every withdrawal greater than 3 will add $1 per withdrawal
		for (int i = 3; i < getNumberOfWithdrawals(); i++) {
			setMonthlyServiceCharges(1);
		}
	}
	//Calls monthlyproc
	monthlyProc();
}

//Returns whether or not account is active
bool SavingsAccount::isActive() const {
	return active;
}
