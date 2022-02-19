/*

 * EXTI_Config.c
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

u8 G_u8EXTI_NUM = EXTI_NUM ;

EXTI_t G_AstrEXTI_tConfig[EXTI_NUM] =
{

		{FALLING_EDGE,ENABLE,EXTI0},
		//{FALLING_EDGE,ENABLE,EXTI1},
		//{RISING_EDGE,DISABLE,EXTI2}
};
