//
//  Masksing.c
//  TeachingAid
//
//  Created by Ulrik on 2014-11-07.
//
//

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint32_t x,y;
    
    x = 0x00004000;
    y = 0x00000002;
    printf("x = 0x%x\ny = 0x%x\n", x, y);
    
    if (x & y)
        printf("The bit specified by 0x%x is set in 0x%x\n", y, x);
    else
        printf("The bit specified by 0x%x is not set in 0x%x\n", y, x);
    
    x = x | y;
    
    printf("x = x | y -> 0x%x\n", x);
}