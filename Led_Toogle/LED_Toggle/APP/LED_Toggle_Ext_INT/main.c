/*
 * main.c
 *
 *  Created on: Apr 17, 2022
 *      Author: Seko
 */

#include "../../MCAL/DIO/DIO_interface.h"
#include  "../../MCAL/External_interrupt/External_interrupt.h"
#include "../../LIB/BIT_MATH.h"
#include "Config_file.h"

void External_Function0 (void)
{

	DIO_SetPinValue(LEDS_PORT,LED_Pin0,DIO_HIGH);

}

void main(void)
{
	DIO_init();
	External_Int0(Rising_Edge_Sense);
	DIO_SetPortDirection(LEDS_PORT,DIO_OUTPUT);
	Enable_Global_Interrupt(Enable_Interrupt);

	while(1)
	{


		while ((GET_BIT(Switch_PORT,Switch_Pin0))==0)
			{
				CallBack_Int0(External_Function0);
			}
	}
}


