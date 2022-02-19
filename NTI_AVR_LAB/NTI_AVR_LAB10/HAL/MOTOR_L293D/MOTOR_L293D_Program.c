/*
 * MOTOR_L293D_Program.c
 *
 *  Created on: Feb 14, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*Public libraries*/
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/ERROR_STATE.h"

//lower layer Libraries
#include"../../MCAL/DIO_Interface.h"

/*own libraries*/
#include"MOTOR_293D_Private.h"

#include"MOTOR_293D_Config.h"


/*Delay Function*/
#include<util/delay.h>


/**/
ES_t MOTOR_293D_ES_tInit(void)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;
	DIO_ES_tSetPinDirection(IN1_GRP,IN1_PIN,PIN_OUTPUT);
	DIO_ES_tSetPinDirection(IN2_GRP,IN2_PIN,PIN_OUTPUT);
	DIO_ES_tSetPinDirection(EN_GRP,EN_PIN,PIN_OUTPUT);

	DIO_ES_tSetPinValue(IN1_GRP,IN1_PIN,PIN_HIGH);
	DIO_ES_tSetPinValue(IN2_GRP,IN2_PIN,PIN_HIGH);
	DIO_ES_tSetPinValue(EN_GRP,EN_PIN,PIN_HIGH);

	LOC_ES_tErrorState = ES_OK ;
	return LOC_ES_tErrorState ;
}

/**/
ES_t MOTOR_293D_ES_tStartWithDirection(u8 Copy_u8Direction,u8 Copy_u8Speed)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;
	switch(Copy_u8Direction)
	{
	case CW:
		DIO_ES_tSetPinValue(IN1_GRP,IN1_PIN,PIN_LOW);
		DIO_ES_tSetPinValue(IN2_GRP,IN2_PIN,PIN_HIGH);
		break ;
	case CCW:
		DIO_ES_tSetPinValue(IN1_GRP,IN1_PIN,PIN_HIGH);
		DIO_ES_tSetPinValue(IN2_GRP,IN2_PIN,PIN_LOW);
		break ;
	default :
		/*Do Nothing*/
		break ;
	}

	DIO_ES_tSetPinValue(EN_GRP,EN_PIN,Copy_u8Speed);

	LOC_ES_tErrorState = ES_OK ;

	return LOC_ES_tErrorState ;
}
/**/
ES_t MOTOR_293D_ES_tStop(void)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;

//	DIO_ES_tSetPinValue(IN1_GRP,IN1_PIN,PIN_LOW);
//	DIO_ES_tSetPinValue(IN2_GRP,IN2_PIN,PIN_LOW);

	DIO_ES_tSetPinValue(IN1_GRP,IN1_PIN,PIN_HIGH);
	DIO_ES_tSetPinValue(IN2_GRP,IN2_PIN,PIN_HIGH);

	LOC_ES_tErrorState = ES_OK ;

	return LOC_ES_tErrorState ;
}
