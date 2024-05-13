
/******************LIB*******************/
#include "LIB/STD_Types.h"
#include "LIB/BIT_MATH.h"

/*****************MCAL*******************/

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/TIMERS/TIMERS_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/USART/USART_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"
/*****************HAL*******************/
#include "HAL/DC_FAN/DC_FAN_Interface.h"
/****************Delay******************/
#include "avr/delay.h"



/***********Definitions***************/
#define WRONG_TRIAL			0
#define WRONG_PASSWORD		1
#define CORRECT_PASSWORD	2
/***************************************/

/************Global Variables***********/
	u8 Global_u8Room_1_Flag = 0 ;
	u8 Global_u8Room_2_Flag = 0 ;
void Room_1_ControlEnable (void)
{
	if (Global_u8Room_1_Flag==0)
	{
		Global_u8Room_1_Flag = 1	;
	}
	else
	{
		Global_u8Room_1_Flag = 0 	;
	}

}

void Room_2_ControlEnable (void)
{
	if (Global_u8Room_2_Flag==0)
	{
		Global_u8Room_2_Flag = 1	;
	}
	else
	{
		Global_u8Room_2_Flag = 0 	;
	}

}


















int main(void)
{




	/*DIO Configuration*/
	DIO_u8SetPortDirection(DIO_PORTA , 0xff) ;


	DIO_u8SetPinDirection(DIO_PORTB , DIO_PIN4 , DIO_PIN_OUTPUT) ;
	DIO_u8SetPinDirection(DIO_PORTB , DIO_PIN5 , DIO_PIN_OUTPUT) ;
	DIO_u8SetPinDirection(DIO_PORTB , DIO_PIN6 , DIO_PIN_INPUT)  ;
	DIO_u8SetPinDirection(DIO_PORTB , DIO_PIN7 , DIO_PIN_OUTPUT) ;


	DIO_u8ConnectPullUp(DIO_PORTD , DIO_PIN2 , DIO_PIN_HIGH) ;
	DIO_u8ConnectPullUp(DIO_PORTD , DIO_PIN3 , DIO_PIN_HIGH) ;

	/*******************************/
	/*Modules Init*/
	EXTI_voidInit()	  ;
	GIE_voidEnable()  ;
	USART_voidInit()  ;
	SPI_VoidInit() 	  ;
	TIMER2_voidInit() ;
	TIMER0_voidInit() ;

	DC_FAN_Init() ;

	/*********************************/
	/*Local Variables*/
	u8  Local_u8Room_1_Temperature = 0xff ;
	u8  Local_u8Room_2_Temperature = 0xff ;
	u8 	Local_u8ReceivedACK		   = 0xff ;
	u8 	Local_u8TransmittedACK	   = 0xff ;
	u8 	Local_u8PasswordState	= WRONG_TRIAL ;
	u8 i = 0 ;




	/*********************************/

	/*CallBack Functions*/
	EXTI_u8Int0SetCallBack(Room_1_ControlEnable) ;
	EXTI_u8Int1SetCallBack(Room_2_ControlEnable) ;

	DC_FAN_SetSpeed(FAN_1 , 0) ;
	DC_FAN_SetSpeed(FAN_2 , 0) ;
	while(1)
	{

		USART_u8RecevieData(&Local_u8PasswordState) ;
		if (Local_u8PasswordState == WRONG_PASSWORD)
		{
			for ( i = 0 ; i<20 ; i++)
			{
				DIO_u8SetPortValue(DIO_PORTA , 0xff) ;
				_delay_ms(500) ;
				DIO_u8SetPortValue(DIO_PORTA , 0x00) ;
				_delay_ms(500) ;

			}
			Local_u8PasswordState = WRONG_TRIAL ;
		}

		else if (Local_u8PasswordState == CORRECT_PASSWORD)
		{



			SPI_u8Tranceive(1 , &Local_u8ReceivedACK) ;
			_delay_ms(10) ;
			SPI_u8Tranceive(Local_u8TransmittedACK , &Local_u8Room_1_Temperature) ;
			_delay_ms(10) ;

			SPI_u8Tranceive(2 , &Local_u8ReceivedACK) ;
			_delay_ms(10) ;
			SPI_u8Tranceive(Local_u8TransmittedACK , &Local_u8Room_2_Temperature) ;
			_delay_ms(10) ;




			/************Room1 Temperature Control*************/
			if (Global_u8Room_1_Flag == 1)
			{


				if(Local_u8Room_1_Temperature < 14)
				{
					DC_FAN_SetSpeed(FAN_1 ,	0) ;
				}
				else if (Local_u8Room_1_Temperature < 20)
				{
					DC_FAN_SetSpeed(FAN_1 , 64) ;
				}
				else if (Local_u8Room_1_Temperature < 30)
				{
					DC_FAN_SetSpeed(FAN_1 , 128) ;
				}
				else
				{
					DC_FAN_SetSpeed(FAN_1 , 255) ;
				}
			}

			else
			{
				DC_FAN_SetSpeed(FAN_1 ,	0) ;
			}
			/*******************************************************/
			/************Room2 Temperature Control*************/
			if (Global_u8Room_2_Flag == 1)
			{



				if(Local_u8Room_2_Temperature < 14)
				{
					DC_FAN_SetSpeed(FAN_2 , 0) ;
				}
				else if (Local_u8Room_2_Temperature < 20)
				{
					DC_FAN_SetSpeed(FAN_2 , 64) ;
				}
				else if (Local_u8Room_2_Temperature < 30)
				{
					DC_FAN_SetSpeed(FAN_2 , 128) ;
				}
				else
				{
					DC_FAN_SetSpeed(FAN_2 , 255) ;
				}
			}

			else
			{
				DC_FAN_SetSpeed(FAN_2 ,	0) ;
			}


		}

		else
		{

		}




	}

	return 0 ;

}
