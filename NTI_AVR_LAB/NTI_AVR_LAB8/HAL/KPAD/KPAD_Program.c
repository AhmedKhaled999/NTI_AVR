/*
 * KPAD_Program.c
 *
 *  Created on: Feb 13, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*Public libraries*/
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/ERROR_STATE.h"



/*lower Libraries*/
#include"../../MCAL/DIO_Interface.h"

/*own library*/
#include"KPAD_Private.h"
#include"KPAD_Config.h"

/*Delay Function*/
#include<util/delay.h>


/*KeyPad Initialization*/
ES_t KPAD_ES_tInit(void)
{
	ES_t LOC_ES_tErrorState =ES_NOK ;
	/*Set Row Input Direction */
	DIO_ES_tSetPinDirection(R1_GRP,R1_PIN,PIN_INPUT);
	DIO_ES_tSetPinDirection(R2_GRP,R2_PIN,PIN_INPUT);
	DIO_ES_tSetPinDirection(R3_GRP,R3_PIN,PIN_INPUT);
	DIO_ES_tSetPinDirection(R4_GRP,R4_PIN,PIN_INPUT);
	/*Active internal Pull up in Row*/
	DIO_ES_tSetPinValue(R1_GRP,R1_PIN,DIO_PULLUP);
	DIO_ES_tSetPinValue(R2_GRP,R2_PIN,DIO_PULLUP);
	DIO_ES_tSetPinValue(R3_GRP,R3_PIN,DIO_PULLUP);
	DIO_ES_tSetPinValue(R4_GRP,R4_PIN,DIO_PULLUP);

	/*Set COL Output Direction */
	DIO_ES_tSetPinDirection(C1_GRP,C1_PIN,PIN_OUTPUT);
	DIO_ES_tSetPinDirection(C2_GRP,C2_PIN,PIN_OUTPUT);
	DIO_ES_tSetPinDirection(C3_GRP,C3_PIN,PIN_OUTPUT);
	DIO_ES_tSetPinDirection(C4_GRP,C4_PIN,PIN_OUTPUT);

	/*Cols Initial Vales High*/
	DIO_ES_tSetPinValue(C1_GRP,C1_PIN,PIN_HIGH);
	DIO_ES_tSetPinValue(C2_GRP,C2_PIN,PIN_HIGH);
	DIO_ES_tSetPinValue(C3_GRP,C3_PIN,PIN_HIGH);
	DIO_ES_tSetPinValue(C4_GRP,C4_PIN,PIN_HIGH);
	 LOC_ES_tErrorState =ES_OK ;
	return LOC_ES_tErrorState;
}


/*Get Pressed Key*/
ES_t KPAD_ES_tGetPressedKey(u8* Copy_u8PressedKey)
{

	ES_t LOC_ES_tErrorState =ES_NOK ;
	    u8 Local_u8RowIter =0;
		u8 Local_u8ColIter =0;
		u8 Local_u8Value=0xff;

		u8 Local_u8ColGrp[COL_NUM]={C1_GRP,C2_GRP,C3_GRP,C4_GRP};
		u8 Local_u8ColPin[COL_NUM]={C1_PIN,C2_PIN,C3_PIN,C4_PIN};

		u8 Local_u8RowGrp[ROW_NUM]={R1_GRP,R2_GRP,R3_GRP,R4_GRP};
		u8 Local_u8RowPin[ROW_NUM]={R1_PIN,R2_PIN,R3_PIN,R4_PIN};

           /*Dummy value*/
		*Copy_u8PressedKey = KEYPAD_NOT_PRESSED;

		for(; Local_u8ColIter < COL_NUM; Local_u8ColIter++)
		{
			/*Active Column [i]*/
			DIO_ES_tSetPinValue(Local_u8ColGrp[Local_u8ColIter],
					Local_u8ColPin[Local_u8ColIter], PIN_LOW);

			for (Local_u8RowIter=0;Local_u8RowIter<ROW_NUM; Local_u8RowIter++)
			{
				DIO_ES_tGetPinValue(Local_u8RowGrp[Local_u8RowIter],
						Local_u8RowPin[Local_u8RowIter], &Local_u8Value);

				if ( ! Local_u8Value)
				{
					_delay_ms(10);// to avoid bouncing
					DIO_ES_tGetPinValue(Local_u8RowGrp[Local_u8RowIter],
										Local_u8RowPin[Local_u8RowIter], &Local_u8Value);
					if ( ! Local_u8Value)
					{
						//prevent holding press
						while ( ! Local_u8Value)
							DIO_ES_tGetPinValue(Local_u8RowGrp[Local_u8RowIter],
									Local_u8RowPin[Local_u8RowIter], &Local_u8Value);
						//return switch value
						u8 Local_Au8KeyValues[ROW_NUM][COL_NUM]=KEY_VALUES;
						*Copy_u8PressedKey=Local_Au8KeyValues[Local_u8RowIter][Local_u8ColIter];
						 LOC_ES_tErrorState =ES_OK ;
					}
				}
			}

			DIO_ES_tSetPinValue(Local_u8ColGrp[Local_u8ColIter],
					Local_u8ColPin[Local_u8ColIter], PIN_HIGH);
		}
	return LOC_ES_tErrorState;

}
