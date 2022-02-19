/*
 * DIO_Config.h
 *
 *  Created on: Feb 12, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

/*Pin Direction State options:
 * 1- PIN_OUTPUT
 * 2- PIN_INPUT*/

//Configure Pins Direction For PORTA
#define PA0_DDR    PIN_INPUT
#define PA1_DDR    PIN_INPUT
#define PA2_DDR    PIN_INPUT
#define PA3_DDR    PIN_INPUT
#define PA4_DDR    PIN_INPUT
#define PA5_DDR    PIN_INPUT
#define PA6_DDR    PIN_INPUT
#define PA7_DDR    PIN_INPUT

//Configure Pins Direction For PORTB
#define PB0_DDR    PIN_INPUT
#define PB1_DDR    PIN_INPUT
#define PB2_DDR    PIN_INPUT
#define PB3_DDR    PIN_INPUT
#define PB4_DDR    PIN_INPUT
#define PB5_DDR    PIN_INPUT
#define PB6_DDR    PIN_INPUT
#define PB7_DDR    PIN_INPUT

//Configure Pins Direction For PORTC
#define PC0_DDR    PIN_OUTPUT
#define PC1_DDR    PIN_OUTPUT
#define PC2_DDR    PIN_OUTPUT
#define PC3_DDR    PIN_OUTPUT
#define PC4_DDR    PIN_INPUT
#define PC5_DDR    PIN_OUTPUT
#define PC6_DDR    PIN_INPUT
#define PC7_DDR    PIN_INPUT

//Configure Pins Direction For PORTD
#define PD0_DDR    PIN_INPUT
#define PD1_DDR    PIN_INPUT
#define PD2_DDR    PIN_INPUT
#define PD3_DDR    PIN_INPUT
#define PD4_DDR    PIN_INPUT
#define PD5_DDR    PIN_INPUT
#define PD6_DDR    PIN_INPUT
#define PD7_DDR    PIN_INPUT


/*Pin State options:
 * 1- PIN_HIGH
 * 2- PIN_LOW
 * 3- DIO_FLOAT
 * 4- DIO_PULLUP*/

//Configure Pins Value For PORTA
#define PA0_PORT    PIN_LOW
#define PA1_PORT    DIO_FLOAT
#define PA2_PORT    DIO_FLOAT
#define PA3_PORT    DIO_FLOAT
#define PA4_PORT    DIO_FLOAT
#define PA5_PORT    DIO_FLOAT
#define PA6_PORT    DIO_FLOAT
#define PA7_PORT    DIO_FLOAT

//Configure Pins Value For PORTB
#define PB0_PORT    PIN_LOW
#define PB1_PORT    PIN_LOW
#define PB2_PORT    PIN_LOW
#define PB3_PORT    PIN_LOW
#define PB4_PORT    PIN_LOW
#define PB5_PORT    PIN_LOW
#define PB6_PORT    PIN_LOW
#define PB7_PORT    PIN_LOW

//Configure Pins Value For PORTC
#define PC0_PORT    PIN_LOW
#define PC1_PORT    PIN_LOW
#define PC2_PORT    PIN_LOW
#define PC3_PORT    PIN_LOW
#define PC4_PORT    PIN_LOW
#define PC5_PORT    PIN_LOW
#define PC6_PORT    PIN_LOW
#define PC7_PORT    PIN_LOW

//Configure Pins Value For PORTD
#define PD0_PORT    PIN_LOW
#define PD1_PORT    PIN_LOW
#define PD2_PORT    PIN_LOW
#define PD3_PORT    PIN_LOW
#define PD4_PORT    PIN_LOW
#define PD5_PORT    PIN_LOW
#define PD6_PORT    PIN_LOW
#define PD7_PORT    PIN_LOW

#endif /* DIO_CONFIG_H_ */
