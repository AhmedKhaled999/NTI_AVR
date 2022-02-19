/*

 * HSEVEN_SEGMENT.c
 *
 *  Created on: Feb 7, 2022
 *      Author: Ahmed Khaled Hammad
 */
/******************************************************Session2************************************************************
 * -> Learn about Seven Segment
 * -> lab 1 Interface with Seven segment With different Pins and Display from 0 -> F
 * -> lab 2 Interface with 2 Seven segment And display form 0 -> FF
 * -> Learn about Switch & Switch Interface
 * -> lab 3 Increment If Switch Pressed And Display Number on Seven Segments 1
 * -> Task 1 Increment 0->FF by using SW
 * -> Task 2 Increment 0->FF by using delay 200 ms
 * -> Task 3 using DIP Switch if(0b10100010)-->display OP else display CL on Seven segment
 * -> Challenge 1 interface with 2 seven segments with 9 pins only without using decoder
 * -> Challenge 2 interface with 3 seven segment with 10 pins only without using decoder
 **/

/*Customized Data Type */
#include"STD_TYPES.h"

/*DIO Register Addresses --> Memory Mapping Address by default*/
//1- PORTA
#define PORTA       *((volatile u8*)0x3B)
#define DDRA        *((volatile u8*)0x3A)
#define PINA        *((volatile u8*)0x39)
//2- PORTB
#define PORTB       *((volatile u8*)0x38)
#define DDRB        *((volatile u8*)0x37)
#define PINB        *((volatile u8*)0x36)
//3- PORTC
#define PORTC       *((volatile u8*)0x35)
#define DDRC        *((volatile u8*)0x34)
#define PINC        *((volatile u8*)0x33)
//4- PORTD
#define PORTD       *((volatile u8*)0x32)
#define DDRD        *((volatile u8*)0x31)
#define PIND        *((volatile u8*)0x30)

/*Delay Function*/
#include<util/delay.h>

/*Seven segment-> Cathode Configuration [active High]
 * Seven Segment Truth Table:
 *----------------------------------------------
 *Number|Dot |g  |f  |e  |d  |c  |b  |a  |Hex  |
 *----------------------------------------------
 * 0    |0   |0  |1  |1  |1  |1  |1  |1  |0x3F |
 * ---------------------------------------------
 * 1    |0   |0  |0  |0  |0  |1  |1  |0  |0x06 |
 * ---------------------------------------------
 * 2    |0   |1  |0  |1  |1  |0  |1  |1  |0x5B |
 * ---------------------------------------------
 * 3    |0   |0  |1  |1  |0  |1  |1  |1  |0x4F |
 * ---------------------------------------------
 * 4    |0   |1  |1  |0  |0  |1  |1  |0  |0x66 |
 * ---------------------------------------------
 * 5    |0   |1  |1  |0  |1  |1  |0  |1  |0x6D |
 * ---------------------------------------------
 * 6    |0   |1  |1  |1  |1  |1  |0  |1  |0x7D |
 * ---------------------------------------------
 * 7    |0   |0  |0  |0  |0  |1  |1  |1  |0x07 |
 * ---------------------------------------------
 * 8    |0   |1  |1  |1  |1  |1  |1  |1  |0x7F |
 * ---------------------------------------------
 * 9    |0   |1  |1  |0  |1  |1  |1  |1  |0x6F |
 * ---------------------------------------------
 * A    |0   |1  |1  |1  |0  |1  |1  |1  |0x77 |
 * ---------------------------------------------
 * B    |0   |1  |1  |1  |1  |1  |0  |0  |0x7C |
 * ---------------------------------------------
 * C    |0   |0  |1  |1  |1  |0  |0  |1  |0x39 |
 * ---------------------------------------------
 * D    |0   |1  |0  |1  |1  |1  |1  |0  |0x5E |
 * ---------------------------------------------
 * E    |0   |1  |1  |1  |1  |0  |0  |1  |0x79 |
 * ---------------------------------------------
 * F    |0   |1  |1  |1  |0  |0  |0  |1  |0x71 |
 * ---------------------------------------------
 * */

u8 Copy_u8SevenSegArr_Cathode[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

u16 Count = 0;

void HSEVEN_SEG_VidInit(void)
{

	/*let Hardware interface with 7Segment 1 -->PORTA*/
	//Set Pins Direction --> Outputs Pins
	DDRA = 0xFF ;
	//Set Pins Initial Value --> Pins LOW
	PORTA = 0x00 ;
	/*let Hardware interface with Switch 1 -->PORTD,PIN7 */
	//Set Pin Direction --> Input Pin
	DDRD  &=~(1<<7) ;
	//Set Pin Initial Value --> Active internal Pull Resistor
	PORTD |=(1<<7);
}

int main(void)
{

	HSEVEN_SEG_VidInit();
	while(1)
	{
		/*Get Pin Value*/
		if(((PIND>>7)&1) == 0 )  //Pressed
		{
			/*De-bouncing*/
			_delay_ms(100);
			if(((PIND>>7)&1) == 0 )
			{
				if(Count<16)
				{
					PORTA = Copy_u8SevenSegArr_Cathode[Count];
					Count++;
					/*wait until depressed*/
					while(((PIND>>7)&1)!=1);
				}
				else
				{
					Count = 0 ;
					PORTA = Copy_u8SevenSegArr_Cathode[Count];
					/*wait until depressed*/
					while(((PIND>>7)&1)!=1);
				}
			}
			else
			{/*Do Nothing */}
		}

	}
	return 0 ;
}
