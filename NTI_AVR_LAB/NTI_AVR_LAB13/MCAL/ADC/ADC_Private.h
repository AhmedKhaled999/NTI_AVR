/*
 * ADC_Private.h
 *
 *  Created on: Feb 17, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define POLLING			98
#define ENABLED			120

#define NORMAL			103
#define FREE_RUNINNG	106
#define TRIGGERED		108

#define EXT0 			111
#define TIM0_OVF		109


#define MADC_BIT_MASKING_PRESCALER     0xF8
#define MADC_BIT_MASKING_CHANNEL       0x07
#define MADC_BIT_MASKING_REG_CHANNEL   0xE0
#define MADC_BIT_MASKING_VREF          0x3F
#define MADC_BIT_MASKING_TRIGERSOURCE          0x1F


#define PRES_2		45
#define PRES_4		95
#define PRES_8		26
#define PRES_16		13
#define PRES_32		49
#define PRES_64		17
#define PRES_128	10


#define AREF_REF		45
#define AVCC_REF	 	65
#define INTERNAL_REF	96

#define LEFT_ADJ		94
#define RIGHT_ADJ		23

#define ADMUX			*((u8*)0x27)
#define ADCSRA			*((u8*)0x26)
#define ADCH			*((volatile u8*)0x25)
#define ADCL			*((volatile u8*)0x24)

#define SFIOR			*((u8*)0x50)


#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
