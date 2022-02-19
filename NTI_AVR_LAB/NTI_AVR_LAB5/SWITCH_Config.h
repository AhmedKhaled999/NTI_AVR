/*
 * SWITCH_Config.h
 *
 *  Created on: Feb 12, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_


/*Switch Port Number options:
 * 1- DIO_PORTA
 * 2- DIO_PORTB
 * 3- DIO_PORTC
 * 4- DIO_PORTD*/

#define SWITCH_PORT          DIO_PORTD


/*Switch Pin Number Options:
 * 1- PIN0
 * 2- PIN1
 * 3- PIN2
 * 4- PIN3
 * 5- PIN4
 * 6- PIN5
 * 7- PIN6
 * 8- PIN7 */

#define SWITCH_PIN           PIN0

/*Switch interface options:
 * 1- DIO_PULLUP
 * 2- DIO_FLOAT*/

#define SWITCH_INTERFACE     DIO_PULLUP


#endif /* SWITCH_CONFIG_H_ */
