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

//Base class account
class Account {
	private:
		double balance;
		int numberOfDeposits;
		int numberOfWithdrawals;
		double annualInterestRate;
		double monthlyFee;
		double monthlyServiceCharges;
	public:
		Account() {};
		Account(double bal, double rate);

		double getBalance() const;
		int getNumberOfDeposits() const;
		int getNumberOfWithdrawals() const;
		double getAnnualInterestRate() const;
		double getMonthlyServiceCharges() const;

		void setBalance(double bal);
		void setMonthlyServiceCharges(double charges);
		virtual void deposit(double depAmount);
		virtual void withdrawal(double withAmount);

		void calcInt();
		virtual void monthlyProc();
};
