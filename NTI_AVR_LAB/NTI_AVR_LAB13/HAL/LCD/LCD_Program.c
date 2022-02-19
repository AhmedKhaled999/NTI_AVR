/*
 * LCD_Program.c
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
#include"LCD_Config.h"
#include"LCD_Private.h"


/*Delay Function*/
#include<util/delay.h>


/*LCD Driver Initialization*/
ES_t  LCD_ES_tInit(void)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;

	DIO_ES_tSetPinDirection(RS_GRP, RS_PIN, PIN_OUTPUT );
	DIO_ES_tSetPinDirection(RW_GRP, RW_PIN, PIN_OUTPUT );
	DIO_ES_tSetPinDirection(EN_GRP, EN_PIN, PIN_OUTPUT );

	DIO_ES_tSetPinDirection(D7_GRP, D7_PIN, PIN_OUTPUT );
	DIO_ES_tSetPinDirection(D6_GRP, D6_PIN, PIN_OUTPUT );
	DIO_ES_tSetPinDirection(D5_GRP, D5_PIN, PIN_OUTPUT );
	DIO_ES_tSetPinDirection(D4_GRP, D4_PIN, PIN_OUTPUT );

#if LCD_MODE == EIGHT_BIT

	DIO_ES_tSetPinDirection(D3_GRP, D3_PIN, PIN_OUTPUT );
	DIO_ES_tSetPinDirection(D2_GRP, D2_PIN, PIN_OUTPUT );
	DIO_ES_tSetPinDirection(D1_GRP, D1_PIN, PIN_OUTPUT );
	DIO_ES_tSetPinDirection(D0_GRP, D0_PIN, PIN_OUTPUT );

	_delay_ms(35);

	DIO_ES_tSetPinValue(RS_GRP, RS_PIN, PIN_LOW);
	LCD_ES_tWriteNLatch(0x38);

#elif LCD_MODE == FOUR_BIT

	DIO_ES_tSetPinValue(RS_GRP, RS_PIN, PIN_LOW);
	DIO_ES_tSetPinValue(EN_GRP, EN_PIN, PIN_LOW);
	DIO_ES_tSetPinValue(RW_GRP, RW_PIN, PIN_LOW);

	DIO_ES_tSetPinValue(D7_GRP, D7_PIN, 0 );
	DIO_ES_tSetPinValue(D6_GRP, D6_PIN, 0 );
	DIO_ES_tSetPinValue(D5_GRP, D5_PIN, 1 );
	DIO_ES_tSetPinValue(D4_GRP, D4_PIN, 0 );

	DIO_ES_tSetPinValue(EN_GRP, EN_PIN, PIN_HIGH );
	_delay_ms(1);
	DIO_ES_tSetPinValue(EN_GRP, EN_PIN, PIN_LOW );
	_delay_ms(30);

	LCD_ES_tWriteNLatch(0x28);

#else
#error "LCD mode configuration is wrong"
#endif

	//Display Control
	DIO_ES_tSetPinValue(RS_GRP, RS_PIN, PIN_LOW);
	LCD_ES_tWriteNLatch(0x0F);
	//_delay_ms(1);


	//Display Clear
	DIO_ES_tSetPinValue(RS_GRP, RS_PIN, PIN_LOW);
	LCD_ES_tWriteNLatch(0x01);
	//_delay_ms(2);

	//Entry Mode
	DIO_ES_tSetPinValue(RS_GRP, RS_PIN, PIN_LOW);
	LCD_ES_tWriteNLatch(0x06);
	//_delay_ms(1);


	return LOC_ES_tErrorState ;

}
/**************************************************************************************************************************************/
/*LCD write Data*/
ES_t   LCD_ES_tWriteData(u8 Copy_u8Data)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;

	DIO_ES_tSetPinValue(RS_GRP , RS_PIN , PIN_HIGH);
	LCD_ES_tWriteNLatch(Copy_u8Data);
	LOC_ES_tErrorState = ES_OK ;

	return LOC_ES_tErrorState ;
}
/****************************************************************************************************************************************/
/*LCD write command*/
ES_t   LCD_ES_tWriteCommand(u8 Copy_u8Command)
{
	ES_t LOC_ES_tErrorState = ES_NOK ;

	DIO_ES_tSetPinValue(RS_GRP , RS_PIN , PIN_LOW);
	LCD_ES_tWriteNLatch(Copy_u8Command);
	LOC_ES_tErrorState = ES_OK ;

	return LOC_ES_tErrorState ;
}

/******************************************************************************************************************************************/
static ES_t LCD_ES_tWriteNLatch(u8 Copy_u8Byte)
{
	ES_t LOC_ES_tErrorState = ES_NOK;

#if LCD_MODE == EIGHT_BIT

	DIO_ES_tSetPinValue(EN_GRP, EN_PIN, PIN_LOW);
	DIO_ES_tSetPinValue(RW_GRP, RW_PIN, PIN_LOW);

	DIO_ES_tSetPinValue(D7_GRP, D7_PIN, ((Copy_u8Byte>>7)&1) );
	DIO_ES_tSetPinValue(D6_GRP, D6_PIN, ((Copy_u8Byte>>6)&1) );
	DIO_ES_tSetPinValue(D5_GRP, D5_PIN, ((Copy_u8Byte>>5)&1) );
	DIO_ES_tSetPinValue(D4_GRP, D4_PIN, ((Copy_u8Byte>>4)&1) );

	DIO_ES_tSetPinValue(D3_GRP, D3_PIN, ((Copy_u8Byte>>3)&1) );
	DIO_ES_tSetPinValue(D2_GRP, D2_PIN, ((Copy_u8Byte>>2)&1) );
	DIO_ES_tSetPinValue(D1_GRP, D1_PIN, ((Copy_u8Byte>>1)&1) );
	DIO_ES_tSetPinValue(D0_GRP, D0_PIN, ((Copy_u8Byte>>0)&1) );

	DIO_ES_tSetPinValue(EN_GRP, EN_PIN, PIN_HIGH );
	_delay_ms(1);
	DIO_ES_tSetPinValue(EN_GRP, EN_PIN, PIN_LOW );

	_delay_ms(30);


#elif LCD_MODE == FOUR_BIT

	DIO_ES_tSetPinValue(EN_GRP, EN_PIN, PIN_LOW);
	DIO_ES_tSetPinValue(RW_GRP, RW_PIN, PIN_LOW);

	DIO_ES_tSetPinValue(D7_GRP, D7_PIN, ((Copy_u8Byte>>7)&1) );
	DIO_ES_tSetPinValue(D6_GRP, D6_PIN, ((Copy_u8Byte>>6)&1) );
	DIO_ES_tSetPinValue(D5_GRP, D5_PIN, ((Copy_u8Byte>>5)&1) );
	DIO_ES_tSetPinValue(D4_GRP, D4_PIN, ((Copy_u8Byte>>4)&1) );

	DIO_ES_tSetPinValue(EN_GRP, EN_PIN, PIN_HIGH );
	_delay_ms(1);
	DIO_ES_tSetPinValue(EN_GRP, EN_PIN, PIN_LOW );
	_delay_ms(30);

	DIO_ES_tSetPinValue(D7_GRP, D7_PIN, ((Copy_u8Byte>>3)&1) );
	DIO_ES_tSetPinValue(D6_GRP, D6_PIN, ((Copy_u8Byte>>2)&1) );
	DIO_ES_tSetPinValue(D5_GRP, D5_PIN, ((Copy_u8Byte>>1)&1) );
	DIO_ES_tSetPinValue(D4_GRP, D4_PIN, ((Copy_u8Byte>>0)&1) );

	DIO_ES_tSetPinValue(EN_GRP, EN_PIN, PIN_HIGH );
	_delay_ms(1);
	DIO_ES_tSetPinValue(EN_GRP, EN_PIN, PIN_LOW );
	_delay_ms(30);

#else
#error "LCD mode configuration is wrong"
#endif

	return LOC_ES_tErrorState;
}
/***********************************************************************************************************************/
ES_t LCD_ES_tWriteString(u8* Copy_u8Data)
{

	ES_t LOC_ES_tErrorState = ES_NOK;
	u8 LOC_u8Iterator = 0 ;
	while(Copy_u8Data[LOC_u8Iterator]!='\0')
	{
		//LCD_enuWriteData(Copy_u8Data[LOC_u8Iterator]);
		DIO_ES_tSetPinValue(RS_GRP , RS_PIN , PIN_HIGH);
		LCD_ES_tWriteNLatch(Copy_u8Data[LOC_u8Iterator]);
		LOC_u8Iterator++;
	}

	return LOC_ES_tErrorState;

}
/***********************************************************************************************************************/
ES_t LCD_ES_tSendIntgerNum(s32 Copy_s32Num)
{
	ES_t LOC_ES_tErrorState = ES_NOK;

	s8 LOC_s8Sign = -1;
	u8 LOC_u8ArrIndex = 0;
	u8 LOC_u8ArrNmber[10];
	/*Check Sign*/
	if(Copy_s32Num < 0)
	{
		/*display Sign*/
		DIO_ES_tSetPinValue(RS_GRP , RS_PIN , PIN_HIGH);
		LCD_ES_tWriteNLatch('-');
		/*make The number Positive*/
		Copy_s32Num *=LOC_s8Sign ;
	}
	else
	{
		/*Parsing the Positive Number*/
		while(Copy_s32Num!=0)
		{
			LOC_u8ArrNmber[LOC_u8ArrIndex] = (Copy_s32Num%10);
			Copy_s32Num/=10;
			LOC_u8ArrIndex++;
		}
		for(s8 i = LOC_u8ArrIndex-1 ; i>=0;i--)
		{
			DIO_ES_tSetPinValue(RS_GRP , RS_PIN , PIN_HIGH);
			LCD_ES_tWriteNLatch(LOC_u8ArrNmber[i]+'0');

		}
	}

	return LOC_ES_tErrorState;
}

/************************************************************************************************************************/
/*LCD Create SpecialCharacter 8 Bits*/
ES_t  LCD_ES_tCustomAlphChar(u8 Copy_u8PatternNumber, u8* PCopy_u8Pattern)
{
	ES_t LOC_ES_tErrorState = ES_NOK;
	/*you have only 8 patterns to be customized */

	if(Copy_u8PatternNumber<PATTERN_MAX_NUMBER)
	{
		/*Address counter point on CGRAM*/
		DIO_ES_tSetPinValue(RS_GRP , RS_PIN , PIN_LOW);
		LCD_ES_tWriteNLatch((CGRAM_OFFSET + (Copy_u8PatternNumber*PATTERN_SIZE)));
		LOC_ES_tErrorState = ES_OK ;
		/*Write your pattern in CGRAM*/
		for(u8 i=0;i<8;i++)
		{
			DIO_ES_tSetPinValue(RS_GRP , RS_PIN , PIN_HIGH);
			LCD_ES_tWriteNLatch(PCopy_u8Pattern[i]);
		}
		LOC_ES_tErrorState = ES_OK;
	}
	else
	{
		LOC_ES_tErrorState = ES_OUT_OF_RANGE ;
	}
	return LOC_ES_tErrorState;

}
/********************************************************************************************************************************************************/

/*LCD Go To Position*/

ES_t   LCD_ES_tGoToPosition(u8 Copy_u8Row,u8 Copy_u8Col)
{
	ES_t LOC_ES_tErrorState = ES_NOK;
	u8 LOC_u8ArrRow[2] = {0x80,0xC0};
	if( (1<=Copy_u8Row && Copy_u8Row<=2 ) &&
			(1<=Copy_u8Col && Copy_u8Col<=16))
	{
		DIO_ES_tSetPinValue(RS_GRP , RS_PIN , PIN_LOW);
		LCD_ES_tWriteNLatch(LOC_u8ArrRow[Copy_u8Row-1]+ Copy_u8Col-1);
		LOC_ES_tErrorState = ES_OK ;
	}
	else
	{
		LOC_ES_tErrorState = ES_OUT_OF_RANGE ;
	}

	return LOC_ES_tErrorState;
}

/***********************************************************************************************************************************************************/
