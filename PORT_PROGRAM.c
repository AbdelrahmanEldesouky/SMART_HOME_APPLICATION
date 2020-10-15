/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: PORT						************/
/************		Date: 31-8-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#include "STD_TYPE.h"

/* Must Include PORT_CONFIG.h before PORT_PRIVATE.h */
#include "PORT_CONFIG.h"
#include "PORT_INTERFACE.h"
#include "PORT_PRIVATE.h"
#include "PORT_REGISTER.h"

void PORT_VoidInit (void)
{
	DDRA = PORTA_DIR ;
	DDRB = PORTB_DIR ;
	DDRC = PORTC_DIR ;
	DDRD = PORTD_DIR ;
	
	PORTA = PORTA_INITIAl_VALUE ;
	PORTB = PORTB_INITIAl_VALUE ;
	PORTC = PORTC_INITIAl_VALUE ;
	PORTD = PORTD_INITIAl_VALUE ;
}
