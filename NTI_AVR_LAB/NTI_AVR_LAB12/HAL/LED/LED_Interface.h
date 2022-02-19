/*
 * LED_Interface.h
 *
 *  Created on: Feb 12, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_






/*LED Driver Initialization*/
ES_t LED_ES_tInit(LED_t* Copy_PtoArrLED_tConfig);

/*Set LED State*/
ES_t LED_ES_tSetState(LED_t* Copy_PtoArrLED_tInfo,u8 Copy_u8State);

/*Toggle LED State*/
ES_t LED_ES_tToggleState(LED_t* Copy_PtoArrLED_tInfo);

#endif /* LED_INTERFACE_H_ */
