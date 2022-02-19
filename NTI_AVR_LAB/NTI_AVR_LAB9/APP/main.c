/*
 * main.c
 *
 *  Created on: Feb 13, 2022
 *      Author: Ahmed Khaled Hammad
 */

/******************************************************Session6************************************************************
 * -> Learn about KeyPad
 * -> Manage Project'Files
 * -> LAB 8 build KeyPad Driver with prebuild Configuration and Display Login system
 * -> TASK 7 Simple Calculator
 **/

/*Customized Data Type */
#include"../LIB/STD_TYPES.h"
#include"../LIB/ERROR_State.h"

/*DIO Libraries*/
#include"../MCAL/DIO_Interface.h"
/*LCD Driver*/
#include"../HAL/LCD/LCD_Interface.h"
/*KEYPAD Driver*/
#include"../HAL/KPAD/KPAD_Interface.h"

/*Delay Function*/
#include<util/delay.h>

/*helper Function*/
u8 App_VidStringCompare(u8* Copy_Pu8String1,u8* Copy_Pu8String2);


u8 G_u8PressedKey ;
int main(void)
{
	/*pattern for 7arami in Arabic */
	//pattern for Alph character
	u8 pattern2[8]={0x06,0x04,0x0E,0x00,0x04,0x04,0x04,0x00};
	// pattern for 7a8
	u8 pattern0[8]={0x00,0x00,0x08,0x14,0x02,0x1F,0x00,0x00};
	// pattern for mem
	u8 pattern3[8]={0x00,0x00,0x00,0x00,0x02,0x1D,0x02,0x00};
	// pattern for ya8
	u8 pattern4[8]={0x00,0x00,0x00,0x13,0x12,0x1E,0x00,0x0C};
	// pattern for ra8
	u8 pattern1[8]={0x00,0x00,0x00,0x03,0x02,0x02,0x04,0x18};

	u8 LOC_u8ArrCorrectPassword []= "123*/";
	u8 LOC_u8ArrUserPassword [10] ={0} ;
	/*Initialize DIO Driver */
	DIO_ES_tInit();
	/*Initialize KeyPad Driver */
	KPAD_ES_tInit();
	/*initialize LCD Driver according to your Configuration*/
	/*Initialize LCD*/
	LCD_ES_tInit();
	/*Initialize patterns*/
	LCD_ES_tCustomAlphChar(0, pattern0);
	LCD_ES_tCustomAlphChar(1, pattern1);
	LCD_ES_tCustomAlphChar(2, pattern2);
	LCD_ES_tCustomAlphChar(3, pattern3);
	LCD_ES_tCustomAlphChar(4, pattern4);

	LCD_ES_tGoToPosition(1,3);
	LCD_ES_tWriteString((u8*)"WELCOME TO");
	LCD_ES_tGoToPosition(2,3);
	LCD_ES_tWriteString((u8*)"LOGIN SYSTEM");
	_delay_ms(1000);
	LCD_ES_tWriteCommand(0x01);
	LCD_ES_tGoToPosition(1,5);
	LCD_ES_tWriteString((u8*)"ENTER THE");
	LCD_ES_tGoToPosition(2,5);
	LCD_ES_tWriteString((u8*)"PASSWORD");

	u8 iter = 0 ;
	u8 State ;
	u8 trials = 3 ;
	u8 LED_Num = 0 ;
	u8 LED_State = 0 ;
	while(1)
	{

		KPAD_ES_tGetPressedKey(&G_u8PressedKey);
		if(G_u8PressedKey != 0xff)
		{  /*clear display*/
			LCD_ES_tWriteCommand(0x01);
			LOC_u8ArrUserPassword[iter] = G_u8PressedKey ;
			LCD_ES_tWriteData(G_u8PressedKey) ;
			iter++ ;
		}
		if(iter == 5)
		{
			LCD_ES_tGoToPosition(2,1);
			State = App_VidStringCompare(LOC_u8ArrCorrectPassword,LOC_u8ArrUserPassword);
			if(State == 1) //Correct
			{

				page0:
				/*clear display*/
				LCD_ES_tWriteCommand(0x01);
				LCD_ES_tGoToPosition(1,1);
				LCD_ES_tWriteString((u8*)"Correct Password");
				LCD_ES_tGoToPosition(2,1);
				LCD_ES_tWriteString((u8*)"Enter The State Number");
				_delay_ms(1000);
				/*clear display*/
				LCD_ES_tWriteCommand(0x01);
				LCD_ES_tGoToPosition(1,1);
				LCD_ES_tWriteString((u8*)"1 -LED1|2 -LED2");
				LCD_ES_tGoToPosition(2,6);
				LCD_ES_tWriteString((u8*)"3 -LED3");

				KPAD_ES_tGetPressedKey(&G_u8PressedKey);
				while(G_u8PressedKey == 0xff)
					KPAD_ES_tGetPressedKey(&G_u8PressedKey);
				if(G_u8PressedKey != 0xff)
				{  /*clear display*/
					LCD_ES_tWriteCommand(0x01);
					LED_Num= G_u8PressedKey ;
					LCD_ES_tWriteData(G_u8PressedKey) ;
					if(LED_Num == '1')
					{

						page1:
						/*clear display*/
						LCD_ES_tWriteCommand(0x01);
						LCD_ES_tWriteString((u8*)"Enter The Option");
						_delay_ms(1000);
						/*clear display*/
						LCD_ES_tWriteCommand(0x01);
						LCD_ES_tGoToPosition(1,1);
						LCD_ES_tWriteString((u8*)"1-LED1_ON|3-BACK");
						LCD_ES_tGoToPosition(2,1);
						LCD_ES_tWriteString((u8*)"2-LED1_OFF");

						KPAD_ES_tGetPressedKey(&G_u8PressedKey);
						while(G_u8PressedKey == 0xff)
							KPAD_ES_tGetPressedKey(&G_u8PressedKey);
						if(G_u8PressedKey != 0xff)
						{  /*clear display*/
							LCD_ES_tWriteCommand(0x01);
							LED_State= G_u8PressedKey ;
							LCD_ES_tWriteData(G_u8PressedKey) ;
							if(LED_State == '1')
							{
								/*clear display*/
								LCD_ES_tWriteCommand(0x01);
								LCD_ES_tGoToPosition(1,1);
								LCD_ES_tWriteString((u8*)"LED1 Is ON");
								DIO_ES_tSetPinValue(DIO_PORTC,PIN0,PIN_HIGH);
								LCD_ES_tGoToPosition(2,1);
								LCD_ES_tWriteString((u8*)"Enter 3 ->BACK");

								KPAD_ES_tGetPressedKey(&G_u8PressedKey);
								while(G_u8PressedKey == 0xff)
									KPAD_ES_tGetPressedKey(&G_u8PressedKey);
								if(G_u8PressedKey != 0xff)
								{  /*clear display*/
									LCD_ES_tWriteCommand(0x01);
									LED_State= G_u8PressedKey ;
									LCD_ES_tWriteData(G_u8PressedKey) ;
									if(LED_State == '3')
									{
										goto page1;
									}
									else
									{
										LCD_ES_tWriteString((u8*)"In Valid Option:(");
									}
								}
							}
							else if(LED_State == '2')
							{
								/*clear display*/
								LCD_ES_tWriteCommand(0x01);
								LCD_ES_tGoToPosition(1,1);
								LCD_ES_tWriteString((u8*)"LED1 Is OFF");
								DIO_ES_tSetPinValue(DIO_PORTC,PIN0,PIN_LOW);
								LCD_ES_tGoToPosition(2,1);
								LCD_ES_tWriteString((u8*)"Enter 3 ->BACK");
								KPAD_ES_tGetPressedKey(&G_u8PressedKey);
								while(G_u8PressedKey == 0xff)
									KPAD_ES_tGetPressedKey(&G_u8PressedKey);
								if(G_u8PressedKey != 0xff)
								{  /*clear display*/
									LCD_ES_tWriteCommand(0x01);
									LED_State= G_u8PressedKey ;
									LCD_ES_tWriteData(G_u8PressedKey) ;
									if(LED_State == '3')
									{
										goto page1;
									}
									else
									{
										LCD_ES_tWriteString((u8*)"In Valid Option:(");
									}
								}
							}
							else if(LED_State == '3')
							{
								goto page0;
							}
							else
							{
								LCD_ES_tWriteString((u8*)"In Valid Option:(");
							}
						}
						else if(LED_Num == '2')
						{
							/*clear display*/
							LCD_ES_tWriteCommand(0x01);
							LCD_ES_tWriteString((u8*)"Enter The Option");
							_delay_ms(1000);
							/*clear display*/
							LCD_ES_tWriteCommand(0x01);
							LCD_ES_tGoToPosition(1,1);
							LCD_ES_tWriteString((u8*)"1-LED2_ON|3-BACK");
							LCD_ES_tGoToPosition(2,1);
							LCD_ES_tWriteString((u8*)"2-LED2_OFF");
						}
						else if(LED_Num == '3')
						{
							/*clear display*/
							LCD_ES_tWriteCommand(0x01);
							LCD_ES_tWriteString((u8*)"Enter The Option");
							_delay_ms(1000);
							/*clear display*/
							LCD_ES_tWriteCommand(0x01);
							LCD_ES_tGoToPosition(1,1);
							LCD_ES_tWriteString((u8*)"1-LED3_ON|3-BACK");
							LCD_ES_tGoToPosition(2,1);
							LCD_ES_tWriteString((u8*)"2-LED3_OFF");
						}
						else
						{
							LCD_ES_tWriteCommand(0x01);
							LCD_ES_tWriteString((u8*)"In Valid Option:(");
							_delay_ms(1000);
						}

					}
					iter = 0;
					trials = 3 ;
				}
			}
				else{
					trials-- ;
					if(trials == 0 )
					{
						/*clear display*/
						LCD_ES_tWriteCommand(0x01);
						LCD_ES_tGoToPosition(1,1);
						LCD_ES_tWriteString((u8*)"Emsk 7ramy:(");
						_delay_ms(1000);
						LCD_ES_tWriteCommand(0x01);
						/*Arabic*/
						LCD_ES_tWriteCommand(0x04);
						LCD_ES_tGoToPosition(1,7);
						LCD_ES_tWriteData(0);
						LCD_ES_tWriteData(1);
						LCD_ES_tWriteData(2);
						LCD_ES_tWriteData(3);
						LCD_ES_tWriteData(4);
						DIO_ES_tSetPinValue(2,5,1);
					}
					else{
						/*clear display*/
						LCD_ES_tWriteCommand(0x01);
						LCD_ES_tGoToPosition(1,1);
						LCD_ES_tWriteString((u8*)"Wrong Password");
						LCD_ES_tGoToPosition(2,1);
						LCD_ES_tWriteString((u8*)"you have ");
						LCD_ES_tSendIntgerNum(trials);
						LCD_ES_tWriteString((u8*)"trials");
					}
					iter = 0;
				}
			}
			else
			{/*Do Nothing*/}

		}
		return 0 ;
	}


	u8 App_VidStringCompare(u8* Copy_Pu8String1,u8* Copy_Pu8String2)
	{
		u8 Password_state = 0 ; //false
		u8  i = 0 ;
		while(Copy_Pu8String1[i] != 0 )
		{
			if(Copy_Pu8String1[i] != Copy_Pu8String2[i])
			{
				Password_state = 0; ; //false
				return Password_state ;
			}
			else
			{
				Password_state = 1 ; //false
			}
			i++ ;
		}

		return Password_state ;
	}
