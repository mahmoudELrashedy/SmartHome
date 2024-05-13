/*
 * DC_FAN_Program.c
 *
 *  Created on: 2024-04-09
 *      Author: Mahmoud ELRashedy
 */

// Source content for module DC_FAN

/****************************LIB***************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

/****************************MCAL**************************/
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMERS/TIMERS_Interface.h"
/****************************HAL***************************/
#include "DC_FAN_Config.h"
#include "DC_FAN_Interface.h"
#include "DC_FAN_Private.h"

/*****************************************************************************/
/*                           FUNCTIONS DEFINITION                           */
/***************************************************************************/

void DC_FAN_Init (void)
{
#if (DC_FAN_1_ENABLE	==	ENABLE)
	DIO_u8SetPinDirection(DC_FAN_1_PORT , DC_FAN_1_PIN , DIO_PIN_OUTPUT) ;
#endif
#if (DC_FAN_2_ENABLE	==	ENABLE)
	DIO_u8SetPinDirection(DC_FAN_2_PORT , DC_FAN_2_PIN , DIO_PIN_OUTPUT) ;
#endif
}

void DC_FAN_SetSpeed (u8 fan , u8 speed)
{
	if (fan == FAN_1)
	{
		TIMER0_voidSetCTC(speed) ;
	}
	else if (fan == FAN_2)
	{
		TIMER2_voidSetCTC(speed) ;
	}
	else
	{

	}
}

























