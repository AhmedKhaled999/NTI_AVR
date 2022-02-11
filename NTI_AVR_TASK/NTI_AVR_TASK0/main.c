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

/*Memory Mapping address*/
#define  DDRA  *((volatile unsigned char *)0x3A)
#define  PORTA *((volatile unsigned char *)0x3B)

/*Delay Function*/
#include<util/delay.h>

/******************************************Helper Functions***************************************************************/
//Set Direction For PORTA By using Assembly
void App_VidPortAddressDirection(void);

//Set PORTA Values By using Inline Assembly
void App_VidPortAddressValue(void);

//Set PORTA Values By using Memory Mapping Address
void App_VidMemoryAddressValue(void);

/*Program Entry Point*/
int main (void)
{
	/*Method 1: By Inline Assembly */
	//Set PORTA Direction
	App_VidPortAddressDirection();
	/*Method 2: By Memory Mapping Address  */
	//Set PORTA Direction
	//DDRA = 255 ; //0b11111111 , 0xFF

	while(1)
	{
		/*Method 1: By Inline Assembly */
		//Set PORTA Values
		App_VidPortAddressValue();
		/*Method 2: By Memory Mapping Address  */
		//Set PORTA Direction
		//App_VidMemoryAddressValue();
	}

	return  0 ;

}

/******************************************************************************************************************************/
void App_VidPortAddressValue(void)
{
	asm("SBI 0x1B,7");
	_delay_ms(250);
	asm("SBI 0x1B,6");
	_delay_ms(250);
	asm("SBI 0x1B,5");
	_delay_ms(250);
	asm("SBI 0x1B,4");
	_delay_ms(250);
	asm("SBI 0x1B,3");
	_delay_ms(250);
	asm("SBI 0x1B,2");
	_delay_ms(250);
	asm("SBI 0x1B,1");
	_delay_ms(250);
	asm("SBI 0x1B,0");
	_delay_ms(250);
	asm("CBI 0x1B,7");
	_delay_ms(250);
	asm("CBI 0x1B,6");
	_delay_ms(250);
	asm("CBI 0x1B,5");
	_delay_ms(250);
	asm("CBI 0x1B,4");
	_delay_ms(250);
	asm("CBI 0x1B,3");
	_delay_ms(250);
	asm("CBI 0x1B,2");
	_delay_ms(250);
	asm("CBI 0x1B,1");
	_delay_ms(250);
	asm("CBI 0x1B,0");
	_delay_ms(250);
}


/**************************************************************************************************************/
void App_VidPortAddressDirection(void)
{
	asm("SBI 0x1A,0");
	asm("SBI 0x1A,1");
	asm("SBI 0x1A,2");
	asm("SBI 0x1A,3");
	asm("SBI 0x1A,4");
	asm("SBI 0x1A,5");
	asm("SBI 0x1A,6");
	asm("SBI 0x1A,7");
}

/**************************************************************************************************************/
void App_VidMemoryAddressValue(void)
{

	for(signed char i = 7 ; i>=0 ;i--  )
	{
		PORTA |= 1<<i;
		_delay_ms(250);
	}
	for(signed char i = 7 ; i>=0 ;i--  )
	{
		PORTA &= ~(1<<i);
		_delay_ms(250);
	}
}
