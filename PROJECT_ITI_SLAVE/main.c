/*
 * main.c
 *
 *  Created on: Sep 8, 2021
 *      Author: memom
 */
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"
#include "MSPI_private.h"
#include "MSPI_interface.h"
#include "MGIE_interface.h"
#include "HLCD_interface.h"

int main(void)
{
	u8_t data= 0;
	u8_t x = 0 ;

	mdio_setPinstatus(PORTD, (PIN0 | PIN1 | PIN2 | PIN3 | PIN4 | PIN5 | PIN6 | PIN7), OUTPUT);


	/*SLAVE PINS*/
	/*mosi is i/p*/
	mdio_setPinstatus(PORTB, PIN5, INPUT_FLOAT);
	/*miso is o/p*/
	mdio_setPinstatus(PORTB, PIN6, OUTPUT);
	/*sck is i/p*/
	mdio_setPinstatus(PORTB, PIN7, INPUT_FLOAT);

	hlcd_init();
	hlcd_creatCustomChar() ;

	mspi_InitSlave();
	mGIE_EnableGie();


	while(1)
	{
		data = mspi_ReadSPDI_Slave();

		switch(data)
		{
		  case 255 :
			  x = data ;
			  hlcd_init();
			  hlcd_displayString("HELLO !!");
			  hlcd_setCursor(1 ,0);
			  hlcd_displayString("MY NAME IS Ali") ;
			  data = 0 ;
			  break ;

		  case 154 :

			  hlcd_init();
			  hlcd_displayString("WHAT ABOUT U ?");
			  data = 0 ;
			  break ;

		  case 51 :

			  hlcd_init();
			  hlcd_displayString("AWESOME !!");
			  data = 0 ;
			  break ;

		  case 205 :

			  hlcd_init();
			  hlcd_displayString("WHERE ARE U FROM ?");
			  data = 0 ;
			  break ;

		  case 102:

			  hlcd_init();
			  hlcd_displayString("REALLY !!");
			  hlcd_setCursor(1,4);
			  hlcd_displayCustomChar();
			  hlcd_displayCustomChar();
			  hlcd_displayCustomChar();
			  hlcd_displayCustomChar();
			  hlcd_displayCustomChar();
			  data = 0 ;
			  break ;
		  case 0:
			  hlcd_init();
			  hlcd_displayString("TO CONTROL ROOM");
			  hlcd_setCursor(1,0);
			  hlcd_displayString("USE KeyPad");
			break;
		  default :


			  break  ;


		}

	}
	return 0;
}
