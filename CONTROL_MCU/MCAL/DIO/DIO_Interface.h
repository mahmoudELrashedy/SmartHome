/*
 * DIO.h
 *
 *  Created on: Mar 18, 2024
 *      Author: M
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_


#include "../../LIB/STD_TYPES.h"

/*******************************GENERAL MACROS**********************************/

/**********************PORTS********************/

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

/**********************PINS********************/

#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7


/**********************DIRECTIONS********************/

#define DIO_PIN_INPUT  0
#define DIO_PIN_OUTPUT 1
#define DIO_PORT_INPUT 0x00
#define DIO_PORT_OUTPUT 0xFF
/**********************DIRECTIONS********************/

#define DIO_PIN_LOW  0
#define DIO_PIN_HIGH 1

/*******************************Function Prototypes*****************************/

ReturnType_State_t DIO_u8SetPortValue (u8 copy_u8Port , u8 copy_u8Value) ;

ReturnType_State_t DIO_u8SetPortDirection (u8 copy_u8Port , u8 copy_u8Direction) ;

ReturnType_State_t DIO_u8GetPortValue (u8 copy_u8Port , u8* copy_u8Value) ;

ReturnType_State_t DIO_u8SetPinValue (u8 copy_u8Port , u8 copy_u8Pin ,  u8 copy_u8Value) ;

ReturnType_State_t DIO_u8TogglePinValue (u8 copy_u8Port , u8 copy_u8Pin ) ;

ReturnType_State_t DIO_u8SetPinDirection (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Direction) ;

ReturnType_State_t DIO_u8GetPinValue (u8 copy_u8Port , u8 copy_u8Pin , u8* copy_u8Value) ;

ReturnType_State_t DIO_u8ConnectPullUp (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8ConnectPullUp) ;


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
