#include "memory_leak.h"

void memory_leak()
{
	int* ptr_num = new int(5);
	//other code 
	//forget to delete code
}
