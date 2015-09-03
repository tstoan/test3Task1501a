/**
 * /file testDigitalIO_runner.c
 * /author Ulrik Eklund
 * /date 2015-09-03
 * /brief Test runner program for test of the digital outputs on an Arduino Due board.
 *
 * This project provides a basic set of tests for functions controlling the digital outputs on
 * Arduino Due board, using Unity as the test framework (https://github.com/ThrowTheSwitch/Unity).
 * 
 * This file is the main() function that calls all the relevant tests, which in turn calls the 
 * functions to be developed.
 *
 * This program does not rely on the hardware API (ASF) provided by Atmel, but instead uses
 * the student developed library for SAM3X8E and a modified unity_internals.h to print the
 * test results on the terminal via UART over USB.
 */

#include <inttypes.h>	/* See http://en.wikipedia.org/wiki/C_data_types#Fixed-width_integer_types for more info */
#include <setjmp.h>

#include "..sam3x8e/eefc.h"
#include "..sam3x8e/pmc.h"
#include "..sam3x8e/uart.h"

//#include <stdio_serial.h>
//#include <asf.h>
//#include "conf_board.h"
#include "../unity/unity.h"	/* Contains declarations of all functions that Unity provides */
#include "test_digitalIO.h" /* Contains declarations of the nine tests for this exercise */

// static void configure_console(void)
// /* Enables feedback through the USB-cable back to terminal within Atmel Studio */
// {
// 	const usart_serial_options_t uart_serial_options = {
// 		.baudrate = CONF_UART_BAUDRATE,
// 		.paritytype = CONF_UART_PARITY
// 	};
//
// 	/* Configure console UART. */
// 	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
// 	stdio_serial_init(CONF_UART, &uart_serial_options);
//
// 	/* printf("Console ready\n"); */
// }


int main(void)
{
	/*
	* Set Flash Wait State, by defining the number of cycles
	* for read and write operations: FWS + 1
	*/
	eefc_set_flash_wait_state(EEFC0, 4);
	eefc_set_flash_wait_state(EEFC1, 4);

	/* initialize system clock, otherwise nothing useful runs */
	pmc_init_system_clock();

	/* disable the watchdog timer so the procoessor does not reset when the timer overflows */
	wdt_disable();
	
	/* Define the settings for printing the output from Unity to the terminal used,
	   note that the settings must be the same in the terminal window in Atmel studio */
	uart_settings_t uart_settings = {
		.baud_rate = 115200,
		.parity = UART_PARITY_NO,
		.ch_mode = UART_CHMODE_LOCAL_LOOPBACK
	};
	/* Initialize the console UART */
	uart_init(&uart_settings);
	
	/* From here on the program uses the Unity testing framework */
	UnityBegin("../test/testDigitalIO.c");
	
	/* Run the tests from the test-file */
	RUN_TEST(test_digitalDuePin13InitialiseProperly, 10);
	
	/* Uncomment the rest of the tests, one at a time, when you have written or modified code so that you pass the previous test */
	//RUN_TEST(test_digitalDuePin13IsSet, 15);
	//RUN_TEST(test_digitalDuePin13IsCleared, 18);
	//
	//RUN_TEST(test_digitalDuePin22InitialiseProperly, 20);
	//RUN_TEST(test_digitalDuePin22IsSet, 25);
	//RUN_TEST(test_digitalDuePin22IsCleared, 28);
	//
	//RUN_TEST(test_digitalDuePin13And22InitialiseProperly, 30);
	//RUN_TEST(test_digitalDuePin13And22IsSet, 35);
	//RUN_TEST(test_digitalDuePin13isClearedAnd22IsSet, 38);

	UnityEnd();
	
	return 0;
}

