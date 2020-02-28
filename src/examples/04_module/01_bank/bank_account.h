#include <string>

//bank_account.h
class BankAccount
{
public:
	BankAccount(int b) : balance{ b } {}
	int get_balance()const { return balance; }
	void deposit(int amount);
	void withdraw(int amount);
private:
	int balance{ 0 };
};


class Invalid
{
public:
	Invalid(std::string msg) : message{ msg } {}
	std::string get_error()const { return message; }

private:
	std::string message;
};