#include <iostream>
#include <string>

using std::cout;

//bank_account.h
class BankAccount
{
public:
	BankAccount() = default; //Default constructor ex. used for new accounts (can also be written BankAccount() {})
	explicit BankAccount(int b) : balance{ b } {} //Used for accounts with an existing balance
	int get_balance()const { return balance; }
	void deposit(int amount);
	void withdraw(int amount);
	void open(int amount);
	double get_rate() { return rate; }
	friend void display_balance(const BankAccount& b); //by using the friend keyword it is not part of the class so it can be accessed elsewhere with the class variables.
	friend std::ostream& operator<<(std::ostream & out, const BankAccount& b); // Used to cout in main without calling class
	friend std::istream& operator>>(std::istream& in, BankAccount& b); //Used to cin in main without calling class
private:
	int balance{ 0 }; //Set balance = 0 for deafult value. (Will be overwritten if another value is sent in)
	const int min_opening_balance{ 25 };
	static double rate; //Cannot give value inside class
	static double init_rate() { return .025; }
};


class Invalid
{
public:
	Invalid(std::string msg) : message{ msg } {}
	std::string get_error()const { return message; }

private:
	std::string message;
};