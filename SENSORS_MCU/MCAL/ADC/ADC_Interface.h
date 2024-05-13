/*
 * ADC_Interface.h
 *
 *  Created on: Mar 25, 2024
 *      Author: Ibrahim
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_



#define CHANNEL0		0
#define CHANNEL1		1
#define CHANNEL2		2
#define CHANNEL3		3
#define CHANNEL4		4
#define CHANNEL5		5
#define CHANNEL6		6
#define CHANNEL7		7

/******************FUNCTIONS PROTOTYPES***************/
void ADC_voidInit(void);

u16 ADC_u16GetConversionReading(u8 copy_u8Channel);

//u8 ADC_u8GetReferenceSelection(void);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
