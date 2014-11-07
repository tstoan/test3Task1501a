//
//  TypeConversion.c
//  C examples
//
//  Created by Ulrik on 2013-10-17.
//
//

#include <stdio.h>

int main(void)
{
    int i,j;
    
    float result;
    
    for(i=0; i<20; i++)
    {
        result = (i/3);	                    /* Example of implicit conversion in C */
        printf("%d/3=\t%f\n", i, result);
    }  
}