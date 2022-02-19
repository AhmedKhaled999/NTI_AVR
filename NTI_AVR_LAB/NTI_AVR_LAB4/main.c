/*
 * main.c
 *
 *  Created on: Feb 7, 2022
 *      Author: Ahmed Khaled Hammad
 */

/******************************************************Session3************************************************************
 * -> Learn about Ghosting effect & Flickering effect
 * -> Software Design (Static Layered Architecture)
 * -> Prebuild Configuration & module's Files[M_Program.c/M_Interface.h/M_Private/M_Config.h]
 * -> Create ERROR_STATE.h File
 * -> Search about Stringification  && String Concatenation in preprocessor
 * -> LAB 4 build DIO Driver and Toogle LED
 **/

/*Customized Data Type */
#include"STD_TYPES.h"
#include"ERROR_State.h"

/*DIO Libraries*/
#include"DIO_Interface.h"

/*Delay Function*/
#include<util/delay.h>


int main(void)
{
	/*initialize DIO Driver according to your Configuration
	 * PA0-->OUTPUT
	 * PA0-->PIN_LOW*/
	DIO_ES_tInit();
	while(1)
	{
		//PINA0--> PIN_HIGH [LED_ON]
		DIO_ES_tSetPinValue(DIO_PORTA,PIN0,PIN_HIGH);
		//Delay--> (1) second
		_delay_ms(1000);
		//PINA0--> PIN_LOW  [LED_OFF]
		DIO_ES_tSetPinValue(DIO_PORTA,PIN0,PIN_LOW);
		//Delay--> (1) second
		_delay_ms(1000);
	}
	return 0 ;
}
