#include "for_ranged.h"
#include<iostream>
#include<vector>
#include "vec.h"

using std::vector;
using std::cout;

/*
Write code for function loop_vector_w_index with no parameters.
The function creates an int vector with values 9, 10, 99, 5, 67
and displays the numbers to screen using an indexed for loop as follows: 9 10 99 5  67
*/



/*
Write code for function loop_vector_w_index with a vector of int pass by value parameter.
The function creates an int vector with values 9, 10, 99, 5, 67
and displays the numbers to screen using an indexed for loop as follows: 9 10 99 5  67
*/

void loop_vector_w_index(vector<int> nums)
{
	for (int i = 0; i < nums.size(); ++i)
	{
		cout << nums[i] << "\n";
	}
}


/*
Write code for function loop_vector_w_index with a vector of int pass by reference parameter.
The function creates an int vector with values 9, 10, 99, 5, 67
and displays the numbers to screen using an indexed for loop as follows : 9 10 99 5  67
*/

void loop_vector_w_index_ref(vector<int> &nums)
{
	for (int i = 0; i < nums.size(); ++i)
	{
		cout << nums[i] << "\n";
	}
}



/*
Write code for function loop_vector_w_index with a vector of int const pass by reference parameter.
The function creates an int vector with values 9, 10, 99, 5, 67
and displays the numbers to screen using an indexed for loop as follows : 9 10 99 5  67
*/

void loop_vector_w_index_ref_const(const vector<int> &nums)
{
	for (int i = 0; i < nums.size(); ++i)
	{
		cout << nums[i] << "\n";
	}
}

void loop_vector_w_auto(vector<int> &nums)
{
	for (auto i : nums)
	{
		i = 0;
	}
}

void loop_vector_w_auto_ref(vector<int> &nums)
{
	for (auto &i : nums)
	{
		i = 0;
	}
}

void loop_vector_w_auto_ref_const(const vector<int> &nums)
{

}
