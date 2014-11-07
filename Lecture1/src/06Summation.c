// Ulrik
// 2013-11-11

#include "06Summation.h"

int sum_of_array(int array[10], int length)
{
	int i;
	int sum=0;
	
	for(i=0; i<length; i++)
    {
        sum = sum+array[i];
    }
    return sum;
}