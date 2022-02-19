/*
 * STEPPER_Program.c
 *
 *  Created on: Feb 15, 2022
 *      Author: Ahmed Khaled Hammad
 */


/*Public libraries*/
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/ERROR_STATE.h"

//lower layer Libraries
#include"../../MCAL/DIO_Interface.h"

/*own libraries*/
#include"STEPPER_Private.h"

#include"STEPPER_Config.h"


/*Delay Function*/
#include<util/delay.h>





/*Stepper_ULN2003 Initialization*/
ES_t STEPPER_ES_tInit(void)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;
	DIO_ES_tSetPinDirection(BLUE_GRP,BLUE_PIN,PIN_OUTPUT);
	DIO_ES_tSetPinDirection(PINK_GRP,PINK_PIN,PIN_OUTPUT);
	DIO_ES_tSetPinDirection(YELLOW_GRP,YELLOW_PIN,PIN_OUTPUT);
	DIO_ES_tSetPinDirection(ORANGE_GRP,ORANGE_PIN,PIN_OUTPUT);
	/*
	DIO_ES_tSetPinValue(BLUE_GRP,BLUE_PIN,PIN_HIGH);
	DIO_ES_tSetPinValue(PINK_GRP,PINK_PIN,PIN_HIGH);
	DIO_ES_tSetPinValue(YELLOW_GRP,YELLOW_PIN,PIN_HIGH);
	DIO_ES_tSetPinValue(ORANGE_GRP,ORANGE_PIN,PIN_HIGH);
	 */
	LOC_ES_tErrorState = ES_OK ;
	return LOC_ES_tErrorState ;
}

/**/
ES_t STEPPER_ES_tFullCycle(u8 Copy_u8Direction,u8 Copy_u8Speed)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;
	u8 State = 15 ;
	switch(Copy_u8Direction)
	{
	case CW:
		for(u16 i = 0 ; i<2048 ; i++)
		{
			State &=~(1<<(i%4));
			DIO_ES_tSetPinValue(ORANGE_GRP,ORANGE_PIN,(((State>>0)&1)));
			DIO_ES_tSetPinValue(YELLOW_GRP,YELLOW_PIN,(((State>>1)&1)));
			DIO_ES_tSetPinValue(PINK_GRP,PINK_PIN,(((State>>2)&1)));
			DIO_ES_tSetPinValue(BLUE_GRP,BLUE_PIN,(((State>>3)&1)));

			State = 0x0F ;
			_delay_ms(Copy_u8Speed);
		}
		break ;
	case CCW:

		for(u16 i = 0 ; i<2048 ; i++)
		{

			State &=~(1<<(i%4));
			DIO_ES_tSetPinValue(BLUE_GRP,BLUE_PIN,(((State>>0)&1)));
			DIO_ES_tSetPinValue(PINK_GRP,PINK_PIN,(((State>>1)&1)));
			DIO_ES_tSetPinValue(YELLOW_GRP,YELLOW_PIN,(((State>>2)&1)));
			DIO_ES_tSetPinValue(ORANGE_GRP,ORANGE_PIN,(((State>>3)&1)));
			State = 0x0F ;
			_delay_ms(Copy_u8Speed);
		}
		break ;
	default :
		/* Do Nothing*/
		break ;

	}

	return LOC_ES_tErrorState ;


}

/**/
ES_t STEPPER_ES_tRotationAngle(u8 Copy_u8Direction,u8 Copy_u8Speed,u16 Copy_u8Angle)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;

	u8 State = 15 ;
	u16 Steps =  (Copy_u8Angle * 2048UL) / 360UL;
	if(Copy_u8Direction == CCW)
	{
		for(u16 i = 0 ; i<Steps ; i++)
		{
			State &=~(1<<(i%4));
			DIO_ES_tSetPinValue(BLUE_GRP,BLUE_PIN,(((State>>0)&1)));
			DIO_ES_tSetPinValue(PINK_GRP,PINK_PIN,(((State>>1)&1)));
			DIO_ES_tSetPinValue(YELLOW_GRP,YELLOW_PIN,(((State>>2)&1)));
			DIO_ES_tSetPinValue(ORANGE_GRP,ORANGE_PIN,(((State>>3)&1)));
			State = 0x0F ;
			_delay_ms(Copy_u8Speed);
		}
	}
	if(Copy_u8Direction == CW)
	{
		for(u16 i = 0 ; i<Steps ; i++)
		{
			State &=~(1<<(i%4));
			DIO_ES_tSetPinValue(ORANGE_GRP,ORANGE_PIN,(((State>>0)&1)));
			DIO_ES_tSetPinValue(YELLOW_GRP,YELLOW_PIN,(((State>>1)&1)));
			DIO_ES_tSetPinValue(PINK_GRP,PINK_PIN,(((State>>2)&1)));
			DIO_ES_tSetPinValue(BLUE_GRP,BLUE_PIN,(((State>>3)&1)));

			State = 0x0F ;
			_delay_ms(Copy_u8Speed);
		}

	}
	return LOC_ES_tErrorState ;
}

