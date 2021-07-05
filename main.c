
#include "adc.h"
#include "lcd.h"
#include "pwm.h"
#include "interrupts.h"

ISR(INT1_vect){
	PORTB ^= 0x03; /*Toggle the first two bits of the motor output in PORTB*/
}


int main()
{
	/*Motor Pins to output*/
	DDRB |= (1<<PB0) | (1<<PB1);
	/*Make motor rotate clock wise*/
	PORTB |= 0x01;

	uint16 read;
	int1(); /*Initialise interrupt 1*/
	PWM_init(); /*Initialise PWM in timer 0*/
	LCD_init(); /*Initialise LCD*/
	ADC_init(); /*Initialise ADC*/
	LCD_clearScreen(); /*clear screen*/

	LCD_displayString("ADC Value = ");

	while(1){
		LCD_goToRowColumn(0,12); /*Put the cursor in the 12th column in row 0*/
		read = ADC_readChannel(0); /*Take the ADC data an put it in read variable*/
		LCD_integerToString(read); /*Print the read data*/
		PWM_motorSpeed(read); /*Function to control the speed of the motor*/
		LCD_displayString("   "); /*Prints 3 spaces to overwrite the left over characters*/
	}
}
