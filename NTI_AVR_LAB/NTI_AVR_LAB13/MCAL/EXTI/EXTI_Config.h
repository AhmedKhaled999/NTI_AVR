/*
 * EXTI_Config.h
 *
 *  Created on: Feb 16, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

#define EXTI_NUM   1


typedef struct
{
u8 SenseLevel;
u8 INT_Mode;
u8 INT_Num;
}EXTI_t ;



#define  EXTI0        0
#define  EXTI1        1
#define  EXTI2        2


#define ENABLE       1

#define DISABLE       0


#define  LOW_LEVEL                0
#define  ANY_LOGICAL              1
#define  FALLING_EDGE             2
#define  RISING_EDGE              3





#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
