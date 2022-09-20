/*
 * dio.h
 *
 * Created: 9/12/2022 12:14:24 PM
 *  Author: dinoa
 */ 


#ifndef DIO_H_
#define DIO_H_

// Include register.h
#include "../Utilities/registers.h"
#include "../Utilities/types.h"

// All driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// direction defines
#define IN 0
#define OUT 1

// value defines
#define LOW 0
#define HIGH 1

// All driver function
void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);	// Initialize dio direction

void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);		// Write data to dio

void DIO_toggle(uint8_t pinNumber, uint8_t portNumber);						// Toggle dio

void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);		// Read dio

#endif /* DIO_H_ */