/*
 * main.c
 *
 *  Created on: Feb 13, 2022
 *      Author: Ahmed Khaled Hammad
 */


/******************************************************Session5************************************************************
 * -> Learn about Display Types
 * -> Learn about Character LCD
 * -> LAB 7 build LCD Driver with prebuild Configuration and Display Character / string /Number
 * -> TASK 5 Display your name in Arabic
 **/

/*Customized Data Type */
#include"STD_TYPES.h"
#include"ERROR_State.h"

/*DIO Libraries*/
//#include"DIO_Interface.h"
/*LCD Driver*/
#include"LCD_Interface.h"
/*Switch Driver*/
#include"SWITCH_Config.h"
#include"SWITCH_Interface.h"

/*Delay Function*/
#include<util/delay.h>

u8 right ;
extern SWITCH_t G_SWITCH_tSwitchArrConfig[SW_NUM] ;
int main(void)
{
	/*pattern for Ahmed in Arabic */
	//pattern for Alph character
	u8 pattern0[8]={0x06,0x04,0x0E,0x00,0x04,0x04,0x04,0x00};
	// pattern for 7a8
	u8 pattern1[8]={0x00,0x00,0x08,0x14,0x02,0x1F,0x00,0x00};
	// pattern for mem
	u8 pattern2[8]={0x00,0x00,0x00,0x00,0x02,0x1D,0x02,0x00};
	// pattern for dal
	u8 pattern3[8]={0x00,0x00,0x01,0x01,0x01,0x1F,0x00,0x00};

	 /*Initialize Switch */
	SWITCH_ES_tInit(G_SWITCH_tSwitchArrConfig);
	/*initialize LCD Driver according to your Configuration*/
	 /*Initialize LCD*/
	LCD_ES_tInit();
	LCD_ES_tWriteString("Ahmed Khaled Hammad Ali");
	LCD_ES_tGoToPosition(2,1);
   LCD_ES_tSendIntgerNum(5980);
	_delay_ms(1000);
	LCD_ES_tWriteCommand(0x01);

//	LCD_ES_tWriteCommand(0x40);
//	for(u8 i ;i<8 ;i++)
//	{
//		LCD_ES_tWriteData(pattern0[i]);
//	}
//	LCD_ES_tGoToPosition(1,15);
//
//	LCD_ES_tWriteData(0);

//	LCD_ES_tGoToPosition(1,1);
//
//	/*Initialize patterns*/
    LCD_ES_tCustomAlphChar(0, pattern0);
	LCD_ES_tCustomAlphChar(1, pattern1);
	LCD_ES_tCustomAlphChar(2, pattern2);
	LCD_ES_tCustomAlphChar(3, pattern3);

	LCD_ES_tWriteCommand(0x04);
	LCD_ES_tGoToPosition(1,16);
    LCD_ES_tWriteData(0);
	//LCD_ES_tGoToPosition(1,15);
	LCD_ES_tWriteData(1);
	//LCD_ES_tGoToPosition(1,14);
	LCD_ES_tWriteData(2);
	//LCD_ES_tGoToPosition(1,13);
	LCD_ES_tWriteData(3);
	//LCD_ES_tGoToPosition(1,12);



	while(1)
	{
//		SWITCH_ES_tGetSwitchState(G_SWITCH_tSwitchArrConfig,&right);
//		if(!right)  //pressed
//		{
//			LCD_ES_tWriteCommand(0x18);
//			while(!right)
//				SWITCH_ES_tGetSwitchState(G_SWITCH_tSwitchArrConfig,&right);
//		}
	}
	return 0 ;
}
