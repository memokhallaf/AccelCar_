/*
 * main.c
 *
 *  Created on: Aug 25, 2021
 *      Author: memom
 */
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"
#include "MADC_interface.h"
#include "MSPI_interface.h"
#include "MGIE_interface.h"


#define F_CPU 8000000UL
#include "util/delay.h"

int main(void)
{
	u8_t x = 0;

	/*ADC I/P*/
	mdio_setPinstatus(PORTA,PIN0,INPUT_FLOAT);
	/*SPI PINS STATUS*/
	/*mosi is o/p*/
	mdio_setPinstatus(PORTB, PIN5, OUTPUT);
	/*miso is i/p*/
	mdio_setPinstatus(PORTB, PIN6, INPUT_FLOAT);
	/*sck is o/p*/
	mdio_setPinstatus(PORTB, PIN7, OUTPUT);
	/*ss is o/p*/
	mdio_setPinstatus(PORTB,PIN4, OUTPUT);

	mspi_InitMaster();
	madc_init();
	mGIE_EnableGie();

	while(1)
	{
		/*ADC FUN*/
		 x = madc_ReadAnalogPolling(0);
		 /*SPI TRANS*/
		 mspi_tran(x);



	}
	return 0;
}
