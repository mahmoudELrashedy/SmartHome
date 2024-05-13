
/******************LIB*******************/
#include "LIB/STD_Types.h"
#include "LIB/BIT_MATH.h"

/*****************MCAL*******************/

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/TWI/TWI_Interface.h"
#include "MCAL/USART/USART_Interface.h"
/*****************HAL*******************/
#include "HAL/EEPROM/EEPROM_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KPD/KPD_Inteface.h"

/****************Delay******************/
#include "avr/delay.h"

/************Global Variables***********/

/***********Definitions***************/
#define WRONG_TRIAL			0
#define WRONG_PASSWORD		1
#define CORRECT_PASSWORD	2


int main(void)
{



	/*Modules Init*/
	EEPROM_voidInit() ;
	LCD_voidInit() ;
	KPD_Init() ;
	USART_voidInit() ;
	/*********************************/



	u16 Local_u16SetPassward = 0 ;
	u16 Local_u16EnteredPassward = 0 ;

	u8 	Local_u8Pressed = 0 ;
	u8 	Local_u8Count	= 0 ;

	u8 	Local_u8ReceivedValue_0 = 0 ;
	u8 	Local_u8ReceivedValue_1 = 0 ;
	u16 Local_u8ReceivedValue	= 0 ;

	u8 	Local_u8PasswordState	= WRONG_TRIAL ;
	/*********************************/




	LCD_voidSendString((u8*)"Create Passward") ;
	LCD_voidSetPosition(LCD_ROW1 , LCD_COLUMN0)  ;
	Local_u8Pressed = KPD_u8GetPressed() ;
	while ( Local_u8Pressed != '=' )
	{
		if (Local_u8Pressed != NOT_PRESSED)
		{


			Local_u16SetPassward *= 10 ;
			Local_u16SetPassward += (Local_u8Pressed - '0') ;

			LCD_voidSendData('*') ;


			Local_u8Pressed = NOT_PRESSED ;
		}


		Local_u8Pressed = KPD_u8GetPressed() ;

	}


	EEPROM_voidSendDataByte((u8)Local_u16SetPassward , 0 ) ;
	_delay_ms(10) ;
	EEPROM_voidSendDataByte(((u8)(Local_u16SetPassward>>8)) , 1 ) ;
	_delay_ms(10) ;

	//	LCD_voidClearScreen() ;
	//	LCD_voidSendNumber((u8)(Local_u16SetPassward)) ;
	//	_delay_ms(2000) ;





	LCD_voidClearScreen() ;
	LCD_voidSendString((u8*)"Enter Passward") ;
	LCD_voidSetPosition(LCD_ROW1 , LCD_COLUMN0) ;



	while(1)
	{


		Local_u8Pressed = KPD_u8GetPressed() ;

		if ( Local_u8Pressed != NOT_PRESSED && Local_u8Pressed != '=')
		{

			Local_u16EnteredPassward *= 10 ;
			Local_u16EnteredPassward += (Local_u8Pressed - '0') ;

			LCD_voidSendData('*') ;


			Local_u8Pressed = NOT_PRESSED ;
		}

		else if (Local_u8Pressed == '=')
		{

			/*Read From EEPROM*/
			Local_u8ReceivedValue_1 = EEPROM_u8ReadDataByte(1) ;
			_delay_ms(10) ;
			Local_u8ReceivedValue_0 = EEPROM_u8ReadDataByte(0) ;
			_delay_ms(10) ;
			Local_u8ReceivedValue 	= (u16) (Local_u8ReceivedValue_0 | (u16)(Local_u8ReceivedValue_1<<8));

			/************************************************/

			if (Local_u16EnteredPassward  == Local_u8ReceivedValue)
			{
				Local_u16EnteredPassward = 0 ;
				Local_u8Count = 0 ;

				LCD_voidClearScreen() ;
				LCD_voidSendString((u8*)"Welcome home !") ;
				_delay_ms(2000) ;

				Local_u8PasswordState = CORRECT_PASSWORD ;
//				break ;
			}

			/*Number of Wrong tries = 3*/
			else if (Local_u8Count <2)
			{

				Local_u8Count ++ ;

				Local_u16EnteredPassward = 0 ;

				LCD_voidClearScreen() ;

				LCD_voidSendString((u8*)"Not Correct !") ;
				LCD_voidSetPosition(LCD_ROW1 , LCD_COLUMN0) ;
				LCD_voidSendString((u8*)"Try again") ;

				_delay_ms(2000) ;

				LCD_voidClearScreen() ;

				LCD_voidSendString((u8*)"Enter Passward") ;
				LCD_voidSetPosition(LCD_ROW1 , LCD_COLUMN0) ;
			}

			else
			{
				LCD_voidClearScreen() ;

				LCD_voidSendString((u8*)"NO More Tries") ;
				Local_u8PasswordState = WRONG_PASSWORD ;
			}
		}

		else
		{

		}

		USART_u8SendData(Local_u8PasswordState) ;

	}
	return 0;
}
