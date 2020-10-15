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
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

	#define DIO_uint8PORTA 			0
	#define DIO_uint8PORTB 			1
	#define DIO_uint8PORTC 			2
	#define DIO_uint8PORTD 			3

	#define DIO_uint8PIN0  			0
	#define DIO_uint8PIN1  			1
	#define DIO_uint8PIN2  			2
	#define DIO_uint8PIN3  			3
	#define DIO_uint8PIN4  			4
	#define DIO_uint8PIN5  			5
	#define DIO_uint8PIN6  			6
	#define DIO_uint8PIN7  			7

	#define DIO_uint8_LOW 			0
	#define DIO_uint8_HIGH 			1

	#define DIO_uint8PORT_LOW 		0X00
	#define DIO_uint8PORT_HIGH 		0XFF

	
	uint8 DIO_uint8SetPinValue		(uint8 Copy_uint8Port , uint8 Copy_uint8Pin , uint8 Copy_uint8Value) ;

	uint8 DIO_uint8PortValue		(uint8 Copy_uint8Port , uint8 Copy_uint8Value) ;
	
	uint8 DIO_uint8GetPinValue		(uint8 Copy_uint8Port , uint8 Copy_uint8Pin , uint8 * Copy_puint8Value) ;
	
	uint8 DIO_uint8ToggelPinValue	(uint8 Copy_uint8Port , uint8 Copy_uint8Pin) ;
	
#endif
