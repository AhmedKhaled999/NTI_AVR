/*
 * LED_Progrm.c
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



extern u8 G_u8LEDsNum ;
/*LED Driver Initialization*/
ES_t LED_ES_tInit(LED_t* Copy_PtoArrLED_tConfig)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;
	if(Copy_PtoArrLED_tConfig != NULL)
	{
		u8 LOC_u8Iter = 0;
		for(;LOC_u8Iter < G_u8LEDsNum ;LOC_u8Iter++)
		{
			DIO_ES_tSetPinDirection(Copy_PtoArrLED_tConfig[LOC_u8Iter].LED_PORT,Copy_PtoArrLED_tConfig[LOC_u8Iter].LED_PIN,PIN_OUTPUT);
			DIO_ES_tSetPinValue(Copy_PtoArrLED_tConfig[LOC_u8Iter].LED_PORT,Copy_PtoArrLED_tConfig[LOC_u8Iter].LED_PIN,Copy_PtoArrLED_tConfig[LOC_u8Iter].LED_State);
		}


		 LOC_ES_tErrorState = ES_OK ;

	}
	else
	{
		LOC_ES_tErrorState = ES_NULL_POINTER;
	}


	return LOC_ES_tErrorState ;

}

/*Set LED State*/

ES_t LED_ES_tSetState(LED_t* Copy_PtoArrLED_tInfo,u8 Copy_u8State)
{

	ES_t LOC_ES_tErrorState = ES_NOK ;
	if(Copy_PtoArrLED_tInfo != NULL)
	{
		DIO_ES_tSetPinValue(Copy_PtoArrLED_tInfo->LED_PORT,Copy_PtoArrLED_tInfo->LED_PIN,Copy_u8State);
		LOC_ES_tErrorState = ES_OK;
	}
	else
	{
		LOC_ES_tErrorState = ES_NULL_POINTER;
	}

	return LOC_ES_tErrorState ;

}

/*Toggle LED State*/
ES_t LED_ES_tToggleState(LED_t* Copy_PtoArrLED_tInfo)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;
		if(Copy_PtoArrLED_tInfo != NULL)
		{
			DIO_ES_tTogglePinValue(Copy_PtoArrLED_tInfo->LED_PORT,Copy_PtoArrLED_tInfo->LED_PIN);
			LOC_ES_tErrorState = ES_OK;
		}
		else
		{
			LOC_ES_tErrorState = ES_NULL_POINTER;
		}

		return LOC_ES_tErrorState ;
}

