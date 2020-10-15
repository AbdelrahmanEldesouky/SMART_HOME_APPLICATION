/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: SSD						************/
/************		Date: 2-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

	#define COMMON_ANODE_TYPE		0
	#define COMMON_CATHODE_TYPE 	1
	
	#define SSD_OFF			0
	#define SSD_ON			1
	
	typedef struct
	{
		uint8 SSD_uint8PORT ;
		uint8 SSD_uint8EN_PORT ;
		uint8 SSD_uint8EN_PIN ;
		uint8 SSD_uint8TYPE ;
	} SSD_CONFIG ;
	
	uint8 SSD_uint8DISPLAYNUMBER (SSD_CONFIG * ssd , uint8 Copy_uint8Number) ;
	uint8 SSD_uint8DISPLAYChar (SSD_CONFIG * ssd , uint8 Copy_uint8Char) ;
	uint8 SSD_uint8CONTROL (SSD_CONFIG * ssd , uint8 Copy_uint8State) ;


#endif
