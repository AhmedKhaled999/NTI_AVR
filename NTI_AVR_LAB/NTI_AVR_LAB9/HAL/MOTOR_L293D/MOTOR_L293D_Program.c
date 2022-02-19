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

	DIO_ES_tSetPinDirection(MC1_GRP,MC1_PIN,PIN_OUTPUT);
	DIO_ES_tSetPinDirection(MC2_GRP,MC2_PIN,PIN_OUTPUT);
	DIO_ES_tSetPinDirection(MS_GRP,MS_PIN,PIN_OUTPUT);

	DIO_ES_tSetPinValue(MC1_GRP,MC1_PIN,PIN_LOW);
	DIO_ES_tSetPinValue(MC2_GRP,MC2_PIN,PIN_LOW);
	DIO_ES_tSetPinValue(MS_GRP,MS_PIN,PIN_LOW);

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
		DIO_ES_tSetPinValue(MC1_GRP,MC1_PIN,PIN_HIGH);
		DIO_ES_tSetPinValue(MC2_GRP,MC2_PIN,PIN_LOW);
		DIO_ES_tSetPinValue(MS_GRP,MS_PIN,PIN_HIGH);
		break ;
	case CCW:
		DIO_ES_tSetPinValue(MC1_GRP,MC1_PIN,PIN_LOW);
		DIO_ES_tSetPinValue(MC2_GRP,MC2_PIN,PIN_HIGH);
		DIO_ES_tSetPinValue(MS_GRP,MS_PIN,PIN_HIGH);
		break ;
	default:
		/*Do nothing*/
		break ;
	}

	LOC_ES_tErrorState = ES_OK ;
	return LOC_ES_tErrorState ;


}

/**/
ES_t MOTOR_293D_ES_tStop(void)
{

	ES_t LOC_ES_tErrorState = ES_NOK ;
	DIO_ES_tSetPinValue(MC1_GRP,MC1_PIN,PIN_LOW);
	DIO_ES_tSetPinValue(MC2_GRP,MC2_PIN,PIN_LOW);
	DIO_ES_tSetPinValue(MS_GRP,MS_PIN,PIN_LOW);

	LOC_ES_tErrorState = ES_OK ;
	return LOC_ES_tErrorState ;

}
