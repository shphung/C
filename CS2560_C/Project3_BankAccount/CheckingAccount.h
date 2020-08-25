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
#pragma once
#include "Account.h"

//CheckingAccount is derived from Account
class CheckingAccount : public Account {
	public:
		CheckingAccount(double bal, double rate);
		void withdrawal(double withAmount);
		void deposit(double depAmount);
		void monthlyProc();
};
