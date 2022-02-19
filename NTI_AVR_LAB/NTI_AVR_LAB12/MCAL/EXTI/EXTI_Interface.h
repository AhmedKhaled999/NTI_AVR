/*
 * EXTI_Interface.h
 *
 *  Created on: Feb 16, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_


/*initialization Function*/
ES_t EXTI_ES_tInit(EXTI_t * Copy_PTArrConfiguration);


/*Set Sense Level*/
ES_t EXTI_ES_tSetSenceLevel(EXTI_t * Copy_PTArrInfo,u8 Copy_u8SenceLevel);


/*Interrupt Enable*/
ES_t EXTI_ES_tEnableEXTI(EXTI_t * Copy_PTArrInfo);


/*Interrupt Disable*/
ES_t EXTI_ES_tEnableEXTI(EXTI_t * Copy_PTArrInfo);

/**/

ES_t EXTI_ES_tCallBack(EXTI_t * Copy_PTArrInfo,void(*Copy_pfunAppFun)(void*),void * Copy_PtrVidAppParametrer);


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
