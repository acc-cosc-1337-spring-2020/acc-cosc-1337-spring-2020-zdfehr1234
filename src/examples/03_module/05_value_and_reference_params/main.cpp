#include<iostream>

using std::cout;

int main() 
{
	int num = 5;
	cout << "Value of: " << num << " Address is: " << &num << "\n";

	int &num_ref = num;
	num_ref = 10;
	cout << "Value of: " << num << " Address is: " << &num<<"\n";


	return 0;
}