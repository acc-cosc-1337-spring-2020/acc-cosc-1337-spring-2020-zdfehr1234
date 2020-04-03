//savings_account.h
#include "bank_account.h"

class SavingsAccount : public BankAccount 
{
public:
	SavingsAccount() = default; 
	explicit SavingsAccount(int b) : BankAccount(b) {} // explicit is used to not allow SavingsAccount s1 = 1000; (That is the incorect syntax)
	int get_balance()const { return 5000; }

};