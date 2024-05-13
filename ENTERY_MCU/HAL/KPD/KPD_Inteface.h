/*
 * KPD_Inteface.h
 *
 *  Created on: Mar 20, 2024
 *      Author: M
 */

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_

void KPD_Init (void) ;
u8 KPD_u8GetPressed (void) ;

/***********************************************/

#define NOT_PRESSED  (0xFF)

/**********************************************/
#endif /* HAL_KPD_KPD_INTERFACE_H_ */
