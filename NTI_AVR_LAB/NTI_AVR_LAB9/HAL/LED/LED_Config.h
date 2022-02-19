/*
 * LED_Config.h
 *
 *  Created on: Feb 12, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_


#define LED_NUM    8


typedef struct{
	u8 LED_PORT;
	u8 LED_PIN;
	u8 LED_State;
}LED_t;



#endif /* LED_CONFIG_H_ */
