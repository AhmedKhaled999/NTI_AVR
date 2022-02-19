/*
 * KPAD_Config.h
 *
 *  Created on: Feb 13, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef HAL_KPAD_KPAD_CONFIG_H_
#define HAL_KPAD_KPAD_CONFIG_H_

/*PORT Options:
 * 1- DIO_PORTA
 * 2- DIO_PORTB
 * 3- DIO_PORTC
 * 4- DIO_PORTD*/

/*PIN Options:
 * 1- PIN0
 * 2- PIN1
 * 3- PIN2
 * 4- PIN3
 * 5- PIN4
 * 6- PIN5
 * 7- PIN6
 * 8- PIN7*/



#define ROW_NUM     4
#define COL_NUM     4

#define R1_GRP     DIO_PORTB
#define R1_PIN     PIN4

#define R2_GRP     DIO_PORTB
#define R2_PIN     PIN5

#define R3_GRP     DIO_PORTB
#define R3_PIN     PIN6

#define R4_GRP     DIO_PORTB
#define R4_PIN     PIN7


#define C1_GRP     DIO_PORTD
#define C1_PIN     PIN2

#define C2_GRP     DIO_PORTD
#define C2_PIN     PIN3

#define C3_GRP     DIO_PORTD
#define C3_PIN     PIN4

#define C4_GRP     DIO_PORTD
#define C4_PIN     PIN5


#define   KEY_VALUES    {{'7','8','9','+'},\
						 {'4','5','6','-'},\
						 {'1','2','3','*'},\
						 {'c','0','=','/'}}

#endif /* HAL_KPAD_KPAD_CONFIG_H_ */
