/*
 * ADC_Program.c
 *
 *  Created on: Feb 17, 2022
 *      Author: Ahmed Khaled Hammad
 */


/*Public libraries*/
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/ERROR_STATE.h"

//lower layer Libraries

/*own libraries*/
#include"ADC_Config.h"
#include"ADC_Private.h"

#include "../interrupt.h"

static  void (* ADC_pfunISRFun)(void*) =NULL;
static void * ADC_pvidISRParameter= NULL;

/**/
ES_t  ADC_ES_tInit(void)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;

#if ADC_PRES == PRES_2
	ADCSRA &= MADC_BIT_MASKING_PRESCALER ;
	ADCSRA |= (1);
#elif ADC_PRES == PRES_4
	ADCSRA &= MADC_BIT_MASKING_PRESCALER ;
	ADCSRA |= (2);
#elif ADC_PRES == PRES_8
	ADCSRA &= MADC_BIT_MASKING_PRESCALER ;
	ADCSRA |= (3);
#elif ADC_PRES == PRES_16
	ADCSRA &= MADC_BIT_MASKING_PRESCALER ;
	ADCSRA |= (4);
#elif ADC_PRES == PRES_32
	ADCSRA &= MADC_BIT_MASKING_PRESCALER ;
	ADCSRA |= (5);
#elif ADC_PRES == PRES_64
	ADCSRA &= MADC_BIT_MASKING_PRESCALER ;
	ADCSRA |= (6);
#elif ADC_PRES == PRES_128
	ADCSRA &= MADC_BIT_MASKING_PRESCALER ;
	ADCSRA |= (7);
#else
#error"ADC PRES selection is wrong"
#endif

#if ADC_VREF == AREF_REF
	ADMUX &= MADC_BIT_MASKING_VREF;
#elif ADC_VREF == AVCC_REF
	ADMUX &= MADC_BIT_MASKING_VREF;
	ADMUX |= (1<<6);
#elif ADC_VREF == INTERNAL_REF
	ADMUX &= MADC_BIT_MASKING_VREF;
	ADMUX |= (3<<6);
#else
#error"ADC Vref selection is wrong"
#endif

#if ADC_ADJ == LEFT_ADJ
	ADMUX |= (1<<5);
#elif ADC_ADJ == RIGHT_ADJ
	ADMUX &=~(1<<5);
#else
#error"ADC ADJ selection is wrong"
#endif

#if INIT_CHNL < 32 && INIT_CHNL >= 0
	ADMUX &= MADC_BIT_MASKING_REG_CHANNEL;
	ADMUX |= (INIT_CHNL);
#else
#error "ADC Channel has a wrong choice"
#endif

#if INIT_INT_MODE == POLLING
	ADCSRA &= ~ (1<<3);
#elif INIT_INT_MODE == ENABLED
	ADCSRA |=  (1<<3);
#else
#error "ADC Channel has a wrong choice"
#endif

#if INIT_MODE == NORMAL
	ADCSRA &=~ (1<<5);
#elif INIT_INT_MODE == FREE_RUNINNG
	SFIOR &= (0x1F);
	ADCSRA |= (1<<5);
#elif INIT_MODE == TRIGGERED
	ADCSRA &=~ (1<<5);
#if INIT_TRIG_SRC	== EXT0
#else
#error  Invalid Triger Mode ...
#endif
#else
#error  "Invalid Choice ..."
#endif

	LOC_ES_tErrorState = ES_OK;
	return LOC_ES_tErrorState ;
}
/**/
ES_t  ADC_ES_tStartConversion(void)
{

	ES_t LOC_ES_tErrorState = ES_NOK ;

	ADCSRA |=(1<<6);

	LOC_ES_tErrorState = ES_OK;
	return LOC_ES_tErrorState ;
}
/**/
ES_t  ADC_ES_tReadHighRegister(u8 * Copy_pu8ReadValue)
{

	ES_t LOC_ES_tErrorState = ES_NOK ;

#if ADC_ADJ == LEFT_ADJ
	*Copy_pu8ReadValue = ADCH;

#elif ADC_ADJ == RIGHT_ADJ
	*Copy_pu8ReadValue  = (ADCL>>2);
	*Copy_pu8ReadValue |= (ADCH<<6);
#else
#error"ADC ADJ selection is wrong"
#endif

	LOC_ES_tErrorState = ES_OK;
	return LOC_ES_tErrorState ;

}
/**/
ES_t ADC_ES_tRead(u16 * Copy_pu16ReadValue)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;

#if ADC_ADJ == LEFT_ADJ
	*Copy_pu16ReadValue  = (ADCL>>6);
	*Copy_pu16ReadValue |= ((u16)ADCH<<2);
#elif ADC_ADJ == RIGHT_ADJ
	*Copy_pu16ReadValue  = ADCL;
	*Copy_pu16ReadValue |= ((u16)ADCH<<8);
#else
#error"ADC ADJ selection is wrong"
#endif

	LOC_ES_tErrorState = ES_OK;
	return LOC_ES_tErrorState ;
}
/**/
ES_t ADC_ES_tCallBack(void (*Copy_pfunAppFun)(void*) , void * Copy_pvidAppParameter)
{

	ES_t LOC_ES_tErrorState = ES_NOK ;
	if (Copy_pfunAppFun != NULL)
	{
		ADC_pfunISRFun = Copy_pfunAppFun;
		ADC_pvidISRParameter = Copy_pvidAppParameter;
	}

	LOC_ES_tErrorState = ES_OK;
	return LOC_ES_tErrorState ;

}
/**/
ES_t ADC_ES_tSelectChannel(u8 Copy_u8ChannelID)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;

	if (Copy_u8ChannelID <= 31 )
	{
		ADMUX &= MADC_BIT_MASKING_REG_CHANNEL; //~0x1F // 0b11100000
		ADMUX |= Copy_u8ChannelID;
	}
	else
	{
		/*Do Nothing*/
	}

	LOC_ES_tErrorState = ES_OK;
	return LOC_ES_tErrorState ;

}
/**/
ES_t ADC_ES_tEnableAutoTrigger(u8 Copy_u8IntSource)
{

	ES_t LOC_ES_tErrorState = ES_NOK ;

	if (Copy_u8IntSource <= 7)
	{
		ADCSRA &=~(1<<5);
		SFIOR  &= MADC_BIT_MASKING_TRIGERSOURCE;

		SFIOR  |= (Copy_u8IntSource <<5);
		ADCSRA |= (1<<5);
	}
	else
	{
		/*Do Nothing*/
	}

	LOC_ES_tErrorState = ES_OK;
	return LOC_ES_tErrorState ;


}
/**/
ES_t ADC_ES_tDisableAutoTrigger(void)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;
	ADCSRA &=~(1<<5);

	LOC_ES_tErrorState = ES_OK;
	return LOC_ES_tErrorState ;

}
/**/
ES_t ADC_ES_tPolling(void)
{

	ES_t LOC_ES_tErrorState = ES_NOK ;

	while (! ((ADCSRA>>4)&1) );

	LOC_ES_tErrorState = ES_OK;
	return LOC_ES_tErrorState ;
}
/**/
ES_t ADC_ES_tClearFlag(void)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;

	ADCSRA |=(1<<4);

	LOC_ES_tErrorState = ES_OK;
	return LOC_ES_tErrorState ;
}
/**/

ES_t ADC_ES_tEnableADC(void)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;

	ADCSRA |= (1<<7);

	LOC_ES_tErrorState = ES_OK;
	return LOC_ES_tErrorState ;
}
/**/

ES_t ADC_ES_tDisableADC(void)
{

	ES_t LOC_ES_tErrorState = ES_NOK ;

	ADCSRA &=~(1<<7);

	LOC_ES_tErrorState = ES_OK;
	return LOC_ES_tErrorState ;
}
/**/
ES_t ADC_ES_tEnableADC_INT(void)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;

	ADCSRA |= (1<<3);

	LOC_ES_tErrorState = ES_OK;
	return LOC_ES_tErrorState ;
}
/**/
ES_t ADC_ES_tDisableADC_INT(void)
{

	ES_t LOC_ES_tErrorState = ES_NOK ;

	ADCSRA &=~(1<<3);

	LOC_ES_tErrorState = ES_OK;
	return LOC_ES_tErrorState ;

}

ISR(VECT_ADC)
{
	if (ADC_pfunISRFun != NULL)
	{
		ADC_pfunISRFun( ADC_pvidISRParameter );
	}
}

