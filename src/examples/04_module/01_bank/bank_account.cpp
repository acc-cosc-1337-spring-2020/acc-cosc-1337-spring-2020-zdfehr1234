#include "bank_account.h"


//bank_account.cpp

void BankAccount::deposit(int amount)
{
	if (amount > 0)
	{
		balance += amount; 
	}
	else
	{
		throw Invalid("Amount must be greater than 0.");
	}
}

void BankAccount::withdraw(int amount)
{
	if (amount < 0)
	{
		throw Invalid("Amount must be greater than 0.");
	}
	else if (amount > balance)
	{
		throw Invalid("Insufficent Funds.");
	}
	else
	{
		balance -= amount;
	}
}

void BankAccount::open(int amount)
{
	if (min_opening_balance > amount)
	{
		throw Invalid("Amount must be at least 25...");
	}
	
	balance += amount;
}

double BankAccount::rate = init_rate();

void display_balance(const BankAccount & b)
{
	cout << "Balance is: " << b.balance;
}

std::ostream & operator<<(std::ostream & out, const BankAccount & b)
{
	out << "Balance is: " << b.balance;

	return out;
}

std::istream & operator>>(std::istream & in, BankAccount & b)
{
	int amount;
	cout << "Enter amount: ";
	in >> amount;
	b.deposit(amount);
	
	return in;
}
