/*
 * main.c
 *
 *  Created on: Feb 13, 2022
 *      Author: Ahmed Khaled Hammad
 */


/******************************************************Session10************************************************************
 * -> Learn ADC
 * -> Manage Project'Files
 * -> LAB 13 build App potentiometer with  ADC
 **/
/*Customized Data Type */
#include"../LIB/STD_TYPES.h"
#include"../LIB/ERROR_State.h"

/*DIO Libraries*/
#include"../MCAL/DIO_Interface.h"

/*GIE Driver*/
#include"../MCAL/GIE/GIE_Interface.h"

/*EXTI Driver*/
#include"../MCAL/EXTI/EXTI_Config.h"
#include"../MCAL/EXTI/EXTI_Interface.h"


/*ADC Driver*/
#include"../MCAL/ADC/ADC_Config.h"
#include"../MCAL/ADC/ADC_Interface.h"

/*LCD Driver*/
#include"../HAL/LCD/LCD_Interface.h"


/*SWITCH Driver*/
#include"../HAL/SWITCH/SWITCH_Config.h"
#include"../HAL/SWITCH/SWITCH_Interface.h"
/*STEPPER Driver*/

/*Delay Function*/
#include<util/delay.h>

extern EXTI_t G_AstrEXTI_tConfig[EXTI_NUM] ;

extern SWITCH_t G_SWITCH_tSwitchArrConfig[SW_NUM] ;

/*Application Function*/
void Count_up(void*) ;

void ADC_Fun(void*) ;



typedef struct
{
	u8  count ;
	u16 Read_ADC ;
}ISR_t ;

u8 flag = 0 ;
int main(void)
{

	ISR_t up_count = {0, 0};
	ISR_t ADC_Par =  {0, 0};

	/*PIN_OUTPUT*/
	DIO_ES_tSetPinDirection(DIO_PORTC,PIN2,PIN_OUTPUT);    //Blue
	DIO_ES_tSetPinDirection(DIO_PORTC,PIN0,PIN_OUTPUT);    //RED
	DIO_ES_tSetPinDirection(DIO_PORTC,PIN1,PIN_OUTPUT);    //Yellow | Green
	GIE_ES_tInit();

	/*Initialize EXTI*/
	EXTI_ES_tInit(G_AstrEXTI_tConfig);
	/*Initialize SWITCH*/
	SWITCH_ES_tInit(G_SWITCH_tSwitchArrConfig);
	EXTI_ES_tCallBack(G_AstrEXTI_tConfig,Count_up,&up_count);
	ADC_ES_tCallBack(ADC_Fun,&ADC_Par);

	/*Drivers Initialization*/
	ADC_ES_tInit();
	LCD_ES_tInit();
	ADC_ES_tEnableADC();
	ADC_ES_tEnableADC_INT();
	ADC_ES_tEnableAutoTrigger(2);  //External Interrupt 0
	GIE_ES_tEnable() ;
	/*Clear LCD*/
	LCD_ES_tWriteCommand(1);
	LCD_ES_tWriteString((u8*)"Welcome");
	_delay_ms(1000);
	LCD_ES_tWriteCommand(1);
	LCD_ES_tGoToPosition(1,1);
	LCD_ES_tWriteString((u8*)"Sample= ");
	LCD_ES_tGoToPosition(2,1);
	LCD_ES_tWriteString((u8*)"Digital= ");

	while (1)
	{
		/*	ADC_enuPolling();
		ADC_enuRead(&x);
		ADC_enuClearFlag();*/
		if(flag != up_count.count)
		{
		LCD_ES_tGoToPosition(1,9);
		LCD_ES_tSendIntgerNum(up_count.count);
		LCD_ES_tWriteString((u8*)"  ");
		LCD_ES_tGoToPosition(2,10);
		LCD_ES_tSendIntgerNum(ADC_Par.Read_ADC);
		LCD_ES_tWriteString((u8*)"  ");
		flag = up_count.count ;
	}

		if(200<= (ADC_Par.Read_ADC) && (ADC_Par.Read_ADC)<= 300)
		{
			DIO_ES_tSetPinValue(DIO_PORTC,PIN2,PIN_HIGH);    //Blue
			DIO_ES_tSetPinValue(DIO_PORTC,PIN0,PIN_LOW);    //RED
			DIO_ES_tSetPinValue(DIO_PORTC,PIN1,PIN_LOW);    //Yellow
		}
		else if(300<=ADC_Par.Read_ADC && ADC_Par.Read_ADC<= 400)
		{
			DIO_ES_tSetPinValue(DIO_PORTC,PIN2,PIN_LOW);    //Blue
			DIO_ES_tSetPinValue(DIO_PORTC,PIN0,PIN_HIGH);    //RED
			DIO_ES_tSetPinValue(DIO_PORTC,PIN1,PIN_LOW);    //Yellow
		}
		else if(ADC_Par.Read_ADC > 400)
		{
			DIO_ES_tSetPinValue(DIO_PORTC,PIN2,PIN_LOW);    //Blue
			DIO_ES_tSetPinValue(DIO_PORTC,PIN0,PIN_LOW);    //RED
			DIO_ES_tSetPinValue(DIO_PORTC,PIN1,PIN_HIGH);    //Yellow
		}
		else if(ADC_Par.Read_ADC < 200)
		{
			DIO_ES_tSetPinValue(DIO_PORTC,PIN2,PIN_LOW);    //Blue
			DIO_ES_tSetPinValue(DIO_PORTC,PIN0,PIN_LOW);    //RED
			DIO_ES_tSetPinValue(DIO_PORTC,PIN1,PIN_LOW);    //Yellow
		}
		else
		{
			/*Do Nothing*/
		}

		//_delay_ms(1000);
	}
}

void Count_up(void* para)
{
	((ISR_t*)para)->count++;
}

void ADC_Fun(void*para)
{
	ADC_ES_tRead(&((ISR_t*)para)->Read_ADC);
}
