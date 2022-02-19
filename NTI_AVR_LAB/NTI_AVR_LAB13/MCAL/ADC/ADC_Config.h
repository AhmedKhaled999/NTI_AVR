/*
 * ADC_Config.h
 *
 *  Created on: Feb 17, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/* 1- PRES_2
 * 2- PRES_4
 * 3- PRES_8
 * 4- PRES_16
 * 5- PRES_32
 * 6- PRES_64
 * 7- PRES_128*/

#define ADC_PRES		   PRES_64

/*Initial channel  0 - 31  */
#define INIT_CHNL		0

/*Initial mode  NORMAL - FREE_RUNNING - TRIGGERED  */
#define INIT_MODE		    NORMAL

/*Initial mode  EXT0 - ANALOG_COMP - TIM0_OVF  */
#define INIT_TRIG_SRC		NORMAL

/*Initial int state  ENABLED - POLLING  */
#define INIT_INT_MODE		POLLING



/*AREF_REF	AVCC_REF	INTERNAL_REF*/
#define ADC_VREF		AVCC_REF

/*LEFT_ADJ		 RIGHT_ADJ*/
#define ADC_ADJ			LEFT_ADJ


#endif /* MCAL_ADC_ADC_CONFIG_H_ */
