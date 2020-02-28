#include "bank_account.h"
#include <iostream>

using std::cout; using std::cin;

int main()
{
	BankAccount account(500); 

	auto balance = account.get_balance();
	cout << "Balance is : " << balance << "\n";

	auto amount{ 0 };
	cout << "Enter deposit amount: ";
	cin >> amount;

	try 
	{
		account.deposit(amount);
		cout << "Balance is: " << account.get_balance();
	}
	catch (Invalid e)
	{
		cout << e.get_error() << "\n";
	}

	return 0;
}