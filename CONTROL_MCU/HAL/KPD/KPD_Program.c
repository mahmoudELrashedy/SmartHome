/*
 * KPD_Program.c
 *
 *  Created on: Mar 20, 2024
 *      Author: M
 */


/*************************************************************************/
/*                            FILES INCLUSION                           */

/***************LIB**************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/************MCAL*************/
#include "../../MCAL/DIO/DIO_Interface.h"

/***********HAL**************/
#include "KPD_Config.h"
#include "KPD_Private.h"
#include <util/delay.h>
#include "KPD_Inteface.h"


void KPD_Init (void)
{
	/*connect PullUp for rows pins */
	DIO_u8ConnectPullUp(KPD_PORT , KPD_R0 , DIO_PIN_HIGH) ;
	DIO_u8ConnectPullUp(KPD_PORT , KPD_R1 , DIO_PIN_HIGH) ;
	DIO_u8ConnectPullUp(KPD_PORT , KPD_R2 , DIO_PIN_HIGH) ;
	DIO_u8ConnectPullUp(KPD_PORT , KPD_R3 , DIO_PIN_HIGH) ;


	/*connect COL pins to HIGH output*/
	DIO_u8SetPinDirection(KPD_PORT , KPD_C0 , DIO_PIN_OUTPUT) ;
	DIO_u8SetPinDirection(KPD_PORT , KPD_C1 , DIO_PIN_OUTPUT) ;
	DIO_u8SetPinDirection(KPD_PORT , KPD_C2 , DIO_PIN_OUTPUT) ;
	DIO_u8SetPinDirection(KPD_PORT , KPD_C3 , DIO_PIN_OUTPUT) ;

	DIO_u8SetPinValue(KPD_PORT , KPD_C0 , DIO_PIN_HIGH) ;
	DIO_u8SetPinValue(KPD_PORT , KPD_C1 , DIO_PIN_HIGH) ;
	DIO_u8SetPinValue(KPD_PORT , KPD_C2 , DIO_PIN_HIGH) ;
	DIO_u8SetPinValue(KPD_PORT , KPD_C3 , DIO_PIN_HIGH) ;

}

u8 KPD_u8GetPressed (void)
{
	u8 Local_u8ReturnData =NOT_PRESSED ;
	u8 Local_u8GetPressed ;

	u8 Local_u8Col ;
	u8 Local_u8Row ;

	for (Local_u8Col = KPD_COL_INIT ; Local_u8Col <= KPD_COL_END ; Local_u8Col++)
	{
		DIO_u8SetPinValue(KPD_PORT , Local_u8Col , DIO_PIN_LOW) ;

		for (Local_u8Row = KPD_ROW_INIT ; Local_u8Row <= KPD_ROW_END ; Local_u8Row++)
		{
			DIO_u8GetPinValue(KPD_PORT , Local_u8Row , &Local_u8GetPressed) ;

			if (Local_u8GetPressed == DIO_PIN_LOW)
			{
				//_delay_ms(50) ;

				DIO_u8GetPinValue(KPD_PORT , Local_u8Row , &Local_u8GetPressed) ;

				if (Local_u8GetPressed == DIO_PIN_LOW)
				{
					Local_u8ReturnData = KPD_u8Buttons [Local_u8Row-KPD_ROW_INIT][Local_u8Col-KPD_COL_INIT] ;
				}

				DIO_u8GetPinValue(KPD_PORT , Local_u8Row , &Local_u8GetPressed) ;
				while (DIO_PIN_LOW == Local_u8GetPressed)
				{
					DIO_u8GetPinValue(KPD_PORT , Local_u8Row , &Local_u8GetPressed) ;
				}
				break ;


			}


		}

		DIO_u8SetPinValue(KPD_PORT , Local_u8Col , DIO_PIN_HIGH) ;
	}



	return Local_u8ReturnData ;
}
