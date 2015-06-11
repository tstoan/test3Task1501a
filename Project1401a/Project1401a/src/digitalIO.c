/*
 * digitalIO.c
 *
 * Created: 2015-06-10 15:11:18
 *  Author: Ulrik
 */ 

#include <inttypes.h>	/* See http://en.wikipedia.org/wiki/C_data_types#Fixed-width_integer_types for more info */
#include <asf.h>		/* Only needed to get the definitions for HIGH and LOW */
#include "digitalIO.h"

#define PIOB_BASE_ADDRESS 0x400E1000U

void pinMode(int pinNumber, mode_definition mode)
{
	if (mode == OUTPUT)	/* You only have to program a function that cares about OUTPUT, and does nothing for the other values */
	{

	}
	else
	{
		/* Do nothing */
	}
}

void digitalWrite(int pinNumber, int value)
{
	if (value == HIGH)
	{
		
	}
	else if (value == LOW)
	{
		
	}
	else
	{
		/* Something is wrong */
	}
}