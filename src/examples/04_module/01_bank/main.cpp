#include "checking_account.h"
#include "savings_account.h"
#include "customer.h"
#include "atm.h"
#include<iostream>
#include<vector>
#include<string>
#include<memory>

using std::cout; using std::cin;
using std::unique_ptr; using std::make_unique;

int main()
{
	


	//c++ 11
	unique_ptr<BankAccount> s = make_unique<SavingsAccount>(90); //heap variable or a pointer to data on the heap
	unique_ptr<BankAccount> c = make_unique<CheckingAccount>(100);

	

	Customer cust; 
	cust.add_account(s);
	cust.add_account(c);

	ATM atm(cust);
	cout << atm;

	

	/*
	cin >> account;
	cout << account;
	display_balance(account);
	auto balance = account.get_balance();
	cout << "Balance is: \n" << balance;
	auto amount{ 0 };
	cout << "\nEnter deposit amount: \n";
	cin >> amount;

	try
	{
		account.deposit(amount);
		cout << "Balance is: " << account.get_balance();
	}
	catch (Invalid e)
	{
		cout << e.get_error()<<"\n";
	}*/

	return 0;
}