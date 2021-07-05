/*
 * interrupts.c
 *
 *  Created on: 31 May 2021
 *      Author: A.Rifaat
 */

#include "interrupts.h"

void int1(void){
	SREG |= (1<<7); /*Global interrupt enable*/
	MCUCR |= (1<<ISC10) | (1<<ISC11); /*choose rising edge*/
	GICR |= (1<<INT1); /*enable interrupt 0*/

}

