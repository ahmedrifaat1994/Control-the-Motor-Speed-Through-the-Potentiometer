/*
 * adc.h
 *
 *  Created on: 28 May 2021
 *      Author: A.Rifaat
 */

#ifndef ADC_H_
#define ADC_H_

#include"common_macros.h"
#include"micro_config.h"
#include"std_types.h"


void ADC_init(void); /*Function to initialise ADC*/
uint16 ADC_readChannel(uint8 ch_num); /*Function to read the data from the ADC channel*/

#endif /* ADC_H_ */
