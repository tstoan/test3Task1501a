/*
 * testDigitalIO.c
 *
 * Created: 2015-06-09 10:37:43
 *  Author: staff
 */ 

#include <asf.h>

#include "../unity/unity.h"

#include "../src/digitalIO.h"
#include "test_digitalIO.h"

/* 
 * setting up the memory addresses of the digital I/O B-port 
 * which does not depend if the B-port is used as an input or output
 */

#define PIOB_BASE_ADDRESS 0x400E1000U
uint32_t *const p_PIOB_PER = (uint32_t *) (PIOB_BASE_ADDRESS+0x0000U);	/* defines the address for enabling the parallel Input/output B register */
uint32_t *const p_PIOB_PDR = (uint32_t *) (PIOB_BASE_ADDRESS+0x0004U);	/* defines the address for dispabling the parallel Input/output B register */
uint32_t *const p_PIOB_PSR = (uint32_t *) (PIOB_BASE_ADDRESS+0x0008U);	/* defines the address for status of the parallel Input/output B register */
uint32_t *const p_PIOB_OER = (uint32_t *) (PIOB_BASE_ADDRESS+0x0010U);	/* defines the address for enabling the parallel output B register */
uint32_t *const p_PIOB_ODR = (uint32_t *) (PIOB_BASE_ADDRESS+0x0014U);	/* defines the address for output disable of the parallel output B register */
uint32_t *const p_PIOB_OSR = (uint32_t *) (PIOB_BASE_ADDRESS+0x0018U);	/* defines the address for status of the parallel output B register */
uint32_t *const p_PIOB_SODR = (uint32_t *) (PIOB_BASE_ADDRESS+0x0030U);	/* defines the address for setting the output pins of the B register */
uint32_t *const p_PIOB_CODR = (uint32_t *) (PIOB_BASE_ADDRESS+0x0034U);	/* defines the address for clearing the output pins of the B register  */
uint32_t *const p_PIOB_ODSR = (uint32_t *) (PIOB_BASE_ADDRESS+0x0038U);	/* defines the address for clearing the output pins of the B register  */
// uint32_t *const p_PIOB_MDER = (uint32_t *) (PIOB_BASE_ADDRESS+0x0010U);	/*   */
// uint32_t *const p_PIOB_MDDR = (uint32_t *) (PIOB_BASE_ADDRESS+0x0010U);	/*   */
uint32_t *const p_PIOB_OWER = (uint32_t *) (PIOB_BASE_ADDRESS+0x0010U);	/*   */
// uint32_t *const p_PIOB_OWDR = (uint32_t *) (PIOB_BASE_ADDRESS+0x0010U);	/*   */
// uint32_t *const p_PIOB_ABSR = (uint32_t *) (PIOB_BASE_ADDRESS+0x0010U);


void setUp(void)
{
	*p_PIOB_PDR = 0xFFFFFFFFU; /* Disable PORT B */
}

void tearDown(void)
{
	*p_PIOB_PDR = 0xFFFFFFFF; /* Disable PORT B */
}

void resetTest(void)
{
	tearDown();
	setUp();
}

void test_digitalDuePin13InitialiseProperly(void)
{
	pinMode(13, OUTPUT);	/* Initialise pin 13 on the Due as an output */
	TEST_ASSERT_BIT_HIGH(27, *p_PIOB_PSR);	/* Check the status bit that PB27 on port B is properly initialised */
	TEST_ASSERT_BIT_HIGH(27, *p_PIOB_OSR);	/* Check the status bit that PB27 on port B is an output */
	
	/* Note that you need to understand the board pin mapping on http://www.arduino.cc/en/Hacking/PinMappingSAM3X */
}

void test_digitalDuePin13IsSet(void)
{
	pinMode(13, OUTPUT);	/* Initialise pin 13 on the Due as an output, already proven to work in previous test */
	
	digitalWrite(13, HIGH); /* set pin 13 on the Due to high, lighting up the amber diode */
	TEST_ASSERT_BIT_HIGH(27, *p_PIOB_ODSR);	/* Check the status bit that PB27 on port B is set */
}

void test_digitalDuePin13IsCleared(void)
{
	pinMode(13, OUTPUT);	/* Initialise pin 13 on the Due as an output, proven to work in previous test */
	digitalWrite(13, HIGH); /* set pin 13 on the Due to high, lighting up the amber diode, proven to work in previous test */
	digitalWrite(13, LOW);	/* set pin 13 on the Due to low, turning off the amber diode */
	TEST_ASSERT_BIT_LOW(27, *p_PIOB_ODSR);	/* Check the status bit that PB27 on port B is cleared */
}

void test_digitalDuePin22InitialiseProperly(void)
{
	pinMode(22, OUTPUT);	/* Initialise pin 22 on the Due as an output */
	TEST_ASSERT_BIT_HIGH(26, *p_PIOB_OSR);	/* Check the status bit that PB26 on port B is properly initialised */
}
void test_digitalDuePin22IsSet(void)
{
	pinMode(22, OUTPUT);	/* Initialise pin 22 on the Due as an output, already proven to work in previous test */
	digitalWrite(22, HIGH); /* set pin 22 on the Due to high */
	TEST_ASSERT_BIT_HIGH(26, *p_PIOB_ODSR);	/* Check the status bit that PB26 on port B is set */
}
void test_digitalDuePin22IsCleared(void)
{
	pinMode(22, OUTPUT);	/* Initialise pin 22 on the Due as an output, proven to work in previous test */
	digitalWrite(22, HIGH); /* set pin 22 on the Due to high, proven to work in previous test */
	
	digitalWrite(22, LOW);	/* set pin 22 on the Due to low */
	TEST_ASSERT_BIT_LOW(26, *p_PIOB_ODSR);	/* Check the status bit that PB26 on port B is cleared */
}

void test_digitalDuePin13And22InitialiseProperly(void)
{
	pinMode(13, OUTPUT);	/* Initialise pin 13 on the Due as an output */
	pinMode(22, OUTPUT);	/* Initialise pin 22 on the Due as an output */
	
	TEST_ASSERT_BIT_HIGH(26, *p_PIOB_OSR);	/* Check the status bit that PB26 on port B is properly initialised */
	TEST_ASSERT_BIT_HIGH(27, *p_PIOB_OSR);	/* Check the status bit that PB27 on port B is properly initialised */
}

void test_digitalDuePin13And22IsSet(void)
{		
	pinMode(13, OUTPUT);	/* Initialise pin 13 on the Due as an output */
	pinMode(22, OUTPUT);	/* Initialise pin 22 on the Due as an output */
		
	digitalWrite(13, HIGH); /* set pin 13 on the Due to high, lighting up the amber diode */
	digitalWrite(22, HIGH); /* set pin 22 on the Due to high */
	TEST_ASSERT_BIT_HIGH(26, *p_PIOB_ODSR);	/* Check the status bit that PB26 on port B is set */
	TEST_ASSERT_BIT_HIGH(27, *p_PIOB_ODSR);	/* Check the status bit that PB27 on port B is set */
}

void test_digitalDuePin13isSetAnd22IsCleared(void)
{
	pinMode(13, OUTPUT);	/* Initialise pin 13 on the Due as an output */
	pinMode(22, OUTPUT);	/* Initialise pin 22 on the Due as an output */

	digitalWrite(13, LOW); /* set pin 13 on the Due to low */
	digitalWrite(22, HIGH); /* set pin 22 on the Due to high */
	TEST_ASSERT_BIT_LOW(27, *p_PIOB_ODSR);	/* Check the status bit that PB27 on port B is cleared */
	TEST_ASSERT_BIT_HIGH(26, *p_PIOB_ODSR);	/* Check the status bit that PB26 on port B is set */
			
	digitalWrite(13, HIGH); /* set pin 13 on the Due to high, lighting up the amber diode */
	digitalWrite(22, LOW); /* set pin 22 on the Due to low */
	TEST_ASSERT_BIT_HIGH(27, *p_PIOB_ODSR);	/* Check the status bit that PB27 on port B is set */	
	TEST_ASSERT_BIT_LOW(26, *p_PIOB_ODSR);	/* Check the status bit that PB26 on port B is cleared */
}


