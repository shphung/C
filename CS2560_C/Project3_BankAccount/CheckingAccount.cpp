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
#include "CheckingAccount.h"
#include <new>

//CheckingAccount's constructor calls base class' (account) constructor
CheckingAccount::CheckingAccount(double bal, double rate) {
	new (this) Account(bal, rate);
}

//Virtual withdraw function
void CheckingAccount::withdrawal(double withAmount) {
	double balance, total, newBalance;
	balance = getBalance();
	total = balance - withAmount;
	//If withdrawal amount is greater than balance, there is a $15 charge
	if (total < 0) {
		double charges = 15;
		newBalance = balance - charges;
		setBalance(newBalance);
	}
	else if (total > 0) {
		withdrawal(withAmount);
	}
}

//Virtual deposit function
void CheckingAccount::deposit(double depAmount) {
	deposit(depAmount);
}

//Virtual monthlyproc function
void CheckingAccount::monthlyProc() {
	setMonthlyServiceCharges(5);
	if (getNumberOfWithdrawals() > 0) {
		for (int i = 1; i < getNumberOfWithdrawals(); i++) {
			setMonthlyServiceCharges(0.10);
		}
	}
	monthlyProc();
}
