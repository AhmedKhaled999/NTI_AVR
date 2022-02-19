/*
 * LCD_Config.h
 *
 *  Created on: Feb 12, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*			Mode : EIGHT_BIT -  FOUR_BIT     */
#define LCD_MODE		FOUR_BIT

/*			Control Pins					*/
#define RS_GRP			DIO_PORTB
#define RS_PIN			PIN0

#define RW_GRP			DIO_PORTB
#define RW_PIN			PIN1

#define EN_GRP			DIO_PORTB
#define EN_PIN			PIN2


/*				Data Pins		*/

#define D7_GRP			DIO_PORTB
#define D7_PIN			PIN7

#define D6_GRP			DIO_PORTB
#define D6_PIN			PIN6

#define D5_GRP			DIO_PORTB
#define D5_PIN			PIN5

#define D4_GRP			DIO_PORTB
#define D4_PIN			PIN4

#define D3_GRP			DIO_PORTA
#define D3_PIN			PIN2

#define D2_GRP			DIO_PORTA
#define D2_PIN			PIN0

#define D1_GRP			DIO_PORTA
#define D1_PIN			PIN7

#define D0_GRP			DIO_PORTA
#define D0_PIN			PIN3


#define SIGNED              0
#define UNSIGNED            1



#endif /* LCD_CONFIG_H_ */
