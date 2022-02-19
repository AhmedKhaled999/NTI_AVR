/*
 * MOTOR_293D_Interface.h
 *
 *  Created on: Feb 14, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef HAL_MOTOR_L293D_MOTOR_293D_INTERFACE_H_
#define HAL_MOTOR_L293D_MOTOR_293D_INTERFACE_H_

/**/
ES_t MOTOR_293D_ES_tInit(void);

/**/
ES_t MOTOR_293D_ES_tStartWithDirection(u8 Copy_u8Direction,u8 Copy_u8Speed);
/**/
ES_t MOTOR_293D_ES_tStop(void);



#define   CW_DIR     0
#define   CCW_DIR    1

#define CW                    CW_DIR
#define CCW                   CCW_DIR

#define FULL_SPEED              1

#endif /* HAL_MOTOR_L293D_MOTOR_293D_INTERFACE_H_ */
