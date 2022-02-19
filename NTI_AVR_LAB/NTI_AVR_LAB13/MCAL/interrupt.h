/*
 * interrupt.h
 *
 *  Created on: Jan 16, 2022
 *      Author: Ahmed Khaled
 */

#ifndef MCAL_INTERRUPT_H_
#define MCAL_INTERRUPT_H_

#define ISR(vect)		void vect(void)__attribute__((signal));\
						void vect(void)


/*For External interrupts*/
#define INT0_vect			__vector_1
#define INT1_vect			__vector_2
#define INT2_vect			__vector_3

/*For ADC Interrupt*/
#define VECT_ADC			__vector_16

#endif /* MCAL_INTERRUPT_H_ */
