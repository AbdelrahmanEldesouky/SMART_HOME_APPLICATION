/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: PORT						************/
/************		Date: 31-8-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

/*File Gard*/
#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_
	#define PORTA		*((volatile uint8 *) 0X3B)
	#define DDRA		*((volatile uint8 *) 0X3A)
	
	#define PORTB		*((volatile uint8 *) 0X38)
	#define DDRB		*((volatile uint8 *) 0X37)
	
	#define PORTC		*((volatile uint8 *) 0X35)
	#define DDRC		*((volatile uint8 *) 0X34)
	
	#define PORTD		*((volatile uint8 *) 0X32)
	#define DDRD		*((volatile uint8 *) 0X31)

#endif
