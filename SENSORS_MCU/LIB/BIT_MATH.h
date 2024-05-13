/*
 * BIT_MATH.h
 *
 * Created: 9/27/2023 9:56:29 AM
 *  Author: M
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT) (REG|=(1u<<BIT))
#define CLR_BIT(REG,BIT) (REG&= ~(1u<<BIT))
#define GET_BIT(REG,BIT) ((REG&(1u<<BIT))>>BIT)
#define TOG_BIT(REG,BIT) (REG^=(1u<<BIT))


#define NULL (void*) 0

#endif /* BIT_MATH_H_ */
