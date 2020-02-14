//write includes statements
#include "loops.h"
#include<iostream>


//write using statements for cin and cout
using std::cin; using std::cout;



/*
Use a do while loop to prompt the user for 
a number, call the factorial function, and display the number's
factorial.  Also, loop continues as long as user wants to.
*/
int main() 
{
	auto choice = 'r';
	do
	{
		int num;
		cout << "\nEnter a number: ";
		cin >> num;
		cout << factorial(num) << "\n\n";

		cout << "Continue? (y or n)";
		cin >> choice;

	} while (choice == 'y');

	return 0;
}