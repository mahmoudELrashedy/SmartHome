
/******************LIB*******************/
#include "LIB/STD_Types.h"
#include "LIB/BIT_MATH.h"

/*****************MCAL*******************/

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
/*****************HAL*******************/
#include "HAL/LM35/LM35_Interface.h"



/****************Delay******************/
#include "avr/delay.h"

/************Global Variables***********/

/***********Definitions***************/


int main(void)
{




	DIO_u8SetPinDirection(DIO_PORTB , DIO_PIN4 , DIO_PIN_INPUT) ;
	DIO_u8SetPinDirection(DIO_PORTB , DIO_PIN5 , DIO_PIN_INPUT) ;
	DIO_u8SetPinDirection(DIO_PORTB , DIO_PIN6 , DIO_PIN_OUTPUT)  ;
	DIO_u8SetPinDirection(DIO_PORTB , DIO_PIN7 , DIO_PIN_INPUT) ;

	DIO_u8SetPinDirection(DIO_PORTC , DIO_PIN0 , DIO_PIN_OUTPUT)  ;
	DIO_u8SetPinDirection(DIO_PORTC , DIO_PIN1 , DIO_PIN_OUTPUT)  ;
	/**************************************************/
	/*Modules Init*/
	SPI_VoidInit() 	 ;
	LM35_voidInit()	 ;

	/*********************************/

	/*Local Variables*/
	u8  Local_u8Room_1_Temperature = 0 ;
	u8  Local_u8Room_2_Temperature = 0 ;
	u8 	Local_u8ReceivedACK		   = 0xff ;
	u8 	Local_u8TransmittedACK	   = 0xff ;


	/*********************************/




	while(1)
	{

		Local_u8Room_1_Temperature = (u8)(LM35_u16GetTempReading(CHANNEL0)) ;
		Local_u8Room_2_Temperature = (u8)(LM35_u16GetTempReading(CHANNEL1)) ;

		SPI_u8Tranceive(Local_u8TransmittedACK , &Local_u8ReceivedACK) ;

		if (Local_u8ReceivedACK == 1)
		{
			SPI_u8Tranceive(Local_u8Room_1_Temperature , &Local_u8ReceivedACK) ;
		}
		else if (Local_u8ReceivedACK == 2)
		{
			SPI_u8Tranceive( Local_u8Room_2_Temperature , &Local_u8ReceivedACK) ;
		}
		else
		{

		}






	}

	return 0 ;

}
