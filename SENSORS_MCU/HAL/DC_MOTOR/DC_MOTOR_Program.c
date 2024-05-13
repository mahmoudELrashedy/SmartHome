/*
 * DC_MOTOR_Program.c
 *
 *  Created on: Mar 27, 2024
 *      Author: M
 */


/****************************LIB***************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

/****************************MCAL**************************/
#include "../../MCAL/DIO/DIO_Interface.h"

/****************************HAL***************************/
#include "DC_MOTOR_Config.h"
#include "DC_MOTOR_Interface.h"
#include "DC_MOTOR_Private.h"









void DC_MOTOR_voidInit 			(void)
{
	DIO_u8SetPinDirection(DC_MOTOR_PORT , DC_MOTOR_PIN_1 , DIO_PIN_OUTPUT) ;
	DIO_u8SetPinDirection(DC_MOTOR_PORT , DC_MOTOR_PIN_2 , DIO_PIN_OUTPUT) ;
}




void DC_MOTOR_voidRotateCCW 	(void)
{
	DIO_u8SetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN_1 , DIO_PIN_HIGH) ;
	DIO_u8SetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN_2 , DIO_PIN_LOW) ;
}




void DC_MOTOR_voidRotateCW	 	(void)
{
	DIO_u8SetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN_1 , DIO_PIN_LOW) ;
	DIO_u8SetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN_2 , DIO_PIN_HIGH) ;
}


void DC_MOTOR_voidStop 			(void)
{
	DIO_u8SetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN_1 , DIO_PIN_LOW) ;
	DIO_u8SetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN_2 , DIO_PIN_LOW) ;
}








