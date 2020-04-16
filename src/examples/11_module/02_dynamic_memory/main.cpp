#include <iostream>

using std::cout;


int main() 
{
	int* ptr_num = new int(5);

	cout << "Address of ptr_num: " << &ptr_num << "\n";//stack address
	cout << "Address ptr_num points to: " << ptr_num << "\n"; //Heap address
	cout << "Value at address ptr_num points to: " << *ptr_num << "\n"; //Actual value

	delete ptr_num;
	ptr_num = nullptr;


	return 0;
}