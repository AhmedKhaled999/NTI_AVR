/*
 * main.c
 *
 *  Created on: Feb 13, 2022
 *      Author: Ahmed Khaled Hammad
 */


/******************************************************Session7************************************************************
 * -> Learn DC Motor / Relay /H-Bridge / Opto_cupler
 * -> Manage Project'Files
 * -> LAB 8 build MOTOR_L293D Driver with prebuild Configuration
 * -> TASK 7  Control DC Motor Direction
 **/
/*Customized Data Type */
#include"../LIB/STD_TYPES.h"
#include"../LIB/ERROR_State.h"

/*DIO Libraries*/
#include"../MCAL/DIO_Interface.h"
/*LCD Driver*/
#include"../HAL/LCD/LCD_Interface.h"
/*MOTOR_L293D Driver*/
#include"../HAL/MOTOR_L293D/MOTOR_293D_Interface.h"

/*Delay Function*/
#include<util/delay.h>


int main(void)
{

	MOTOR_293D_ES_tInit();
	while(1)
	{
        MOTOR_293D_ES_tStartWithDirection(CW,FULL_SPEED);
		_delay_ms(1000);
		 MOTOR_293D_ES_tStartWithDirection(CCW,FULL_SPEED);
		_delay_ms(1000);
        MOTOR_293D_ES_tStop();
		_delay_ms(2000);

	}

	return 0 ;
}
