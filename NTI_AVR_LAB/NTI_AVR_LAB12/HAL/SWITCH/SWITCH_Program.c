/*
 * SWITCH_Program.c
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


extern u8 G_u8SwitchNum ;


/*Switch Driver Initialization*/
ES_t SWITCH_ES_tInit(SWITCH_t* Copy_PtrSWITCH_tConfig )
{
	ES_t LOC_ES_tErrorState = ES_NOK ;
	if(Copy_PtrSWITCH_tConfig !=NULL)
	{
		u8 LOC_u8SwitchIter = 0 ;
		for(;LOC_u8SwitchIter<G_u8SwitchNum;LOC_u8SwitchIter++)
		{
			DIO_ES_tSetPinDirection(Copy_PtrSWITCH_tConfig[LOC_u8SwitchIter].SWITCH_PORT,
					Copy_PtrSWITCH_tConfig[LOC_u8SwitchIter].SWITCH_PIN,PIN_INPUT);
			DIO_ES_tSetPinValue(Copy_PtrSWITCH_tConfig[LOC_u8SwitchIter].SWITCH_PORT,
					Copy_PtrSWITCH_tConfig[LOC_u8SwitchIter].SWITCH_PIN,
					(Copy_PtrSWITCH_tConfig+LOC_u8SwitchIter)->SWITCH_INTERFACE);
		}
	}
	else
	{
		LOC_ES_tErrorState = ES_NULL_POINTER;
	}

   return LOC_ES_tErrorState ;
}
/*Get Switch State*/
ES_t SWITCH_ES_tGetSwitchState(SWITCH_t* Copy_PtrSWITCH_tInfo,u8* Copy_Pu8SwitchState)
{
	ES_t LOC_ES_tErrorState = ES_NOK;

	if(Copy_Pu8SwitchState !=NULL &&
			Copy_Pu8SwitchState !=NULL)
	{
		LOC_ES_tErrorState = DIO_ES_tGetPinValue(Copy_PtrSWITCH_tInfo->SWITCH_PORT,Copy_PtrSWITCH_tInfo->SWITCH_PIN,Copy_Pu8SwitchState);
	}
	else
	{
		LOC_ES_tErrorState = ES_NULL_POINTER ;
	}
	   return LOC_ES_tErrorState ;
}
