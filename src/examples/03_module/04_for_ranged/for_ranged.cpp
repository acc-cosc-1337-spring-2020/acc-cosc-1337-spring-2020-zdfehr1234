//#include "sample_for_ranged.h"
#include<iostream>
#include<vector>
#include "for_ranged.h"

using std::vector;

/*
Write code for loop_string_w_index that accepts a string parameter.
The function uses an indexed for loop to iterate and display the characters in the
string as follows:
for string test displays

t
e
s
t
*/
void loop_string_w_index(const std::string & str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		std::cout << str[i] << "\n";
	}
}



/*
Write code for loop_string_w_index that accepts a string parameter.
The function uses a for ranged loop using auto to iterate and display the characters in the
string as follows:
for string test displays

t
e
s
t
*/

void loop_string_w_auto(const std::string &str)
{
	for (auto ch : str)
	{
		std::cout << ch << "\n";

	}
}


void loop_vector_w_index() 
{
	vector<int> nums = {9, 10, 99, 5,67 };

	for (int i = 0; i < nums.size(); ++i) 
	{
		std::cout << nums[i] << "\n";
	}
}

