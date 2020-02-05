#include<iostream>
#include "if.h"//to use is_even function here

using std::cout; // Outputs to screen 
using std::cin; // Used to capture keyboard

int main() 
{
	//create a bool variable named even
	bool even = false;
	//create an int variable named value
	int value;
	//prompt user for a keyboard number
	cout << "Type a number: ";
	//assign the number to the value variable
	cin >> value;
	//call the is_even function with value as its argument
	//and assign its return value to the even variable
	even == is_even(value);

	

	//display even if number is even
	if (even == true)
	{
		cout << value << "is even.";
	}
	else
	{
		cout << value << "is odd.";
	}
	return 0;
}
