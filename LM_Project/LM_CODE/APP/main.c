/*
 * main.c
 *
 *  Created on: Sep 22, 2021
 *      Author: Seko
 */
/*
 * MAIN.C
 *
 *  Created on: Sep 22, 2021
 *      Author: Seko
 */
#include "../MCAL/GPIO/GPIO.h"
#include "../MCAL/ADC/ADC.h"
#include "../HAL/lcd/lcd.h"
#include <util/delay.h>

#define SensorPin 1
#define VREF 5
#define ADC_MAX 1024
#define LM35_Voltage 0.01
#define AREF_INTERNAL_VOLTAGE 2.56

uint16 adcValue;
f32 c;
char Temp[]={"Temperature"};
char symb[]={223};
void Value_Changes(void)
{
	ADC_getValue(&adcValue);

	c=(((f32)adcValue)*4.889);
	c=(c/10.00);

}
int main (void)
{
	GPIO_init();
	LCD_lcd_init();
	ADC_init();
	ADC_callback(&Value_Changes);

	ADC_setInterrupt(ADC_INTERRUPT_ENABLE);
	ENABLE_GLOBAL_INTERRUPT();

	while(1)
	{
		ADC_startConversion(SensorPin);


		LCD_Send_A_String("Temp is");
		LCD_Send_A_String(" ");

		//LCD_Send_A_Command(0xC0);
		LCD_display_number(c);

		LCD_Send_A_String(symb);
		LCD_Send_A_String("C");

		LCD_clear_screen();
	}
}
//
