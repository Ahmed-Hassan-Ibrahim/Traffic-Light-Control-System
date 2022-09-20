/*
 * application.c
 *
 * Created: 9/12/2022 12:13:15 PM
 *  Author: dinoa
 */ 

#include "application.h"

void APP_init()
{
	traffic_status = 0;
	yellow_blink = 0;
	interrupt_flag = 0;
	
	LED_init(PORT_A, 0);	//Initialize car red light
	LED_init(PORT_A, 1);	//Initialize car yellow light
	LED_init(PORT_A, 2);	//Initialize car green light
	
	LED_init(PORT_B, 0);	//Initialize pedestrian red light
	LED_init(PORT_B, 1);	//Initialize pedestrian yellow light
	LED_init(PORT_B, 2);	//Initialize pedestrian green light
	
	BUTTON_init(BUTTON_1_PORT, BUTTON_1_PIN);	//Initialize Traffic light button
	
	TIMER_init();	//Initialize timer
	
	sei();						// enable global interrupts
	MCUCR |= (1<<0) | (1<<1);	// choose  sense on rising edge
	GICR |= (1<<6);				// enable external interrupt
}
//=========================================================================================================
void APP_start()
{
	while(1){
		switch(traffic_status)
		{
			// Normal mode
			case 0:
				while(traffic_status == 0)
				{
					LED_on(PORT_A, 2);	//car green on
					interrupt_flag = 1;
					LED_on(PORT_B, 0);	//pedestrian red on
					DELAY_5_sec();
					LED_off(PORT_A, 2);	//car green off
					interrupt_flag = 0;
					LED_off(PORT_B, 0);	//pedestrian red off
					break;
				}
				while(traffic_status == 0)
				{
					// both yellow light toggle for 5 seconds
					yellow_blink = 0;
					while(yellow_blink < 5)
					{
						interrupt_flag = 1;
						LED_toggle(PORT_A, 1);	//car yellow toggle
						LED_toggle(PORT_B, 1);	//pedestrian yellow toggle
						DELAY_1_sec();
						yellow_blink++;
					}
					interrupt_flag = 0;
					LED_off(PORT_A, 1); //car yellow off
					LED_off(PORT_B, 1);	//pedestrian yellow off
					break;
				}
				while(traffic_status == 0)
				{
					LED_on(PORT_A, 0);	//car red on 
					LED_on(PORT_B, 2);	//pedestrian green on
					DELAY_5_sec();
					LED_off(PORT_A, 0);	//car red off
					break;
				}
				while(traffic_status == 0)
				{
					LED_off(PORT_B, 2);	//pedestrian green off
					// both yellow light toggle for 5 seconds
					yellow_blink = 0;
					while(yellow_blink < 5)
					{
						interrupt_flag = 1;
						LED_toggle(PORT_A, 1);	//car yellow toggle
						LED_toggle(PORT_B, 1);	//pedestrian yellow toggle
						DELAY_1_sec();
						yellow_blink++;
					}
					interrupt_flag = 0;
					LED_off(PORT_A, 1); //car yellow off
					LED_off(PORT_B, 1);	//pedestrian yellow off
					break;
				}
			break;
			
			//button pushed while car green or yellow is on
			case 1:
				LED_off(PORT_B, 2);	//pedestrian green off
				LED_on(PORT_B, 0);	//pedestrian red on
				// both yellow light toggle for 5 seconds
				yellow_blink = 0;
				while(yellow_blink < 5)
				{
					LED_toggle(PORT_A, 1);	//car yellow toggle
					LED_toggle(PORT_B, 1);	//pedestrian yellow toggle
					DELAY_1_sec();
					yellow_blink++;
				}
				LED_off(PORT_B, 0);	//pedestrian red off
				LED_off(PORT_A, 1); //car yellow off
				LED_off(PORT_B, 1);	//pedestrian yellow off
				LED_on(PORT_A, 0);	//car red on
				LED_on(PORT_B, 2);	//pedestrian green on
				DELAY_5_sec();
				LED_off(PORT_A, 0);	//car red off
				// both yellow light toggle for 5 seconds
				yellow_blink = 0;
				while(yellow_blink < 5)
				{
					LED_toggle(PORT_A, 1);	//car yellow toggle
					LED_toggle(PORT_B, 1);	//pedestrian yellow toggle
					DELAY_1_sec();
					yellow_blink++;
				}
				LED_off(PORT_A, 1); //car yellow off
				LED_off(PORT_B, 1);	//pedestrian yellow off
				LED_off(PORT_B, 2);	//pedestrian green off
				traffic_status = 0;
			break;
		}
	}
}
//=========================================================================================================
ISR(EXT_INT_0)
{
	if (interrupt_flag == 1)
	{
		traffic_status = 1; //case 1 -> button pushed while car green or yellow is on
	}
}