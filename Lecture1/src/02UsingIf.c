//
//  comparison.c
//  TeachingAid
//
//  Created by Ulrik on 2013-10-31.
//
//

#include <stdio.h>

int main(void)
{
    int x,y;
    
    x = 7;
    y = 12;
    printf("x = %d\ty = %d\n", x, y);
           
    printf("Comparison: ");
    if (x==y)
    {
    	printf("%d = %d\n", x, y);
    }
    else
    {
    	printf("%d != %d\n", x, y);
    }
    
    printf("Assignment: ");
    if (x=y)
    {
    	printf("%d = %d\n", x, y);
    }
    else
    {
    	printf("%d != %d\n", x, y);
    }  
}