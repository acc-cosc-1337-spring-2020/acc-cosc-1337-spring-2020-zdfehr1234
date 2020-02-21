#include "dna.h"


/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/
double get_gc_content(const string &dna)
{
	int i = 0;
	double count = 0;
	double length = dna.length();
	double result = 0.0;

	while (i<length)
	{
		if (dna[i] == 'G')
		{
			count += 1;
		}
		if (dna[i] == 'C')
		{
			count += 1;
		}
		i += 1;
		
	}
	result = count / length;
	return result;
}



/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/
string get_reverse_string(string dna)
{
	int i = dna.length();
	string dna_reverse ;
	while (i > 0)
	{
		dna_reverse += dna[i-1];
		i -= 1;
	}
	return dna_reverse;
}


/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string

*/


string get_dna_complement(string dna)
{
	string complement;
	int len = dna.length();
	int i = 0;

	complement = get_reverse_string(dna);
	while (i < len)
	{
		if (complement[i] == 'A')
		{
			complement[i] = 'T';
		}else if (complement[i] == 'T')
		{
			complement[i] = 'A';
		}else if  (complement[i] == 'C')
		{
			complement[i] = 'G';
		}else if (complement[i] == 'G')
		{
			complement[i] = 'C';
		}
		i += 1;
	}

	return complement;
}
