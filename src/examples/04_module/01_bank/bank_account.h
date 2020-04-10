#include <iostream>
#include <string>

#ifndef BANK_ACCOUNT_H //Header Guard
#define BANK_ACCOUNT_H

using std::cout;

//bank_account.h
class BankAccount
{
public:
	BankAccount() = default; //Default constructor ex. used for new accounts (can also be written BankAccount() {})
	explicit BankAccount(int b) : balance{ b } {} //Used for accounts with an existing balance
	virtual int get_balance()const = 0;
	void deposit(int amount);
	void withdraw(int amount);
	void open(int amount);
	double get_rate() const { return rate; }
	friend void display_balance(const BankAccount& b); //by using the friend keyword it is not part of the class so it can be accessed elsewhere with the class variables.
	friend std::ostream& operator<<(std::ostream & out, const BankAccount& b); // Used to cout in main without calling class
	friend std::istream& operator>>(std::istream& in, BankAccount& b); //Used to cin in main without calling class

protected: //Allows variables to be accessed by other classes but not in main. (Such as in the savings account class)
	int balance{ 0 }; //Set balance = 0 for deafult value. (Will be overwritten if another value is sent in)

private:
	const int min_balance_to_open{ 25 };
	static double rate; //Cannot give value inside class
	static double init_rate() { return .025; }
};

#endif


#ifndef INVALID_H
#define INVALID_H
class Invalid
{
public:
	Invalid(std::string msg) : message{ msg } {}
	std::string get_error()const { return message; }

private:
	std::string message;
};

#endif