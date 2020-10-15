/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: DIO						************/
/************		Date: 24-8-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_CONFIG.h"
#include "DIO_INTERFACE.h"
#include "DIO_PRIVATE.h"
#include "DIO_REGISTER.h"

	
uint8 DIO_uint8SetPinValue(uint8 Copy_uint8Port , uint8 Copy_uint8Pin , uint8 Copy_uint8Value)
{
	uint8 Local_uint8ErrorState = OK ;
	if ((Copy_uint8Pin <= DIO_uint8PIN7))
	{
		if (Copy_uint8Value == DIO_uint8_LOW)
		{
			switch (Copy_uint8Port)
			{
			case DIO_uint8PORTA: CLR_BIT(PORTA , Copy_uint8Pin) ; break ;
			case DIO_uint8PORTB: CLR_BIT(PORTB , Copy_uint8Pin) ; break ;
			case DIO_uint8PORTC: CLR_BIT(PORTC , Copy_uint8Pin) ; break ;
			case DIO_uint8PORTD: CLR_BIT(PORTD , Copy_uint8Pin) ; break ;
			default: Local_uint8ErrorState = NOK ;
			}
		}
		else if (Copy_uint8Value == DIO_uint8_HIGH)
		{
			switch (Copy_uint8Port)
			{
			case DIO_uint8PORTA: SET_BIT(PORTA , Copy_uint8Pin) ; break ;
			case DIO_uint8PORTB: SET_BIT(PORTB , Copy_uint8Pin) ; break ;
			case DIO_uint8PORTC: SET_BIT(PORTC , Copy_uint8Pin) ; break ;
			case DIO_uint8PORTD: SET_BIT(PORTD , Copy_uint8Pin) ; break ;
			default: Local_uint8ErrorState = NOK ;
			}
		}
		else
		{
			Local_uint8ErrorState = NOK ;
		}
	}
	else
	{
		Local_uint8ErrorState = NOK ;
	}
	return Local_uint8ErrorState ;
}
	
uint8 DIO_uint8PortValue(uint8 Copy_uint8Port , uint8 Copy_uint8Value) 
{
	uint8 Local_uint8ErrorState = OK ;
	switch (Copy_uint8Port)
	{
	case DIO_uint8PORTA: PORTA = Copy_uint8Value; break ;
	case DIO_uint8PORTB: PORTB = Copy_uint8Value; break ;
	case DIO_uint8PORTC: PORTC = Copy_uint8Value; break ;
	case DIO_uint8PORTD: PORTD = Copy_uint8Value; break ;
	default: Local_uint8ErrorState = NOK ; 		  break ;
	}
	return Local_uint8ErrorState ;
}
	
uint8 DIO_uint8GetPinValue(uint8 Copy_uint8Port , uint8 Copy_uint8Pin , uint8 * Copy_puint8Value) 
{
	uint8 Local_uint8ErrorState = OK ;
	if ((Copy_puint8Value != NULL) && (Copy_uint8Pin <= DIO_uint8PIN7))
	{
		switch (Copy_uint8Port)
		{
		case DIO_uint8PORTA: *Copy_puint8Value = GET_BIT(PINA , Copy_uint8Pin) ; break ;
		case DIO_uint8PORTB: *Copy_puint8Value = GET_BIT(PINB , Copy_uint8Pin) ; break ;
		case DIO_uint8PORTC: *Copy_puint8Value = GET_BIT(PINC , Copy_uint8Pin) ; break ;
		case DIO_uint8PORTD: *Copy_puint8Value = GET_BIT(PIND , Copy_uint8Pin) ; break ;
		default: Local_uint8ErrorState = NOK ; 									 break ;
		}
	}
	else
	{
		Local_uint8ErrorState = NOK ;
	}
	return Local_uint8ErrorState ;
}
uint8 DIO_uint8ToggelPinValue	(uint8 Copy_uint8Port , uint8 Copy_uint8Pin)
{
	uint8 Local_uint8ErrorState = OK ;
	if (Copy_uint8Pin <= DIO_uint8PIN7)
	{
		switch (Copy_uint8Port)
		{
		case DIO_uint8PORTA: DIO_uint8SetPinValue(PORTA , Copy_uint8Pin , TOGGLE_BIT(PORTA, Copy_uint8Pin)) ; break ;
		case DIO_uint8PORTB: DIO_uint8SetPinValue(PORTB , Copy_uint8Pin , TOGGLE_BIT(PORTB, Copy_uint8Pin)) ; break ;
		case DIO_uint8PORTC: DIO_uint8SetPinValue(PORTC , Copy_uint8Pin , TOGGLE_BIT(PORTC, Copy_uint8Pin)) ; break ;
		case DIO_uint8PORTD: DIO_uint8SetPinValue(PORTD , Copy_uint8Pin , TOGGLE_BIT(PORTD, Copy_uint8Pin)) ; break ;
		default: Local_uint8ErrorState = NOK ; break ;
		}
	}
	else
	{
		Local_uint8ErrorState = NOK ;
	}
	return Local_uint8ErrorState ;
}
