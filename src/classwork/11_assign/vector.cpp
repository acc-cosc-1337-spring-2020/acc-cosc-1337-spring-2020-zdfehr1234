#include "vector.h"

/*
	Initalize nums to size dynamic array
	Initalize each array element to zero
*/

Vector::Vector(size_t sz)
	:size {sz}, nums{new int[sz]}
{
	for (size_t i = 0; i < sz; ++i)
	{
		nums[i] = 0;
	}
}

/*
	Copy v.size to new class
	Create new dynamic memory array 
	Initalize aray elements to the v.nums array values
*/
Vector::Vector(const Vector & v)
	:size{ v.size }, nums{ new int[v.size] }
{
	for (size_t i = 0; i < size; ++i)
	{
		nums[i] = v[i];
	}
}