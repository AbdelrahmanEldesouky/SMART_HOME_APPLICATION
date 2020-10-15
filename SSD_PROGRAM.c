/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: SSD						************/
/************		Date: 2-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#include "STD_TYPE.h"

#include "DIO_INTERFACE.h"
#include "PORT_INTERFACE.h"

#include "SSD_INTERFACE.h"
#include "SSD_PRIVET.h"

uint8 SSD_uint8DISPLAYNUMBER (SSD_CONFIG * ssd , uint8 Copy_uint8Number)
{
	uint8 Local_uint8ErrorState = OK ;
	static uint8 Local_uint8NumbersArr[10] = SSD_NUMBER_ARR ;
	if (Copy_uint8Number < 10)
	{
		if (ssd->SSD_uint8TYPE == COMMON_CATHODE_TYPE)
		{
			DIO_uint8PortValue(ssd->SSD_uint8PORT, Local_uint8NumbersArr[Copy_uint8Number]) ;
		}
		else if (ssd->SSD_uint8TYPE == COMMON_ANODE_TYPE)
		{
			DIO_uint8PortValue(ssd->SSD_uint8PORT , ~Local_uint8NumbersArr[Copy_uint8Number]) ;
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
uint8 SSD_uint8DISPLAYChar (SSD_CONFIG * ssd , uint8 Copy_uint8Char)
{
	uint8 Local_uint8ErrorState = OK ;
	if (ssd->SSD_uint8TYPE == COMMON_CATHODE_TYPE)
	{
		DIO_uint8PortValue(ssd->SSD_uint8PORT , Copy_uint8Char) ;
	}
	else if (ssd->SSD_uint8TYPE == COMMON_ANODE_TYPE)
	{
		DIO_uint8PortValue(ssd->SSD_uint8PORT , ~Copy_uint8Char) ;
	}
	else
	{
		Local_uint8ErrorState = NOK ;
	}
	return Local_uint8ErrorState ;
}
uint8 SSD_uint8CONTROL (SSD_CONFIG * ssd , uint8 Copy_uint8State)
{
	uint8 Local_uint8ErrorState = OK ;

	if (Copy_uint8State == SSD_OFF)
	{
		if (ssd->SSD_uint8TYPE == COMMON_ANODE_TYPE)
		{

		DIO_uint8SetPinValue(ssd->SSD_uint8EN_PORT , ssd->SSD_uint8EN_PIN , SSD_OFF) ;
		}
		else if (ssd->SSD_uint8TYPE == COMMON_CATHODE_TYPE)
		{
			DIO_uint8SetPinValue(ssd->SSD_uint8EN_PORT , ssd->SSD_uint8EN_PIN , !SSD_OFF) ;
		}
		else
		{
			Local_uint8ErrorState = NOK ;
		}
	}
	else if (Copy_uint8State == SSD_ON)
	{
		if (ssd->SSD_uint8TYPE == COMMON_ANODE_TYPE)
		{

			DIO_uint8SetPinValue(ssd->SSD_uint8EN_PORT , ssd->SSD_uint8EN_PIN , SSD_ON) ;
		}
		else if (ssd->SSD_uint8TYPE == COMMON_CATHODE_TYPE)
		{
			DIO_uint8SetPinValue(ssd->SSD_uint8EN_PORT , ssd->SSD_uint8EN_PIN , !SSD_ON) ;
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
