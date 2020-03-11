//checking_account.h
#include "bank_account.h"

class CheckingAccount : public BankAccount
{
public: 
	CheckingAccount() = default; // sets a default value 
	explicit CheckingAccount(int b) : BankAccount(b) {} // allows a value to be passed in (Explicit does not allow setting the paramater equal to something ex bank = 5)
	int get_balance()const { return balance * (1 + get_rate()); }
};