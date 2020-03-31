#include "bank_account.h"
#include "checking_account.h"
#include <iostream>
#include <vector>


using std::cout; using std::cin; using std::vector;

int main()
{
	CheckingAccount checking;
	CheckingAccount checking1(90);

	std::vector<BankAccount> accounts{ BankAccount(100), BankAccount(200) }; //Creates a list of bank account vectors

	for (auto act : accounts)
	{
		cout << act.get_balance() << "\n";
	}
	
	


	BankAccount account1(500);
	cin >> account1; 
	cout << account1;
	display_balance(account1);





	//BankAccount a = 100; Does not work since in the bank_account.h file we added explicit in line 8.
	BankAccount a (100); // Only allowed syntax for creating an account with balance. 
	cout << a.get_balance();

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