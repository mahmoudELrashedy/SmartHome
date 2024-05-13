/*
 * TWI_Config.h
 *
 *  Created on: Apr 3, 2024
 *      Author: Ibrahim
 */

#ifndef MCAL_TWI_TWI_CONFIG_H_
#define MCAL_TWI_TWI_CONFIG_H_


/*Set the Master/Slave TWI
 * Options:
 * 1. MASTER
 * 2. SLAVE
 */
#define TWI_MASTER_SLAVE		MASTER

/*Set speed of TWI
 * Options:
 * 1. SPEED_100K
 * 2. SPEED_400K
 */
#define TWI_SPEED				SPEED_400K


/*Set prescaler value
 * Options:
 * 1. TWI_PRESCALER_1
 * 2. TWI_PRESCALER_4
 * 3. TWI_PRESCALER_16
 * 4. TWI_PRESCALER_64
 */
#define TWI_PRESCALER			TWI_PRESCALER_1


/*Set Target address*/
#define TARGET_ADDRESS			0x0



#endif /* MCAL_TWI_TWI_CONFIG_H_ */
