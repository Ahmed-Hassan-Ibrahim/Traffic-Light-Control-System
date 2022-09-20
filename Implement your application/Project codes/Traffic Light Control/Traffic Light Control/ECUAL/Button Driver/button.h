/*
 * button.h
 *
 * Created: 9/12/2022 12:13:43 PM
 *  Author: dinoa
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupt Library/interrupt.h"

// All driver macros
#define BUTTON_1_PORT PORT_D
#define BUTTON_1_PIN 2

// Button state Macros
#define LOW		0
#define HIGH	1

// All driver function
void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);					// Initialize button
void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);	// Read button

#endif /* BUTTON_H_ */