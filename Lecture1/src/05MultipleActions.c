//
//  MultipleActions.c
//  TeachingAid
//
//  Created by Ulrik on 2013-10-17.
//
//

#include <stdio.h>

int main(void)
{
    int x,y;
   
    x = 7;
    y = (x = 2*x);	/* shows that multiple assignments are possible in the same statement */
    printf("x = %d\ty = %d\n", x, y);
    
    x = 7;
    x = 2*x;
    y = x;
    printf("x = %d\tY = %d\n", x, y);
    
}