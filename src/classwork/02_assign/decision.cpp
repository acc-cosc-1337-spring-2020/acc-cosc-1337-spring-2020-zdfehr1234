#include "decision.h"
//Write the function code that returns the product of hours and hourly_rate.


double gross_pay(double hourly_rate, double hours)
{
	if (hours <= 40)
	{
		return (hourly_rate*hours);
	}
	else if (hours > 40)
	{
		return  ((40 * hourly_rate) + ((hours - 40)*(hourly_rate*1.5)));
	}
}
