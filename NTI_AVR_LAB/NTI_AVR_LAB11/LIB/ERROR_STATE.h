/*
 * ERROR_STATE.h
 *
 *  Created on: Feb 12, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef ERROR_STATE_H_
#define ERROR_STATE_H_

typedef enum{

	ES_NOK,
	ES_OK,
	ES_OUT_OF_RANGE,
	ES_NULL_POINTER
}ES_t;

#define NULL    (void*)0

#endif /* ERROR_STATE_H_ */
