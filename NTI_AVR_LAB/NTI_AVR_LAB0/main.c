/*
 * main.c
 *
 *  Created on: Feb 6, 2022
 *      Author: Ahmed Khaled Hammad
 */



/******************************************************Session1************************************************************
 * -> Learn about DIO in general and specific for ATMEGA32
 * -> Inline assembly in c code through asm()
 * -> Port mapping and memory mapping
 * -> set up tools
 * -> lab [toggle lED]
 * -> Task apply snake effect on  8 LEDs by using Memory Mapping once and Porting Mapping anther once
 **/

/*Memory Mapping address From Data sheet Page 299 */
#define  DDRA  *((volatile unsigned char *)0x3A)
#define  PORTA *((volatile unsigned char *)0x3B)

/*Delay Function*/
#include<util/delay.h>


int main (void)
{

	/*Method 1 : By Port Mapping Address */
//	//PINA0--> Output Pin
//	asm("SBI 0x1A,0");
//	//PINA0--> Initial Value Low
//	asm("CBI 0x1B,0");
	/*Method 2 : By Memory Mapping Address */
	//PINA0--> Output Pin
	*((unsigned char*)0x3A) |=(1<<0);
	//PINA0--> Initial Value Low
	*((unsigned char*)0x3B) &=~(1<<0);

	while(1)
	{
		/*Method 1 : By Port Mapping Address */
		//PINA0--> PIN_HIGH [LED_ON]
//		asm("SBI 0x1B,0");
//		//Delay--> (1) second
//		_delay_ms(1000);
//		//PINA0--> PIN_LOW  [LED_OFF]
//		asm("CBI 0x1B,0");
//		//Delay--> (1) second
//		_delay_ms(1000);

		/*Method 2 : By Memory Mapping Address */
		//PINA0--> PIN_HIGH [LED_ON]
		*((unsigned char*)0x3B) |=(1<<0);
		//Delay--> (1) second
		_delay_ms(1000);
		//PINA0--> PIN_LOW  [LED_OFF]
		*((unsigned char*)0x3B) &=~(1<<0);
		//Delay--> (1) second
		_delay_ms(1000);
	}

	return  0 ;

}
