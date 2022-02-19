/*
 * DIO_Interface.h
 *
 *  Created on: Feb 12, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*DIO Initialization*/
ES_t DIO_ES_tInit(void);
/*Set Pin Direction*/
ES_t DIO_ES_tSetPinDirection(u8 Copy_u8PortNumber, u8 Copy_u8PinNumber , u8 Copy_PinDirection);
/*Set Pin Value*/
ES_t DIO_ES_tSetPinValue(u8 Copy_u8PortNumber, u8 Copy_u8PinNumber , u8 Copy_PinValue);
/*Get Pin Value*/
ES_t DIO_ES_tGetPinValue(u8 Copy_u8PortNumber, u8 Copy_u8PinNumber , u8* Copy_PinValue);
/*Toggle Pin Value*/
ES_t DIO_ES_tTogglePinValue(u8 Copy_u8PortNumber, u8 Copy_u8PinNumber);

/************************************************User DIO PORT's Name*************************************************************/

#define  DIO_PORTA    0
#define  DIO_PORTB    1
#define  DIO_PORTC    2
#define  DIO_PORTD    3

/************************************************User PORT Pin's Name***************************************************************/

#define PIN0     0
#define PIN1     1
#define PIN2     2
#define PIN3     3
#define PIN4     4
#define PIN5     5
#define PIN6     6
#define PIN7     7


/*************************************************User Pin Direction state************************************************************/

#define PIN_OUTPUT   1
#define PIN_INPUT    0

/*************************************************User Pin  value*********************************************************************/

#define PIN_HIGH   1
#define PIN_LOW    0

/*************************************************Pin Input Interface*****************************************************************/

#define DIO_FLOAT    0
#define DIO_PULLUP   1

#endif /* DIO_INTERFACE_H_ */
