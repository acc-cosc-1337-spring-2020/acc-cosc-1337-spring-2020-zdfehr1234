#include "ref_pointers.h"
#include<iostream>

using std::cout;

int main() 
{
	// Create two stack variables 
	int r = 0, p = 0;

	//Create a refrence to r
	int& ref_r = r;

	//Display the result to verify
	cout << "Address of r: " << &r << "\t";
	cout << "Value of r: " << r << "\n";
	cout << "Address of ref_r: " << &ref_r << "\n\n";

	//Create a pointer to p
	int* ptr_p = &p;

	//Display the result to verify
	cout << "Address of p: " << &p << "\n";
	cout << "Value of p: " << p << "\n";
	cout << "Address of ptr_p: " << &ptr_p << "\n\n";

	cout << "Contents (address) of ptr_p: " << ptr_p << "\n";
	cout << "Value ptr_p points to: " << *ptr_p << "\n";

	
	return 0;
}