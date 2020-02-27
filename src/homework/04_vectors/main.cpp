#include <iostream>
#include "vectors.h"

using std::cout; using std::cin;

/*
use a vector of int with values 8, 4, 20, 88, 66, 99

Prompt user for 1 for Get Max from vector and 2 for Get primes.
Prompt user for a number and return max value or list of primes
and display them to screen.
Program continues until user decides to exit.

*/
int main() 
{
	vector<int> val{ 8, 4, 20, 88, 66, 99 };
	auto cont{ 'y' };
	auto choice{ 1 };

	do
	{
		cout << "Press 1 to get max vector, or press 2 to get prime numbers: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << get_max_from_vector(val) << "\n";
		}
		else if (choice == 2)
		{
			auto num{ 0 };
			vector<int> result{ 0 };
			cout << "Please enter a number: ";
			cin >> num;

			result = vector_of_primes(num);

			for (int i = 0; i < result.size(); i++)
			{
				cout << result[i] << " ";
			}
			cout << "\n";
		}
		else
		{
			cout << "Please enter a 1 or 2. ";
		}

		cout << "Continue (y/n)? ";
		cin >> cont;

	} while (cont == 'y' || cont == 'Y');

	return 0;
}