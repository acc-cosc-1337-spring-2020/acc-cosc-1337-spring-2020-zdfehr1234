//write include statements
# include <iostream>
# include "dna.h"

//write using statements
using std::cout; 
using std::cin;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	int c = 0;
	auto choice = 1;
	auto choice2 = 'a';
	string result;
	string dna;
	do
	{
		cout << "Please enter 1 for Get GC Content or 2 for Get DNA Complement: ";
		cin >> choice;
		
		if (choice == 1)
		{
			cout << "Please enter DNA string: ";
			cin >> dna;
			cout << get_gc_content(dna) << "\n";
		}
		else if (choice == 2)
		{
			cout << "Please enter DNA string: ";
			cin >> dna;
			cout << get_dna_complement(dna) << "\n";
		}
		else
		{
			cout << "Please enter a 1 or 2.";
		}
		cout << "Continue (y/n)?";
		cin >> choice2;
	} while (choice2 == 'Y' || choice2 == 'y');
	

	
	return 0;
}