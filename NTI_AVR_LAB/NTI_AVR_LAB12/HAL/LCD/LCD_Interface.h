/*
 * LCD_Interface.h
 *
 *  Created on: Feb 12, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*LCD Driver Initialization*/
ES_t   LCD_ES_tInit(void);
/*LCD write Data*/
ES_t   LCD_ES_tWriteData(u8 Copy_u8Data);
/*LCD write command*/
ES_t   LCD_ES_tWriteCommand(u8 Copy_u8Command);

ES_t LCD_ES_tWriteString(u8* Copy_u8Data);

ES_t LCD_ES_tSendIntgerNum(s32 Copy_s32Num);

ES_t  LCD_ES_tCustomAlphChar(u8 Copy_u8PatternNumber, u8* PCopy_u8Pattern);

ES_t   LCD_ES_tGoToPosition(u8 Copy_u8Row,u8 Copy_u8Col) ;


#endif /* LCD_INTERFACE_H_ */
