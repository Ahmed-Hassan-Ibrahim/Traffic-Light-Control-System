/*
 * timer.h
 *
 * Created: 9/12/2022 12:15:28 PM
 *  Author: dinoa
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../DIO Driver/dio.h"

// Driver defines
#define NUMBER_OF_OVERFLOW_5 19531		// calculated overflow repeats for 5 second delay
#define NUMBER_OF_OVERFLOW_1 3906		// calculated overflow repeats for 1 second delay

// All driver function
void TIMER_init();		// Initialize timer
void DELAY_5_sec();		// delay 5 seconds
void DELAY_1_sec();		// delay 1 second

#endif /* TIMER_H_ */