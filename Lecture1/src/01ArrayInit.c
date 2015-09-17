//
//  ArrayInit.c
//  C examples
//
//  Created by Ulrik on 2013-10-31.
//
//

#include <stdio.h>

int main(void)
{
    int i;	/* i is ALWAYS used as a loop and/or index variable */
    int squares_of_int[10];
    
    for(i=0; i<10; i++)	/* Array indeces (and everything else) always start at 0 in C */
    {
    	printf("%d\t%d\n", i, squares_of_int[i]);
    }
}
