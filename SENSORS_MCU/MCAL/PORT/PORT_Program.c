/*
 * PORT_Program.c
 *
 *  Created on: Apr 7, 2024
 *      Author: Ibrahim
 */

/****************************************************************/
/*                    FILES INCLUSIONS							*/
/****************************************************************/
/************************LIB*************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

/************************MCAL************************************/
#include "PORT_Config.h"
#include "PORT_Interface.h"
#include "PORT_Private.h"


/**************************************************************/
/*					FUNCTIONS DEFINITIONS					  */
/**************************************************************/
void PORT_voidInit(void)
{
	DDRA_Register=PORTA_DIR;
	DDRB_Register=PORTB_DIR;
	DDRC_Register=PORTC_DIR;
	DDRD_Register=PORTD_DIR;

	/*
			Hint : will set 1 if The pin input Pullup
	 */
	PORTA_Register=PORTA_INITIAL_VALUE;
	PORTB_Register=PORTB_INITIAL_VALUE;
	PORTC_Register=PORTC_INITIAL_VALUE;
	PORTD_Register=PORTD_INITIAL_VALUE;
}
