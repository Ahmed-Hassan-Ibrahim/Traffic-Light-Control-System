/*
 * button.c
 *
 * Created: 9/12/2022 12:13:29 PM
 *  Author: dinoa
 */ 

#include "button.h"

void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin)
{
	DIO_init(buttonPin,buttonPort,IN);
}
//=========================================================================================================
void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value)
{
	DIO_read(buttonPin,buttonPort,value);
}