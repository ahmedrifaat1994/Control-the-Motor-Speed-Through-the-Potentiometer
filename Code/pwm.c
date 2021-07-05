/*
 * pwm.c
 *
 *  Created on: 31 May 2021
 *      Author: A.Rifaat
 */

#include "pwm.h"


/*function to initialise PWM in timer 1*/
void PWM_init(void){
	/*make OC0 PIN output*/
	SET_BIT(DDRB,PB3);
	//DDRB |= (1<<PB3);
	/*
	 * enable fast PWM
	 * non-inverting mode
	 * 8 pre-scaler
	 * */
#if (MODE == PWM)
		TCCR0 |= (1<<WGM01) | (1<<WGM00);
#elif (MODE == Normal)
		TCCR0 |= (0<<WGM01) | (0<<WGM00);
#elif (MODE == Compare)
		TCCR0 |= (1<<WGM01) | (0<<WGM00);
#endif

#if ((MODE == PWM) && (COMPARE_MODE == Inverting))
		TCCR0 |= (1<<COM01) | (1<<COM00);
#elif ((MODE == PWM) && (COMPARE_MODE == Non_inverting))
		TCCR0 |= (1<<COM01) | (0<<COM00);
#elif ((MODE == PWM) && (COMPARE_MODE == Disconnected))
		TCCR0 |= (0<<COM01) | (0<<COM00);
#elif (MODE != PWM)
#if(NON_PWM_MODE == Normal)
		TCCR0 |= (0<<COM01) | (0<<COM00);
#elif(NON_PWM_MODE == Toggle)
		TCCR0 |= (0<<COM01) | (1<<COM00);
#elif (NON_PWM_MODE == Clear)
		TCCR0 |= (1<<COM01) | (0<<COM00);
#elif (NON_PWM_MODE == Set)
		TCCR0 |= (1<<COM01) | (1<<COM00);
#endif
#endif


	PRESCALER;

	//TCCR0 |= (1<<WGM00) | (1<<WGM00) | (1<<COM01) | (1<<CS01);
	/*initialise value to 0*/
//	TCNT0 = 0;
	T0_startValue(a_T0_startValue);
	/*compare value initialise to 0*/
//	OCR0 = 0;
	T0_compareValue(a_T0_compareValue);

#ifdef INTERRUPT
#if(INTERRUPT == 1)
	T0_INTERRUPT_OF;
#elif (INTERRUPT == 2)
	T0_INTERRUPT_OC;
#endif
#endif
}

void PWM_motorSpeed(uint16 read){
	T0_compareValue(read/4);
}
