/*
 * testDigitalIO.c
 *
 * Created: 2015-06-09 10:37:43
 *  Author: staff
 */ 


#include "unity.h"

#include "../src/digitalIO.h"
#include "test_digitalIO.h"

/* 
 * setting up the memory addresses of the digital I/O B-port 
 * which does not depend if the B-port is used as an input or output
 * Most of these variables will not be used
 */
uint32_t *const p_PIOB_BASE = (register_ctrl *) 0x400E1000U;	/*base address for PIO registers */

uint32_t *const p_PIOB_PER = (uint32_t *) 0x400E1000U;	/* defines the address for enabling the parallel Input/output B register */
uint32_t *const p_PIOB_PSR = (uint32_t *) 0x400E1008U;	/* defines the address for status of the parallel Input/output B register */
uint32_t *const p_PIOB_OER = (uint32_t *) 0x400E1010U;	/* defines the address for enabling the parallel output B register */
uint32_t *const p_PIOB_OSR = (uint32_t *) 0x400E1018U;	/* defines the address for status of the parallel output B register */
uint32_t *const p_PIOB_ODR = (uint32_t *) 0x400E1014U;	/* defines the address for output disable of the parallel output B register */
uint32_t *const p_PIOB_SODR = (uint32_t *) 0x400E1030U;	/* defines the address for setting the output pins of the B register */
uint32_t *const p_PIOB_CODR = (uint32_t *) 0x400E1034U;	/* defines the address for clearing the output pins of the B register  */
// uint32_t *const p_PIOB_MDER = (uint32_t *) 0x400E1050U;	/*   */
// uint32_t *const p_PIOB_MDDR = (uint32_t *) 0x400E1054U;	/*   */
uint32_t *const p_PIOB_OWER = (uint32_t *) 0x400E10A0U;	/*   */
// uint32_t *const p_PIOB_OWDR = (uint32_t *) 0x400E10A4U;	/*   */
// uint32_t *const p_PIOB_ABSR = (uint32_t *) (0x400E1070U);


void setUp(void)
{
	/* No special setup before each test */
}

void tearDown(void)
{
	/* No special teardown after each test */
}

void resetTest(void)
{
	tearDown();
	setUp();
}

void test_digitalDuePin13InitialiseProperly(void)
{
	pinMode(13, OUTPUT);	/* Initialise pin 13 on the Due as an output */
	TEST_ASSERT_BIT_HIGH(27, *p_PIOB_OSR)	/* Check the status bit that PB27 on port B is properly initialised */
	
	/* Note that you need to understand the board pin mapping on http://www.arduino.cc/en/Hacking/PinMappingSAM3X */
}

void test_digitalDuePin13IsSet(void)
{
	digitalWrite(13, HIGH); /* set pin 13 on the Due to high, lighting up the amber diod */
	TEST_ASSERT_BIT_HIGH(27, *p_PIOB_ODSR)	/* Check the status bit that PB27 on port B is set */
}