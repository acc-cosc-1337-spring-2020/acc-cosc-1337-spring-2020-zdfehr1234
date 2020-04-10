//customer.h
#ifndef CUSTOMER_H //Header guards
#define CUSTOMER_H //Dont forget to put this or you will get strange errors.
#include<vector>
#include<memory>
#include<iostream>
#include"bank_account.h"

class Customer
{
public: 

	void add_account(std::unique_ptr<BankAccount>& act);
	friend std::ostream& operator<<(std::ostream& out, const Customer& c);
private:
	std::vector<std::unique_ptr<BankAccount>> accounts;
};
#endif // !CUSTOMER_H
