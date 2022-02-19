/*
 * DIO_Private.h
 *
 *  Created on: Feb 12, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

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

/*************************************************Pins Direction************************************************************/

#define PIN_OUTPUT   1
#define PIN_INPUT    0

/*************************************************Pins Initial value************************************************************/
#define PIN_HIGH     1
#define PIN_LOW      0

/************************************************DIO PORT's Name*************************************************************/

#define  DIO_PORTA    0
#define  DIO_PORTB    1
#define  DIO_PORTC    2
#define  DIO_PORTD    3

/************************************************ PORT Pin's Name*************************************************************/

#define PIN0     0
#define PIN1     1
#define PIN2     2
#define PIN3     3
#define PIN4     4
#define PIN5     5
#define PIN6     6
#define PIN7     7

/*************************************************Pin Input Interface*****************************************************************/

#define DIO_FLOAT    0
#define DIO_PULLUP   1

/***************************************************String Concatenation**************************************************************/
#define CONCAT_H(PIN7,PIN6,PIN5,PIN4,PIN3,PIN2,PIN1,PIN0)   0b##PIN7##PIN6##PIN5##PIN4##PIN3##PIN2##PIN1##PIN0
#define CONCAT(PIN7,PIN6,PIN5,PIN4,PIN3,PIN2,PIN1,PIN0)     CONCAT_H(PIN7,PIN6,PIN5,PIN4,PIN3,PIN2,PIN1,PIN0)

/************************************************BIT MASKING *************************************************************************/
#define DIO_BIT_MASK  1
#endif /* DIO_PRIVATE_H_ */
