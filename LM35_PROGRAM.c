/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: LM35						************/
/************		Date: 3-10-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_INTERFACE.h"
#include "ADC_INTERFACE.h"

#include "LM35_INTERFACE.h"
#include "LM35_PRIVET.h"

uint8 LM35_uint8GetTempSynch (LM35_CONFIG * lm35 , uint8 * Copy_uint8TempValue)
{
	uint8 Local_uint8ErrorState = OK ;
	uint16 Local_uint8ADCReference = (lm35->Copy_uint8ADCVoltageReference * 1000) ;
	uint16 Local_uint8ADCResolution ;
	uint16 Local_uint16ADCResult ;
	uint16 Local_uint16_AnalogValue ;

	if (lm35->Copy_uint8ADCResolution == ADC_RESOLUTION_10_BIT)
	{
		Local_uint8ADCResolution = 1024 ;
	}
	else if (lm35->Copy_uint8ADCResolution == ADC_RESOLUTION_8_BIT)
	{
		Local_uint8ADCResolution = 256 ;
	}

	ADC_uint8StartSingleConversionSynch(lm35->Copy_uint8LM35Channel , &Local_uint16ADCResult) ;

	Local_uint16_AnalogValue = (uint16)(((uint32) Local_uint16ADCResult * (uint32)Local_uint8ADCReference) / (uint32)Local_uint8ADCResolution) ;

	* Copy_uint8TempValue = (uint8)(Local_uint16_AnalogValue / (uint16)10) ;

	return Local_uint8ErrorState ;
}
