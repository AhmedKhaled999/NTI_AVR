/*
 * main.c
 *
 *  Created on: Feb 7, 2022
 *      Author: Ahmed Khaled Hammad
 */

/******************************************************Session4************************************************************
 * -> Learn about Stringification  && String Concatenation in preprocessor
 * -> Prebuild Configuration & module's Files[M_Program.c/M_Interface.h/M_Private/M_Config.h]
 * -> Learn about Linking Configuration
 * -> LAB 5 build Switch Driver with prebuild Configuration and Toogle LED when Switch is pressed
 * -> LAB 6 build Switch Driver with Linking Configuration and Toogle LED when Switch is pressed
 * -> TASK 4 build 7SEG  Driver With Linking Configuration
 **/

/*Customized Data Type */
#include"STD_TYPES.h"
#include"ERROR_State.h"

/*DIO Libraries*/
#include"DIO_Interface.h"
/*SWITCH Driver*/
#include"SWITCH_Interface.h"

/*Delay Function*/
#include<util/delay.h>

 u8 G_u8SwitchState  ;
int main(void)
{
	/*initialize DIO Driver according to your Configuration
	 * PA0-->OUTPUT
	 * PA0-->PIN_LOW*/
	DIO_ES_tInit();

	/*Initialize SWITCH Driver According to your Configuration
	 * PD0-->INPUT
	 * PD0-->PIN_HIGH[Active Internal Pull up resistor]*/
	SWITCH_ES_tInit();
	while(1)
	{
		SWITCH_ES_tGetSwitchState(&G_u8SwitchState);
		if(G_u8SwitchState == PULLUP_PRESSED)
		{
			/*De-Bouncing */
			_delay_ms(50);
			SWITCH_ES_tGetSwitchState(&G_u8SwitchState);
			if(G_u8SwitchState == PULLUP_PRESSED)
			{
				DIO_ES_tTogglePinValue(DIO_PORTA,PIN0);
				SWITCH_ES_tGetSwitchState(&G_u8SwitchState);
				/*wait till  switch Depressed*/
				while(G_u8SwitchState == PULLUP_PRESSED)
				{
					SWITCH_ES_tGetSwitchState(&G_u8SwitchState);
				}
			}
			else
			{
				/*Do Nothing*/
			}
		}
		else
		{/*Do Nothing*/}
	}
	return 0 ;
}
