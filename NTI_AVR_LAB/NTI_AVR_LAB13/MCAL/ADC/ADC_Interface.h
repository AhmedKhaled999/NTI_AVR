/*
 * ADC_Interface.h
 *
 *  Created on: Feb 17, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_



ES_t  ADC_ES_tInit(void);

ES_t  ADC_ES_tStartConversion(void);

ES_t  ADC_ES_tReadHighRegister(u8 * Copy_pu8ReadValue);

ES_t ADC_ES_tRead(u16 * Copy_pu16ReadValue);

ES_t ADC_ES_tCallBack(void (*Copy_pfunAppFun)(void*) , void * Copy_pvidAppParameter);

ES_t ADC_ES_tSelectChannel(u8 Copy_u8ChannelID);

ES_t ADC_ES_tEnableAutoTrigger(u8 Copy_u8IntSource);

ES_t ADC_ES_tDisableAutoTrigger(void);

ES_t ADC_ES_tPolling(void);

ES_t ADC_ES_tClearFlag(void);

ES_t ADC_ES_tEnableADC(void);

ES_t ADC_ES_tDisableADC(void);

ES_t ADC_ES_tEnableADC_INT(void);

ES_t ADC_ES_tDisableADC_INT(void);




#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
