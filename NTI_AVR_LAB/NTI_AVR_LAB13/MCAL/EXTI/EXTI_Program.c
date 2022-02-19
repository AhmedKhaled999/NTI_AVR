/*
 * EXTI_Program.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Ahmed Khaled Hammad
 */


/*Public libraries*/
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/ERROR_STATE.h"

//lower layer Libraries

/*own libraries*/
#include"EXTI_Config.h"
#include"EXTI_Private.h"


extern u8 G_u8EXTI_NUM  ;

static  void(*EXTI_pfunISRFun [ 3 ])(void*) = {NULL,NULL,NULL};

static  void* EXTI_pvidISRParameter [ 3 ] = {NULL,NULL,NULL};

/*initialization Function*/
ES_t EXTI_ES_tInit(EXTI_t * Copy_PTArrConfiguration)
{
	ES_t LOC_ES_tErrorState = ES_NOK;

	u8 Local_u8ExtiIter=0;
	for ( ; Local_u8ExtiIter<G_u8EXTI_NUM ; Local_u8ExtiIter++)
	{
		switch(Copy_PTArrConfiguration[Local_u8ExtiIter].INT_Num)
		{
		case EXTI0:
			MCUCR &=~(3<<0);
			switch (Copy_PTArrConfiguration[Local_u8ExtiIter].SenseLevel)
			{
			case LOW_LEVEL:

				break;

			case ANY_LOGICAL:
				MCUCR |= (1<<0);
				break;

			case FALLING_EDGE:
				MCUCR |= (2<<0);
				break;

			case RISING_EDGE:
				MCUCR |= (3<<0);
				break;
			}
			if (Copy_PTArrConfiguration[Local_u8ExtiIter].INT_Mode == ENABLE)
			{
				GICR |= (1<<6);
			}
			else if (Copy_PTArrConfiguration[Local_u8ExtiIter].INT_Mode == DISABLE)
			{
				GICR &=~(1<<6);
			}
			break;

			case EXTI1:
				MCUCR &=~(3<<2);
				switch (Copy_PTArrConfiguration[Local_u8ExtiIter].SenseLevel)
				{
				case LOW_LEVEL:

					break;

				case ANY_LOGICAL:
					MCUCR |= (1<<2);
					break;

				case FALLING_EDGE:
					MCUCR |= (2<<2);
					break;

				case RISING_EDGE:
					MCUCR |= (3<<2);
					break;
				}
				if (Copy_PTArrConfiguration[Local_u8ExtiIter].INT_Mode == ENABLE)
				{
					GICR |= (1<<7);
				}
				else if (Copy_PTArrConfiguration[Local_u8ExtiIter].INT_Mode == DISABLE)
				{
					GICR &=~(1<<7);
				}

				break;

				case EXTI2:
					MCUCSR &=~(1<<6);
					switch (Copy_PTArrConfiguration[Local_u8ExtiIter].SenseLevel)
					{
					case FALLING_EDGE:

						break;

					case RISING_EDGE:
						MCUCSR |= (1<<6);
						break;
					}
					if (Copy_PTArrConfiguration[Local_u8ExtiIter].INT_Mode == ENABLE)
					{
						GICR |= (1<<5);
					}
					else if (Copy_PTArrConfiguration[Local_u8ExtiIter].INT_Mode == DISABLE)
					{
						GICR &=~(1<<5);
					}
					break;
		}
	}


	return LOC_ES_tErrorState = ES_OK;
}


/*Set Sense Level*/
ES_t EXTI_ES_tSetSenceLevel(EXTI_t * Copy_PTArrInfo,u8 Copy_u8SenceLevel)
{

	ES_t LOC_ES_tErrorState = ES_NOK;

	switch(Copy_PTArrInfo->INT_Num)
	{
	case EXTI0:
		MCUCR &=~(3<<0);
		switch (Copy_PTArrInfo->SenseLevel)
		{
		case LOW_LEVEL:

			break;

		case ANY_LOGICAL:
			MCUCR |= (1<<0);
			break;

		case FALLING_EDGE:
			MCUCR |= (2<<0);
			break;

		case RISING_EDGE:
			MCUCR |= (3<<0);
			break;
		}
		break;
		case EXTI1:
			MCUCR &=~(3<<2);
			switch (Copy_PTArrInfo->SenseLevel)
			{
			case LOW_LEVEL:

				break;

			case ANY_LOGICAL:
				MCUCR |= (1<<2);
				break;

			case FALLING_EDGE:
				MCUCR |= (2<<2);
				break;

			case RISING_EDGE:
				MCUCR |= (3<<2);
				break;
			}
			break;

			case EXTI2:
				MCUCSR &=~(1<<6);
				switch (Copy_PTArrInfo->SenseLevel)
				{
				case FALLING_EDGE:

					break;

				case RISING_EDGE:
					MCUCSR |= (1<<6);
					break;
				}
				break;
	}
	return LOC_ES_tErrorState = ES_OK;
}

/*EXTIerrupt Enable*/
ES_t EXTI_ES_tEnableEXTI(EXTI_t * Copy_PTArrInfo)
{
	ES_t LOC_ES_tErrorState = ES_NOK;

	switch(Copy_PTArrInfo->INT_Num)
	{
	case EXTI0:
		break;
	case EXTI1:
		break;
	case EXTI2:
		break;
	}


	return LOC_ES_tErrorState = ES_OK;
}



/*EXTIerrupt Disable*/
ES_t EXTI_ES_tDisableEXTI(EXTI_t * Copy_PTArrInfo)
{
	ES_t LOC_ES_tErrorState = ES_NOK;

	switch(Copy_PTArrInfo->INT_Num)
	{
	case EXTI0:
		if (Copy_PTArrInfo->INT_Mode == ENABLE)
		{
			GICR |= (1<<6);
		}
		else if (Copy_PTArrInfo->INT_Mode == DISABLE)
		{
			GICR &=~(1<<6);
		}
		break;
	case EXTI1:
		if (Copy_PTArrInfo->INT_Mode == ENABLE)
		{
			GICR |= (1<<7);
		}
		else if (Copy_PTArrInfo->INT_Mode == DISABLE)
		{
			GICR &=~(1<<7);
		}
		break;
	case EXTI2:
		if (Copy_PTArrInfo->INT_Mode == ENABLE)
		{
			GICR |= (1<<5);
		}
		else if (Copy_PTArrInfo->INT_Mode == DISABLE)
		{
			GICR &=~(1<<5);
		}
		break;
	}
	return LOC_ES_tErrorState = ES_OK;
}

ES_t EXTI_ES_tCallBack(EXTI_t * Copy_PTArrInfo,void(*Copy_pfunAppFun)(void*),void * Copy_PtrVidAppParametrer)
{

	ES_t LOC_ES_tErrorState = ES_NOK;

	if(Copy_PTArrInfo != NULL && Copy_pfunAppFun != NULL)
	{

		EXTI_pfunISRFun[Copy_PTArrInfo->INT_Num] = Copy_pfunAppFun ;
		EXTI_pvidISRParameter[Copy_PTArrInfo->INT_Num] = Copy_PtrVidAppParametrer;
	}

	return LOC_ES_tErrorState = ES_OK;

}

void __vector_1 (void)  __attribute__((signal)) ;
void __vector_2 (void)  __attribute__((signal)) ;
void __vector_3 (void)  __attribute__((signal)) ;



void __vector_1 (void)
{
	if(EXTI_pfunISRFun[0] != NULL)
	{
		EXTI_pfunISRFun[0] (EXTI_pvidISRParameter[0]);


	}
}
void __vector_2 (void)
{
	if(EXTI_pfunISRFun[1] != NULL)
		{
			EXTI_pfunISRFun[1] (EXTI_pvidISRParameter[1]);
		}
}
void __vector_3 (void)
{
	if(EXTI_pfunISRFun[2] != NULL)
		{
			EXTI_pfunISRFun[2] (EXTI_pvidISRParameter[2]);
		}
}


