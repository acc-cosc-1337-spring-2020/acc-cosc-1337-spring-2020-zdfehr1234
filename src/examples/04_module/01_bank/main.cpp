#include "bank_account.h"
#include "checking_account.h"
#include "savings_account.h"
#include <iostream>
#include <vector>
#include <memory>


using std::cout; using std::cin; using std::vector;
using std::unique_ptr; using std::make_unique;

int main()
{
	unique_ptr<BankAccount> s = make_unique<SavingsAccount>(90); //Creates dynamic memory behind the scenes (smart pointer)
	unique_ptr<BankAccount> c = make_unique<CheckingAccount>(100);

	
	std::vector<unique_ptr<BankAccount>> account; //Creates a list of bank account vectors
	account.push_back(std::move(s));
	account.push_back(std::move(c));

	for (auto& act : account)
	{
		cout << act->get_balance() << "\n";
	}

	/*

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

	*/

	return 0;
}