/*
 * main.c
 *
 *  Created on: Feb 13, 2022
 *      Author: Ahmed Khaled Hammad
 */


/******************************************************Session8************************************************************
 * -> Learn Stepper Motor
 * -> Manage Project'Files
 * -> LAB 8 build STEPPER_ULN2003 Driver with prebuild Configuration and  control the stepper motor
 * -> TASK 7  Control DC Motor Direction
 **/
/*Customized Data Type */
#include"../LIB/STD_TYPES.h"
#include"../LIB/ERROR_State.h"

/*DIO Libraries*/
#include"../MCAL/DIO_Interface.h"
/*LCD Driver*/
#include"../HAL/LCD/LCD_Interface.h"
/*STEPPER Driver*/
#include"../HAL/STEPPER_ULN2003/STEPPER_Interface.h"

/*Delay Function*/
#include<util/delay.h>


int main(void)
{
	STEPPER_ES_tInit();
	while(1)
	{
		STEPPER_ES_tFullCycle(CCW,LOW_SPEED);
		_delay_ms(30);
		STEPPER_ES_tFullCycle(CW,HIGH_SPEED);
		_delay_ms(1000);
		STEPPER_ES_tRotationAngle(CCW,MID_SPEED,45);
		_delay_ms(1000);
		STEPPER_ES_tRotationAngle(CCW,HIGH_SPEED,270);
		_delay_ms(1000);
		STEPPER_ES_tRotationAngle(CW,LOW_SPEED,45);
		_delay_ms(1000);
	}
	return 0 ;
}
