/*
 * KPAD_Interface.h
 *
 *  Created on: Feb 13, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef HAL_KPAD_KPAD_INTERFACE_H_
#define HAL_KPAD_KPAD_INTERFACE_H_

/*KeyPad Initialization*/
ES_t KPAD_ES_tInit(void);


/*Get Pressed Key*/
ES_t KPAD_ES_tGetPressedKey(u8* Copy_u8PressedKey);


#define KEYPAD_NOT_PRESSED     0xff

#endif /* HAL_KPAD_KPAD_INTERFACE_H_ */
