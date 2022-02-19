/*
 * STEPPER_Interface.h
 *
 *  Created on: Feb 15, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef HAL_STEPPER_ULN2003_STEPPER_INTERFACE_H_
#define HAL_STEPPER_ULN2003_STEPPER_INTERFACE_H_

/*Stepper_ULN2003 Initialization*/
ES_t STEPPER_ES_tInit(void);

/**/
ES_t STEPPER_ES_tFullCycle(u8 Copy_u8Direction,u8 Copy_u8Speed);

/**/
ES_t STEPPER_ES_tRotationAngle(u8 Copy_u8Direction,u8 Copy_u8Speed,u8 Copy_u8Angle);

#define   CW_DIR     0
#define   CCW_DIR    1

#define  SP_LOW                9
#define  SP_MID                5
#define  SP_HIGH               2

#define CW                    CW_DIR
#define CCW                   CCW_DIR


#define  LOW_SPEED            SP_LOW
#define  MID_SPEED            SP_MID
#define  HIGH_SPEED           SP_HIGH



#endif /* HAL_STEPPER_ULN2003_STEPPER_INTERFACE_H_ */
