/*
 * DC_FAN_Interface.h
 *
 *  Created on: 2024-04-09
 *      Author: Mahmoud ELRashedy
 */

#ifndef DC_FAN_INTERFACE_H_
#define DC_FAN_INTERFACE_H_

#define FAN_1		1
#define FAN_2		2

void DC_FAN_Init (void) ;

void DC_FAN_SetSpeed (u8 fan , u8 speed) ;


#endif /* DC_FAN_INTERFACE_H_*/
