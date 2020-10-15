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
#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

	/* Choose between INPUT or OUTPUT */
	
	#define PORTA_PIN0_DIR				INPUT
	#define PORTA_PIN1_DIR				INPUT
	#define PORTA_PIN2_DIR				OUTPUT
	#define PORTA_PIN3_DIR				OUTPUT
	#define PORTA_PIN4_DIR				OUTPUT
	#define PORTA_PIN5_DIR				OUTPUT
	#define PORTA_PIN6_DIR				INPUT
	#define PORTA_PIN7_DIR			    INPUT
			
	#define PORTB_PIN0_DIR				OUTPUT
	#define PORTB_PIN1_DIR				OUTPUT
	#define PORTB_PIN2_DIR				OUTPUT
	#define PORTB_PIN3_DIR				OUTPUT
	#define PORTB_PIN4_DIR				OUTPUT
	#define PORTB_PIN5_DIR				OUTPUT
	#define PORTB_PIN6_DIR				OUTPUT
	#define PORTB_PIN7_DIR  		    OUTPUT
			
	#define PORTC_PIN0_DIR				OUTPUT
	#define PORTC_PIN1_DIR				OUTPUT
	#define PORTC_PIN2_DIR				OUTPUT
	#define PORTC_PIN3_DIR				OUTPUT
	#define PORTC_PIN4_DIR				OUTPUT
	#define PORTC_PIN5_DIR				OUTPUT
	#define PORTC_PIN6_DIR				OUTPUT
	#define PORTC_PIN7_DIR			    OUTPUT
		
	#define PORTD_PIN0_DIR				INPUT
	#define PORTD_PIN1_DIR				OUTPUT
	#define PORTD_PIN2_DIR				OUTPUT
	#define PORTD_PIN3_DIR				OUTPUT
	#define PORTD_PIN4_DIR				OUTPUT
	#define PORTD_PIN5_DIR				OUTPUT
	#define PORTD_PIN6_DIR				OUTPUT
	#define PORTD_PIN7_DIR  		    OUTPUT
	
	/* 
		Choose between LOW for: 1. floating input	2. low output
					  HIGH for: 1. pullup input		2. high output
	*/
	
	#define PORTA_PIN0_INITIAl_VALUE		LOW
	#define PORTA_PIN1_INITIAl_VALUE		LOW
	#define PORTA_PIN2_INITIAl_VALUE		LOW
	#define PORTA_PIN3_INITIAl_VALUE		LOW
	#define PORTA_PIN4_INITIAl_VALUE		LOW
	#define PORTA_PIN5_INITIAl_VALUE		LOW
	#define PORTA_PIN6_INITIAl_VALUE		LOW
	#define PORTA_PIN7_INITIAl_VALUE	    LOW
							  
	#define PORTB_PIN0_INITIAl_VALUE		LOW
	#define PORTB_PIN1_INITIAl_VALUE		LOW
	#define PORTB_PIN2_INITIAl_VALUE		LOW
	#define PORTB_PIN3_INITIAl_VALUE		LOW
	#define PORTB_PIN4_INITIAl_VALUE		LOW
	#define PORTB_PIN5_INITIAl_VALUE		LOW
	#define PORTB_PIN6_INITIAl_VALUE		LOW
	#define PORTB_PIN7_INITIAl_VALUE	    LOW
							  
	#define PORTC_PIN0_INITIAl_VALUE		LOW
	#define PORTC_PIN1_INITIAl_VALUE		LOW
	#define PORTC_PIN2_INITIAl_VALUE		LOW
	#define PORTC_PIN3_INITIAl_VALUE		LOW
	#define PORTC_PIN4_INITIAl_VALUE		LOW
	#define PORTC_PIN5_INITIAl_VALUE		LOW
	#define PORTC_PIN6_INITIAl_VALUE		LOW
	#define PORTC_PIN7_INITIAl_VALUE	    LOW
							  
	#define PORTD_PIN0_INITIAl_VALUE		LOW
	#define PORTD_PIN1_INITIAl_VALUE		LOW
	#define PORTD_PIN2_INITIAl_VALUE		LOW
	#define PORTD_PIN3_INITIAl_VALUE		LOW
	#define PORTD_PIN4_INITIAl_VALUE		LOW
	#define PORTD_PIN5_INITIAl_VALUE		LOW
	#define PORTD_PIN6_INITIAl_VALUE		LOW
	#define PORTD_PIN7_INITIAl_VALUE	    LOW

#endif
