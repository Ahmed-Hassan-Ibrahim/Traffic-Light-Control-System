/*
 * led.h
 *
 * Created: 9/12/2022 12:13:54 PM
 *  Author: dinoa
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Timer Driver/timer.h"

// All driver function
void LED_init(uint8_t ledPort, uint8_t ledPin);		// Initialize LED
void LED_on(uint8_t ledPort, uint8_t ledPin);		// Turn on the LED
void LED_off(uint8_t ledPort, uint8_t ledPin);		// Turn off the LED
void LED_toggle(uint8_t ledPort, uint8_t ledPin);	// Toggle the LED

#endif /* LED_H_ */