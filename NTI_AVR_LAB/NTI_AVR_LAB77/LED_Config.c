/*
 * LED_Config.c
 *
 *  Created on: Feb 12, 2022
 *      Author: Ahmed Khaled Hammad
 */


/*Public libraries*/
#include"STD_TYPES.h"
#include"ERROR_STATE.h"

//lower layer Libraries
#include"DIO_Interface.h"

/*own libraries*/
#include"LED_Config.h"
#include"LED_Private.h"

/*Linking Configuration*/


u8 G_u8LEDsNum = LED_NUM ;


/*LED Port Number options:
 * 1- DIO_PORTA
 * 2- DIO_PORTB
 * 3- DIO_PORTC
 * 4- DIO_PORTD*/


/*LED Pin Number Options:
 * 1- PIN0
 * 2- PIN1
 * 3- PIN2
 * 4- PIN3
 * 5- PIN4
 * 6- PIN5
 * 7- PIN6
 * 8- PIN7 */

/*LED initial State options:
 * 1- PIN_HIGH
 * 2- PIN_LOW*/

LED_t G_LED_tLEDsArrConfig[LED_NUM] =
{
		{DIO_PORTA,PIN0,PIN_LOW},
		{DIO_PORTB,PIN2,PIN_HIGH},
		{DIO_PORTA,PIN7,PIN_LOW},
		{DIO_PORTD,PIN1,PIN_HIGH},
		{DIO_PORTC,PIN0,PIN_LOW},
		{DIO_PORTB,PIN5,PIN_HIGH},
		{DIO_PORTA,PIN6,PIN_LOW},
		{DIO_PORTD,PIN4,PIN_HIGH}
};
