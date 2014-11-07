//
//  OutOfBounds.c
//  C examples
//
//  Created by Ulrik on 2013-10-17.
//
//

#include <stdio.h>

int main(void)
{
    int i;
    int squares_of_int[10];
    
    for(i=0; i<20; i++)	/* intentional indexing of an array beyond initial definition */
    {
        squares_of_int[i] = i*i;
        printf("%d\t%d\n", i, squares_of_int[i]);
    }
    
}
