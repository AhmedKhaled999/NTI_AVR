/*
 * SWITCH_Config.c
 *
 *  Created on: Feb 12, 2022
 *      Author: Ahmed Khaled Hammad
 */


/*Public libraries*/
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/ERROR_STATE.h"

//lower layer Libraries
#include"../../MCAL/DIO_Interface.h"

/*own libraries*/
#include"SWITCH_Config.h"
#include"SWITCH_Private.h"

/*Linking Configuration*/


u8 G_u8SwitchNum = SW_NUM ;


/*Switch Port Number options:
 * 1- DIO_PORTA
 * 2- DIO_PORTB
 * 3- DIO_PORTC
 * 4- DIO_PORTD*/


/*Switch Pin Number Options:
 * 1- PIN0
 * 2- PIN1
 * 3- PIN2
 * 4- PIN3
 * 5- PIN4
 * 6- PIN5
 * 7- PIN6
 * 8- PIN7 */

/*Switch interface options:
 * 1- DIO_PULLUP
 * 2- DIO_FLOAT*/

SWITCH_t G_SWITCH_tSwitchArrConfig[SW_NUM] =
{
		{DIO_PORTD,PIN2,DIO_PULLUP},
		//{DIO_PORTD,PIN1,DIO_PULLUP}
};
