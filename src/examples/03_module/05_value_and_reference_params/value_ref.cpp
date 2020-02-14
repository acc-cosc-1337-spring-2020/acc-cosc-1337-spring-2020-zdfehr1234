#include "value_ref.h"

/*
Write function code for pass_by_val_and_ref with
a value int num1 and ref int num2 parameter.
The function assigns 20 to num1 and 50 to num2
*/
void pass_by_val_and_ref(int num1, int & num2)
{
	num1 = 20;
	num2 = 50;
}



/*
Write function prototype for pass_by_const_ref with
const int reference parameter num1.
Try to assign a value to num1, generates error.
*/

void pass_by_const_ref(const int & num)
{
	//num = 0; const reference parameters can't be modified
}

