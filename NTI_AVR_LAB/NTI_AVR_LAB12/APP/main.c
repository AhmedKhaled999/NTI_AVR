/*
 * main.c
 *
 *  Created on: Feb 13, 2022
 *      Author: Ahmed Khaled Hammad
 */


/******************************************************Session9************************************************************
 * -> Learn Interrupt
 * -> Learn about callback Function
 * -> LAB 12 build App with switch and relay with interrupt
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

/*LCD Driver*/
#include"../HAL/LCD/LCD_Interface.h"

/*SWITCH Driver*/
#include"../HAL/SWITCH/SWITCH_Config.h"
#include"../HAL/SWITCH/SWITCH_Interface.h"
/*STEPPER Driver*/

/*Delay Function*/
#include<util/delay.h>


/*Application Function*/
void BUZZER(void*) ;

void RELAY(void*) ;

extern EXTI_t G_AstrEXTI_tConfig[EXTI_NUM] ;

extern SWITCH_t G_SWITCH_tSwitchArrConfig[SW_NUM] ;


typedef struct
{

	u8 count ;
	u8 group ;
	u8 pin ;
	u8 flag ;
}ISR_t ;

int main(void)
{

	ISR_t up = {0, DIO_PORTC ,PIN2, 0 };
	ISR_t up2 = {0, DIO_PORTC ,PIN1, 0 };

	GIE_ES_tInit();
	LCD_ES_tInit();
	/*Interrupt Direction INT0,INT1 */
	DIO_ES_tSetPinDirection(DIO_PORTD,PIN2,PIN_INPUT);
	DIO_ES_tSetPinDirection(DIO_PORTD,PIN3,PIN_INPUT);

	/*PIN_OUTPUT*/

	DIO_ES_tSetPinDirection(DIO_PORTC,PIN2,PIN_OUTPUT);
	DIO_ES_tSetPinDirection(DIO_PORTC,PIN1,PIN_OUTPUT);
	/*Initialize EXTI*/
	EXTI_ES_tInit(G_AstrEXTI_tConfig);
	/*Initialize SWITCH*/
	SWITCH_ES_tInit(G_SWITCH_tSwitchArrConfig);
	EXTI_ES_tCallBack(G_AstrEXTI_tConfig,BUZZER,&up);
	EXTI_ES_tCallBack(&(G_AstrEXTI_tConfig[1]),RELAY,&up2) ;
	GIE_ES_tEnable();
	while(1)
	{
		if(up.flag == 1)
		{
			LCD_ES_tGoToPosition(1,8);
			LCD_ES_tWriteString("       ");
			LCD_ES_tGoToPosition(1,8);
			LCD_ES_tSendIntgerNum(up.count);
			up.flag = 0;
		}
		if(up2.flag == 1)
		{
			LCD_ES_tGoToPosition(2,8);
			LCD_ES_tWriteString("       ");
			LCD_ES_tGoToPosition(2,8);
			LCD_ES_tSendIntgerNum(up2.count);
			up2.flag = 0;
		}

	}
	return 0 ;
}

void BUZZER(void* para)
{
	//DIO_ES_tTogglePinValue(DIO_PORTC,PIN5);
	DIO_ES_tTogglePinValue(((ISR_t*)para)->group,((ISR_t*)para)->pin);
	((ISR_t*)para)->count++;
	((ISR_t*)para)->flag=1;
}

void RELAY(void*para)
{
	//DIO_ES_tTogglePinValue(DIO_PORTC,PIN4);
	DIO_ES_tTogglePinValue(((ISR_t*)para)->group,((ISR_t*)para)->pin);
	((ISR_t*)para)->count++;
	((ISR_t*)para)->flag=1;
}
