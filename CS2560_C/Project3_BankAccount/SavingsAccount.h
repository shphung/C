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

//SavingsAccount is derived from Account
class SavingsAccount : public Account {
	private:
		bool active;
	public:
		SavingsAccount(double bal, double rate);
		void deposit(double depAmount);
		void withdrawal(double withAmount);
		void monthlyProc();
		bool isActive() const;
};
