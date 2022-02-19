/*
 * GIE_Program.c
 *
 *  Created on: Feb 15, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*Public libraries*/
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/ERROR_STATE.h"

//lower layer Libraries
#include"../../MCAL/DIO_Interface.h"

/*own libraries*/
#include"GIE_Config.h"
#include"GIE_Private.h"


/*Delay Function*/
#include<util/delay.h>



/*Initialization GIE Module*/

ES_t GIE_ES_tInit(void)

{
	ES_t LOC_ES_tErrorState = ES_NOK;
	//SREG &=~(1<<7);
    asm("CLI");
	return LOC_ES_tErrorState = ES_OK;
}

/*Disable GIE */

ES_t GIE_ES_tEnable(void)

{
	ES_t LOC_ES_tErrorState = ES_NOK;
	//SREG |=(1<<7) ;
    asm("SEI");

	return 	LOC_ES_tErrorState = ES_OK;
}


/*Enable GIE*/

ES_t GIE_ES_tDisable(void)
{

	       ES_t LOC_ES_tErrorState = ES_NOK;
	   	//SREG &=~(1<<7);

	       asm("CLI");
	return LOC_ES_tErrorState = ES_OK;
}
