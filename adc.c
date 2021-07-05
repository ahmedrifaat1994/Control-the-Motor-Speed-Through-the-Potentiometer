/*
 * adc.c
 *
 *  Created on: 28 May 2021
 *      Author: A.Rifaat
 */

#include "adc.h"


void ADC_init(void){
	ADMUX = 0;
	ADCSRA |= (1<<ADEN) | (0<<ADIE) | (1<<ADPS0) | (1<<ADPS1) |(0<<ADPS2);
}

uint16 ADC_readChannel(uint8 ch_num){

	ADMUX &= 0xe0;
	ADMUX |= ch_num;
	ADCSRA |= (1<<ADSC);
	while(ADIF == 0);
	ADCSRA |= (1<<ADIF);
	return ADC;
}
