/*
 * DIO_Program.c
 *
 *  Created on: Feb DIO_BIT_MASK2, 2022
 *      Author: Ahmed Khaled Hammad
 */



/*Public libraries*/
#include"STD_TYPES.h"
#include"ERROR_STATE.h"

//lower layer Libraries


/*own libraries*/
#include"DIO_Config.h"
#include"DIO_Private.h"


/*DIO Initialization*/
ES_t DIO_ES_tInit(void)
{
	ES_t LOC_ES_tErrorState = ES_NOK;
	/*Pins Direction according to your Configuration */
	DDRA = CONCAT(PA7_DDR,PA6_DDR,PA5_DDR,PA4_DDR,PA3_DDR,PA2_DDR,PA1_DDR,PA0_DDR);
	DDRB = CONCAT(PB7_DDR,PB6_DDR,PB5_DDR,PB4_DDR,PB3_DDR,PB2_DDR,PB1_DDR,PB0_DDR);
	DDRC = CONCAT(PC7_DDR,PC6_DDR,PC5_DDR,PC4_DDR,PC3_DDR,PC2_DDR,PC1_DDR,PC0_DDR);
	DDRD = CONCAT(PD7_DDR,PD6_DDR,PD5_DDR,PD4_DDR,PD3_DDR,PD2_DDR,PD1_DDR,PD0_DDR);

	/*Pins Initial Value according to your configuration */
	PORTA = CONCAT(PA7_PORT,PA6_PORT,PA5_PORT,PA4_PORT,PA3_PORT,PA2_PORT,PA1_PORT,PA0_PORT);
	PORTB = CONCAT(PB7_PORT,PB6_PORT,PB5_PORT,PB4_PORT,PB3_PORT,PB2_PORT,PB1_PORT,PB0_PORT);
	PORTC = CONCAT(PC7_PORT,PC6_PORT,PC5_PORT,PC4_PORT,PC3_PORT,PC2_PORT,PC1_PORT,PC0_PORT);
	PORTD = CONCAT(PD7_PORT,PD6_PORT,PD5_PORT,PD4_PORT,PD3_PORT,PD2_PORT,PD1_PORT,PD0_PORT);

	/*
#if PA0_DDR == PIN_OUTPUT

#elif PA0_DDR == PIN_INPUT

#endif
	 */
	LOC_ES_tErrorState = ES_OK ;
	return LOC_ES_tErrorState ;
}
/*Set Pin Direction*/
ES_t DIO_ES_tSetPinDirection(u8 Copy_u8PortNumber, u8 Copy_u8PinNumber , u8 Copy_PinDirection)
{
	ES_t LOC_ES_tErrorState = ES_NOK;
	if(Copy_u8PortNumber>= DIO_PORTD &&
			Copy_u8PinNumber>=PIN7 &&
			Copy_PinDirection>=PIN_OUTPUT)
	{
		LOC_ES_tErrorState = ES_OUT_OF_RANGE ;
	}
	else
	{
		switch(Copy_u8PortNumber)
		{

		case DIO_PORTA:
			if(Copy_PinDirection==PIN_OUTPUT)
				DDRA |= (DIO_BIT_MASK<<Copy_u8PinNumber);
			else
				DDRA &=~(DIO_BIT_MASK<<Copy_u8PinNumber);
			break ;
		case DIO_PORTB:
			DDRB &=~(DIO_BIT_MASK<<Copy_u8PinNumber);
			DDRB |= (Copy_PinDirection<<Copy_u8PinNumber);
			break ;
		case DIO_PORTC:
			if(Copy_PinDirection==PIN_OUTPUT)
				DDRC |= (DIO_BIT_MASK<<Copy_u8PinNumber);
			else
				DDRC &=~(DIO_BIT_MASK<<Copy_u8PinNumber);
			break ;
		case DIO_PORTD:
			if(Copy_PinDirection==PIN_OUTPUT)
				DDRD |= (DIO_BIT_MASK<<Copy_u8PinNumber);
			else
				DDRD &=~(DIO_BIT_MASK<<Copy_u8PinNumber);
			break ;
		default:
			break ;
			/*Do Nothing*/
		}
		LOC_ES_tErrorState = ES_OK ;
	}

	return LOC_ES_tErrorState ;
}
/*Set Pin Value*/
ES_t DIO_ES_tSetPinValue(u8 Copy_u8PortNumber, u8 Copy_u8PinNumber , u8 Copy_PinValue)
{
	ES_t LOC_ES_tErrorState = ES_NOK;
	if(Copy_u8PortNumber>= DIO_PORTD &&
			Copy_u8PinNumber>=PIN7 &&
			Copy_PinValue>=PIN_HIGH)
	{
		LOC_ES_tErrorState  = ES_OUT_OF_RANGE ;
	}
	else
	{
		switch(Copy_u8PortNumber)
		{

		case DIO_PORTA:
			if(Copy_PinValue==PIN_HIGH)
				PORTA |= (DIO_BIT_MASK<<Copy_u8PinNumber);
			else
				PORTA &=~(DIO_BIT_MASK<<Copy_u8PinNumber);
			break ;
		case DIO_PORTB:
			PORTB &=~(DIO_BIT_MASK<<Copy_u8PinNumber);
			PORTB |= (Copy_PinValue<<Copy_u8PinNumber);
			break ;
		case DIO_PORTC:
			if(Copy_PinValue==PIN_HIGH)
				PORTC |= (DIO_BIT_MASK<<Copy_u8PinNumber);
			else
				PORTC &=~(DIO_BIT_MASK<<Copy_u8PinNumber);
			break ;
		case DIO_PORTD:
			if(Copy_PinValue==PIN_HIGH)
				PORTD |= (DIO_BIT_MASK<<Copy_u8PinNumber);
			else
				PORTD &=~(DIO_BIT_MASK<<Copy_u8PinNumber);
			break ;
		default:
			break ;
			/*Do Nothing*/
		}
		LOC_ES_tErrorState = ES_OK ;
	}

	return LOC_ES_tErrorState ;
}
/*Get Pin Value*/
ES_t DIO_ES_tGetPinValue(u8 Copy_u8PortNumber, u8 Copy_u8PinNumber , u8* Copy_PinValue)
{
	ES_t LOC_ES_tErrorState = ES_NOK;
	if(Copy_PinValue!=NULL)
	{
		if(Copy_u8PortNumber>= DIO_PORTD &&
				Copy_u8PinNumber>=PIN7 )
		{
			LOC_ES_tErrorState = ES_OUT_OF_RANGE ;
		}
		else
		{
			switch(Copy_u8PortNumber)
			{

			case DIO_PORTA:
				*Copy_PinValue = (PINA>>Copy_u8PinNumber)&DIO_BIT_MASK ;
				break ;
			case DIO_PORTB:
				*Copy_PinValue = (PINB>>Copy_u8PinNumber)&DIO_BIT_MASK ;
				break ;
			case DIO_PORTC:
				*Copy_PinValue = (PINC>>Copy_u8PinNumber)&DIO_BIT_MASK ;
				break ;
			case DIO_PORTD:
				*Copy_PinValue = (PIND>>Copy_u8PinNumber)&DIO_BIT_MASK ;
				break ;
			default:
				break ;
				/*Do Nothing*/
			}
			LOC_ES_tErrorState = ES_OK ;
		}
	}
	else
	{
		LOC_ES_tErrorState = ES_NULL_POINTER ;
	}
	return LOC_ES_tErrorState ;
}
/*Toggle Pin Value*/
ES_t DIO_ES_tTogglePinValue(u8 Copy_u8PortNumber, u8 Copy_u8PinNumber)
{
	ES_t LOC_ES_tErrorState = ES_NOK;
	if(Copy_u8PortNumber>= DIO_PORTD &&
			Copy_u8PinNumber>=PIN7 )
	{
		LOC_ES_tErrorState = ES_OUT_OF_RANGE ;
	}
	else
	{
		switch(Copy_u8PortNumber)
		{

		case DIO_PORTA:
			PORTA ^= (DIO_BIT_MASK<<Copy_u8PinNumber) ;
			break ;
		case DIO_PORTB:
			PORTB ^= (DIO_BIT_MASK<<Copy_u8PinNumber) ;
			break ;
		case DIO_PORTC:
			PORTC ^= (DIO_BIT_MASK<<Copy_u8PinNumber) ;
			break ;
		case DIO_PORTD:
			PORTD ^= (DIO_BIT_MASK<<Copy_u8PinNumber) ;
			break ;
		default:
			break ;
			/*Do Nothing*/
		}
		LOC_ES_tErrorState = ES_OK ;
	}

	return LOC_ES_tErrorState ;
}
