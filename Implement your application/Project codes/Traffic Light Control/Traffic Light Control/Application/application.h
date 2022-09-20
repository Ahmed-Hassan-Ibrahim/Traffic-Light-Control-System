/*
 * application.h
 *
 * Created: 9/12/2022 12:12:36 PM
 *  Author: dinoa
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

//Application flags
unsigned int traffic_status; // flag for button pushed at which state
unsigned int interrupt_flag; // flag for when car red is on
unsigned int yellow_blink; // flag to count number of times yellow light blinked

// Include all required files
#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Button Driver/button.h"

// All APP function
void APP_init();	// Initialize all drivers
void APP_start();	// Start the application

#endif /* APPLICATION_H_ */