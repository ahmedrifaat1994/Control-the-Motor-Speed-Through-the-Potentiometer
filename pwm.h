/*
 * pwm.h
 *
 *  Created on: 31 May 2021
 *      Author: A.Rifaat
 */

#ifndef PWM_H_
#define PWM_H_

#include"common_macros.h"
#include"micro_config.h"
#include"std_types.h"

/********************************************************************************************************
 *
 * ************************************CONFIGURTIONS FOR USER USE****************************************
 * *********************FOR MORE INFORMTION READ THE DISCRIPTION APOVE EVERY LINE************************
 *
 ********************************************************************************************************
 * MODES ARE:
 * 0- Normal
 * 1- Compare
 * 2- PWM
 * *******************************************************************************************************/
#define MODE PWM
/*********************************************************************************************************
 * COMPARE_MODES_PWM ARE:
 * 0- Disconnected
 * 1- Inverting
 * 2- Non_inverting
 * *******************************************************************************************************/
#define COMPARE_MODE Non_inverting
/**********************************************************************************************************
 * COMPARE_MODES_NON_PWM ARE:
 * 0- Normal
 * 1- Toggle
 * 2- Clear
 * 3- Set
 * ******************************************************************************************************/
#define NON_PWM_MODE Clear
/*CHOOSE THE PRESCALLER YOU WANT <T0_PRESCALER_x> x = 1,8,64,256,1024 or <T0_STOP_TIMER> TO STOP TIMER0*/
#define PRESCALER T0_PRESCALER_8
/*1 to enable overflow interrupt, 2 to enable compare mode interrupt or Write NOT_ENABLED*/
#define INTERRUPT NOT_ENABLED
/*Initialise the timer start value*/
#define a_T0_startValue 0 /*argument for T0_startValue*/
/*Initialise the timer compare value*/
#define a_T0_compareValue 0 /*argument for T0_compareValue*/

/********************************************************************************************************
 *
 * **********************************END OF CONFIGURATION SECTION****************************************
 *
 * ******************************************************************************************************/

#define T0_startValue(value) (TCNT0 = value)
#define T0_compareValue(val) (OCR0 = val)


/*************************************************************************
 * MODES ARE:
 * 0- Normal
 * 1- Compare
 * 2- PWM
 * **********************************************************************/
#define Normal 1
#define Compare 2
#define PWM 3
/*************************************************************************
 * COMPARE_MODES_PWM ARE:
 * 0- Disconnected
 * 1- Inverting
 * 2- Non_inverting
 * **********************************************************************/
#define Disconnected 1
#define Inverting 2
#define Non_inverting 3
/*************************************************************************
 * COMPARE_MODES_NON_PWM ARE:
 * 0- Normal
 * 1- Toggle
 * 2- Clear
 * 3- Set
 * **********************************************************************/
#define Normal 1
#define Toggle 2
#define Clear 3
#define Set 4

#define T0_STOP_TIMER (TCCR0 |= (0<<CS02) | (0<<CS01) | (0<<CS00))
#define T0_PRESCALER_1 (TCCR0 |= (0<<CS02) | (0<<CS01) | (1<<CS00))
#define T0_PRESCALER_8 (TCCR0 |= (0<<CS02) | (1<<CS01) | (0<<CS00))
#define T0_PRESCALER_64 (TCCR0 |= (0<<CS02) | (1<<CS01) | (1<<CS00))
#define T0_PRESCALER_256 (TCCR0 |= (1<<CS02) | (0<<CS01) | (0<<CS00))
#define T0_PRESCALER_1024 (TCCR0 |= (1<<CS02) | (0<<CS01) | (1<<CS00))

#define T0_INTERRUPT_OF (TIMSK = (1<<TOIE0))
#define T0_INTERRUPT_OC (TIMSK = (1<<OCIE0))



void PWM_init(void);
void PWM_motorSpeed(uint16 read);


#endif /* PWM_H_ */
