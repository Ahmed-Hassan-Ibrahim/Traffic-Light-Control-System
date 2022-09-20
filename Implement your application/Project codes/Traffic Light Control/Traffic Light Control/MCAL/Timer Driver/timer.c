/*
 * timer.c
 *
 * Created: 9/12/2022 12:15:19 PM
 *  Author: dinoa
 */ 

#include "timer.h"

void TIMER_init()
{
	TCCR0 = 0x00;	// Normal Mode
	TCNT0 = 0x00;	// timer initial value
}
//=========================================================================================================
void DELAY_5_sec()
{
	unsigned int overFlowCounter = 0;
	TCCR0 |= (1<<0);	// time start -> no prescaler
	
	while(overFlowCounter < NUMBER_OF_OVERFLOW_5)
	{
		// will repeat 19531 times
		while((TIFR & (1<<0)) == 0);	// wait until overflow flag is set
		TIFR |= (1<<0);	// clear overflow flag
		overFlowCounter++;
	}
	TCCR0 = 0x00;	// timer stop
}
//=========================================================================================================
void DELAY_1_sec()
{
	unsigned int overFlowCounter = 0;
	TCCR0 |= (1<<0);	// time start -> no prescaler
	
	while(overFlowCounter < NUMBER_OF_OVERFLOW_1)
	{
		// will repeat 3906 times
		while((TIFR & (1<<0)) == 0);	// wait until overflow flag is set
		TIFR |= (1<<0);	// clear overflow flag
		overFlowCounter++;
	}
	TCCR0 = 0x00;	// timer stop
}