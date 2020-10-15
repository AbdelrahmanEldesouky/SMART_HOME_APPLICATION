/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: DIO						************/
/************		Date: 24-8-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

/*File Gard*/
#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_
	
	#define PORTA		*((volatile uint8 *) 0X3B)
	#define PINA		*((volatile uint8 *) 0X39)
	
	#define PORTB		*((volatile uint8 *) 0X38)
	#define PINB		*((volatile uint8 *) 0X36)
	
	#define PORTC		*((volatile uint8 *) 0X35)
	#define PINC		*((volatile uint8 *) 0X33)
	
	#define PORTD		*((volatile uint8 *) 0X32)
	#define PIND		*((volatile uint8 *) 0X30)
	
#endif
