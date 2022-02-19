/*
 * SWITCH_Interface.h
 *
 *  Created on: Feb 12, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

/*Switch State Options:
 * 1- Pressed
 * 2- Depressed*/

#define PULLUP_PRESSED         0
#define PULLUP_DEPRESSED       1

#define PULLDOWN_PRESSED       1
#define PULLDOWN_DEPRESSED     0

/*Switch Driver Initialization*/
ES_t SWITCH_ES_tInit(SWITCH_t* Copy_PtrSWITCH_tConfig );
/*Get Switch State*/
ES_t SWITCH_ES_tGetSwitchState(SWITCH_t* Copy_PtrSWITCH_tInfo,u8* Copy_Pu8SwitchState);

#endif /* SWITCH_INTERFACE_H_ */
