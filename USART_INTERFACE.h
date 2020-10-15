/***************************************************************/
/***************************************************************/
 /************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: USART						************/
/************		Date: 6-10-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

/*File Gard*/
#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

	void USART_VoidInit (void) ; 

	uint8 USART_uint8SendData (uint8 Copy_uint8Data) ;

	uint8 USART_uint8RecevieData (uint8 * Copy_uint8ReceviedData) ;

	uint8 USART_uint8SendStingSynch (const char * Copy_pchString) ;
	uint8 USART_uint8SendStingAsynch (const char * Copy_pchString , void (* NotificationFunc)(void)) ;

	uint8 USART_uint8ReceiveBufferSynch (uint8 * Copy_pchString , uint32 Copy_uint32BufferSize) ;
	uint8 USART_uint8ReceiveBufferAsynch (uint8 * Copy_pchString , uint32 Copy_uint32BufferSize , void (* NotificationFunc)(void)) ;

#endif
