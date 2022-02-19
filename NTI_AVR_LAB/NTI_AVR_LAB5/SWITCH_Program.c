/*
 * SWITCH_Program.c
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
#include"SWITCH_Config.h"
#include"SWITCH_Private.h"



/*Switch Driver Initialization*/
ES_t SWITCH_ES_tInit(void)
{
	ES_t LOC_ES_tErrorState = ES_NOK ,LOC_ES_tErrorStateArray[2] ;
	LOC_ES_tErrorStateArray[0] = DIO_ES_tSetPinDirection(SWITCH_PORT,SWITCH_PIN,PIN_INPUT);
	LOC_ES_tErrorStateArray[1] = DIO_ES_tSetPinValue(SWITCH_PORT,SWITCH_PIN,SWITCH_INTERFACE);

	if(LOC_ES_tErrorStateArray[0]==ES_OK && LOC_ES_tErrorStateArray[1] == ES_OK)
	{
		LOC_ES_tErrorState = ES_OK;
	}

   return LOC_ES_tErrorState ;
}
/*Get Switch State*/
ES_t SWITCH_ES_tGetSwitchState(u8* Copy_Pu8SwitchState)
{
	ES_t LOC_ES_tErrorState = ES_NOK;

	if(Copy_Pu8SwitchState !=NULL)
	{
		LOC_ES_tErrorState = DIO_ES_tGetPinValue(SWITCH_PORT,SWITCH_PIN,Copy_Pu8SwitchState);
	}
	else
	{
		LOC_ES_tErrorState = ES_NULL_POINTER ;
	}
	   return LOC_ES_tErrorState ;
}
