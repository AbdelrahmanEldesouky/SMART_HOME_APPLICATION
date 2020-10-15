/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: LM35						************/
/************		Date: 3-10-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_
	
	typedef struct
	{
		uint8 Copy_uint8LM35Channel ;
		uint8 Copy_uint8ADCVoltageReference ;
		uint8 Copy_uint8ADCResolution ;
	} LM35_CONFIG ;
	
	uint8 LM35_uint8GetTempSynch (LM35_CONFIG * lm35 , uint8 * Copy_uint8TempValue) ;

#endif
