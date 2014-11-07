//
//  UsingFunctions.c
//  C examples
//
//  Created by Ulrik on 2013-10-31.
//
//

#include <stdio.h>
#include "06Summation.h"




int main(void)
{
    int i;
    const int length=5;
    int array_of_ints[10];
 
    for(i=0; i<length; i++)
    {
        array_of_ints[i] = i+1;
    }
     
    printf("Sum of the first %d integers is %d\n", 
    length, sum_of_array(array_of_ints, length));
}





