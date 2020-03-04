#include <string>

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
private:
	int balance{ 0 }; //Set balance = 0 for deafult value. (Will be overwritten if another value is sent in)
	const int min_opening_balance{ 25 };
};


class Invalid
{
public:
	Invalid(std::string msg) : message{ msg } {}
	std::string get_error()const { return message; }

private:
	std::string message;
};