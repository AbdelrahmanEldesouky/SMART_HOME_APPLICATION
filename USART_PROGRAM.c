/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: USART						************/
/************		Date: 6-10-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/


#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "USART_CONFIG.h"
#include "USART_INTERFACE.h"
#include "USART_PRIVATE.h"
#include "USART_REGISTER.h"

/*Global variable to carry the send Data*/
static const char * USART_puint8SendData = NULL ;

/*Global variable to carry the Receive Data*/
static uint8 * USART_puint8ReceiveData = NULL ;

/*Global variable to carry the buffer size*/
static uint8 USART_uint8BufferSize ;

/*Global variable to indicate for the current Data index of the buffer*/
static uint8 USART_uint8Index ;

/*Global pointer to function to carry the notification function called by ISR*/
static void (* USART_pvNotificationFunc)(void)= NULL;

/*Global flag for the USART Busy State*/
static uint8 USART_uint8State= ACTIVE ;

void USART_VoidInit (void)
{
	/*Set Baud Rate*/
	uint8 Local_uint8UCSRC = 0 ;
	uint8 Local_uint8UBRRH = 0 ;
	uint16 Local_uint16UBRR = (uint16)((SYSTEM_FREQUENCY / (16 * USART_BAUD_RATE)) - 1) ;

	#if (USART_MODE == ASYNCHRONOUS) && (USART_SYSTEM_SPEED == USART_X1)

		CLR_BIT(UCSRA , UCSRA_U2X) ;

	#elif (USART_MODE == ASYNCHRONOUS) && (USART_SYSTEM_SPEED == USART_X2)

		Local_uint16UBRR /= 2 ;
		SET_BIT(UCSRA , UCSRA_U2X) ;

	#elif (USART_MODE == SYNCHRONOUS)

		Local_uint16UBRR /= 8 ;

	#else
		#error "Wrong USART_MODE or USART_SYSTEM_SPEED config"
	#endif

	UBRRL = (uint8)Local_uint16UBRR ;
	UBRRH = (Local_uint8UBRRH >> 8) ;

	/*Multi-Processor Communication mode*/
	#if USART_MPCM == DISABLE
		CLR_BIT(UCSRA , UCSRA_MPCM) ;
	#elif USART_MPCM == ENABLE
		SET_BIT(UCSRA , UCSRA_MPCM) ;
	#else
		#error "Wrong USART_MPCM config"
	#endif

	/*UCSRC Register Config*/

	/*USART Mode*/
	#if USART_MODE == ASYNCHRONOUS
		CLR_BIT(Local_uint8UCSRC , UCSRC_UMSEL) ;
	#elif USART_MODE == SYNCHRONOUS
		SET_BIT(Local_uint8UCSRC , UCSRC_UMSEL) ;
	#else
		#error "Wrong USART_MODE config"
	#endif

	/*Parity Mode*/
	#if USART_PARITY_MODE == DISABLE
		CLR_BIT(Local_uint8UCSRC , UCSRC_UPM0) ;
		CLR_BIT(Local_uint8UCSRC , UCSRC_UPM1) ;
	#elif USART_PARITY_MODE == EVEN_PARITY
		CLR_BIT(Local_uint8UCSRC , UCSRC_UPM0) ;
		SET_BIT(Local_uint8UCSRC , UCSRC_UPM1) ;
	#elif USART_PARITY_MODE == ODD_PARITY
		SET_BIT(Local_uint8UCSRC , UCSRC_UPM0) ;
		SET_BIT(Local_uint8UCSRC , UCSRC_UPM1) ;
	#else
		#error "Wrong USART_PARITY_MODE config"
	#endif

	/*Stop Bit*/
	#if USART_STOP_BIT == STOP_BIT_1
		CLR_BIT(Local_uint8UCSRC , UCSRC_USBS) ;
	#elif USART_STOP_BIT == STOP_BIT_2
		SET_BIT(Local_uint8UCSRC , UCSRC_USBS) ;
	#else
		#error "Wrong USART_STOP_BIT config"
	#endif

	/*Data Size*/
	#if USART_DATA_SIZE == DATA_SIZE_5_BIT
		CLR_BIT(Local_uint8UCSRC , UCSRC_UCSZ0) ;
		CLR_BIT(Local_uint8UCSRC , UCSRC_UCSZ1) ;
		CLR_BIT(UCSRB , UCSRB_UCSZ2) ;
	#elif USART_DATA_SIZE == DATA_SIZE_6_BIT
		SET_BIT(Local_uint8UCSRC , UCSRC_UCSZ0) ;
		CLR_BIT(Local_uint8UCSRC , UCSRC_UCSZ1) ;
		CLR_BIT(UCSRB , UCSRB_UCSZ2) ;
	#elif USART_DATA_SIZE == DATA_SIZE_7_BIT
		CLR_BIT(Local_uint8UCSRC , UCSRC_UCSZ0) ;
		SET_BIT(Local_uint8UCSRC , UCSRC_UCSZ1) ;
		CLR_BIT(UCSRB , UCSRB_UCSZ2) ;
	#elif USART_DATA_SIZE == DATA_SIZE_8_BIT
		SET_BIT(Local_uint8UCSRC , UCSRC_UCSZ0) ;
		SET_BIT(Local_uint8UCSRC , UCSRC_UCSZ1) ;
		CLR_BIT(UCSRB , UCSRB_UCSZ2) ;
	#elif USART_DATA_SIZE == DATA_SIZE_5_BIT
		SET_BIT(Local_uint8UCSRC , UCSRC_UCSZ0) ;
		SET_BIT(Local_uint8UCSRC , UCSRC_UCSZ1) ;
		SET_BIT(UCSRB , UCSRB_UCSZ2) ;
	#else
		#error "Wrong USART_DATA_SIZE config"
	#endif

	/*Clock Polarity (for SYNCHRONOUS mode only)*/
	#if USART_MODE == SYNCHRONOUS
		#if USART_CLOCK_POLARITY == XCK_RISING_TX_XCH_FALLING_RX
			CLR_BIT(Local_uint8UCSRC , UCSRC_UCPOL) ;
		#elif USART_CLOCK_POLARITY == XCK_RISING_RX_XCH_FALLING_TX
			SET_BIT(Local_uint8UCSRC , UCSRC_UCPOL) ;
		#else
			#error "Wrong USART_STOP_BIT config"
		#endif
	#endif

	/*Set UCSRC Mode*/
	SET_BIT(Local_uint8UCSRC , UCSRC_URSEL) ;

	/*Store the value in UCSRC Register*/
	UCSRC = Local_uint8UCSRC ;

	/*RX Complete Interrupt Enable*/
	#if USART_RX_COMPLETE_INTERRUPT == DISABLE
		CLR_BIT(UCSRB , UCSRB_RXCIE) ;
	#elif USART_RX_COMPLETE_INTERRUPT == ENABLE
		SET_BIT(UCSRB , UCSRB_RXCIE) ;
	#else
		#error "Wrong USART_RX_COMPLETE_INTERRUPT config"
	#endif

	/*TX Complete Interrupt Enable*/
	#if USART_TX_COMPLETE_INTERRUPT == DISABLE
		CLR_BIT(UCSRB , UCSRB_TXCIE) ;
	#elif USART_TX_COMPLETE_INTERRUPT == ENABLE
		SET_BIT(UCSRB , UCSRB_TXCIE) ;
	#else
		#error "Wrong USART_TX_COMPLETE_INTERRUPT config"
	#endif

	/*UDR Empty Interrupt Enable*/
	#if USART_UDR_EMPTY_INTERRUPT == DISABLE
		CLR_BIT(UCSRB , UCSRB_UDRIE) ;
	#elif USART_UDR_EMPTY_INTERRUPT == ENABLE
		SET_BIT(UCSRB , UCSRB_UDRIE) ;
	#else
		#error "Wrong USART_UDR_EMPTY_INTERRUPT config"
	#endif

	/*Receive Enable*/
	#if USART_RECEIVER_ENABLE == DISABLE
		CLR_BIT(UCSRB , UCSRB_RXEN) ;
	#elif USART_RECEIVER_ENABLE == ENABLE
		SET_BIT(UCSRB , UCSRB_RXEN) ;
	#else
		#error "Wrong USART_RECEIVER_ENABLE config"
	#endif

	/*Transmitter Enable*/
	#if USART_TRANSMITTER_ENABLE == DISABLE
		CLR_BIT(UCSRB , UCSRB_TXEN) ;
	#elif USART_TRANSMITTER_ENABLE == ENABLE
		SET_BIT(UCSRB , UCSRB_TXEN) ;
	#else
		#error "Wrong USART_TRANSMITTER_ENABLE config"
	#endif
}

uint8 USART_uint8SendData (uint8 Copy_uint8Data)
{
	uint8 Local_uint8ErrorState = OK ;
	uint32 Local_uint32TimeoutCounter = 0 ;
	if (USART_uint8State == ACTIVE)
	{
		USART_uint8State = BUSY ;

		/*Wait until a receive complete*/
		while (((GET_BIT(UCSRA , UCSRA_UDRE)) == 0) && (Local_uint32TimeoutCounter != USART_uint32TIMEOUT))
		{
			Local_uint32TimeoutCounter++ ;
		}
		if (Local_uint32TimeoutCounter == USART_uint32TIMEOUT)
		{
			Local_uint8ErrorState = TIMEOUT_STATE ;
		}
		else
		{
			UDR = Copy_uint8Data ;
		}

		USART_uint8State = ACTIVE ;
	}
	else
	{
		Local_uint8ErrorState = BUSY_STATE ;
	}
	return Local_uint8ErrorState ;
}

uint8 USART_uint8RecevieData (uint8 * Copy_uint8ReceviedData)
{
	uint8 Local_uint8ErrorState ;
	uint32 Local_uint32TimeoutCounter = 0 ;
	if (Copy_uint8ReceviedData != NULL)
	{
		if (USART_uint8State == ACTIVE)
		{
			USART_uint8State = BUSY ;

			/*Wait until a receive complete*/
			while (((GET_BIT(UCSRA , UCSRA_RXC)) == 0) && (Local_uint32TimeoutCounter != USART_uint32TIMEOUT))
			{
				Local_uint32TimeoutCounter++ ;
			}
			if (Local_uint32TimeoutCounter == USART_uint32TIMEOUT)
			{
				Local_uint8ErrorState = TIMEOUT_STATE ;
			}
			else
			{
				* Copy_uint8ReceviedData = UDR ;
			}

			USART_uint8State = ACTIVE ;
		}
		else
		{
			Local_uint8ErrorState = BUSY_STATE ;
		}
	}
	else
	{
		Local_uint8ErrorState = NULL_POINTER ;
	}

	return Local_uint8ErrorState ;
}

uint8 USART_uint8SendStingSynch (const char * Copy_pchString)
{
	uint8 Local_uint8ErrorState = OK ;

	uint32 Local_uint32Index = 0 ;

	if (Copy_pchString != NULL)
	{
		while (Copy_pchString[Local_uint32Index] != '\0')
		{
			Local_uint8ErrorState = USART_uint8SendData(Copy_pchString[Local_uint32Index]) ;
			Local_uint32Index++ ;
			if (Local_uint8ErrorState != OK)
			{
				return Local_uint8ErrorState ;
			}
		}
	}
	else
	{
		Local_uint8ErrorState = NULL_POINTER ;
	}

	return Local_uint8ErrorState ;
}

uint8 USART_uint8SendStingAsynch (const char * Copy_pchString , void (* NotificationFunc)(void))
{
	uint8 Local_uint8ErrorState = OK ;

	if (USART_uint8State == ACTIVE)
	{
		if ((Copy_pchString != NULL) && (NotificationFunc != NULL))
		{
			/*USART is now Busy*/
			USART_uint8State = BUSY ;

			/*Assign the USART data globally*/
			USART_puint8SendData = Copy_pchString ;
			USART_pvNotificationFunc = NotificationFunc ;

			/*Set Index to first element*/
			USART_uint8Index = 0 ;

			/*Send first Data */
			UDR = USART_puint8SendData[USART_uint8Index] ;

			/*USART Transmit Interrupt Enable*/
			SET_BIT(UCSRB , UCSRB_TXCIE) ;
		}
		else
		{
			Local_uint8ErrorState = NULL_POINTER ;
		}
	}
	else
	{
		Local_uint8ErrorState = BUSY_STATE ;
	}

	return Local_uint8ErrorState ;
}

uint8 USART_uint8ReceiveBufferSynch (uint8 * Copy_pchString , uint32 Copy_uint32BufferSize)
{
	uint8 Local_uint8ErrorState = OK ;

	uint32 Local_uint32Index = 0 ;

	if (Copy_pchString != NULL)
	{
		while (Local_uint32Index < Copy_uint32BufferSize)
		{
			Local_uint8ErrorState = USART_uint8RecevieData(&Copy_pchString[Local_uint32Index]) ;
			Local_uint32Index++ ;

			if (Local_uint8ErrorState != OK)
			{
				break ;
			}
		}
	}
	else
	{
		Local_uint8ErrorState = NULL_POINTER ;
	}

	return Local_uint8ErrorState ;
}

uint8 USART_uint8ReceiveBufferAsynch (uint8 * Copy_pchString , uint32 Copy_uint32BufferSize , void (* NotificationFunc)(void))
{
	uint8 Local_uint8ErrorState = OK ;

	if (USART_uint8State == ACTIVE)
	{
		if ((Copy_pchString != NULL) && (NotificationFunc != NULL))
		{
			/*USART is now Busy*/
			USART_uint8State = BUSY ;

			/*Assign the USART data globally*/
			USART_puint8ReceiveData = Copy_pchString ;
			USART_pvNotificationFunc = NotificationFunc ;

			/*Set Index to first element*/
			USART_uint8Index = 0 ;

			/*USART Transmit Interrupt Enable*/
			SET_BIT(UCSRB , UCSRB_RXCIE) ;
		}
		else
		{
			Local_uint8ErrorState = NULL_POINTER ;
		}
	}
	else
	{
		Local_uint8ErrorState = BUSY_STATE ;
	}

	return Local_uint8ErrorState ;
}

void __vector_13 (void)		__attribute__ ((signal)) ;
void __vector_13 (void)
{
	/*Increment Data index of the buffer*/
	USART_uint8Index++ ;

	if (USART_uint8Index == USART_uint8BufferSize)
	{
		/*Send Data Complete*/

		/*USART is now Active*/
		USART_uint8State = ACTIVE ;

		/*Call Notification Function*/
		USART_pvNotificationFunc() ;

		/*USART Transmit Interrupt Enable*/
		CLR_BIT(UCSRB , UCSRB_TXCIE) ;
	}
	else
	{
		/*Send Data not Complete*/

		/*Send next Data*/
		UDR = USART_puint8SendData[USART_uint8Index] ;
	}
}

void __vector_15 (void)		__attribute__ ((signal)) ;
void __vector_15 (void)
{
	/*Receive next Data*/
	USART_puint8ReceiveData[USART_uint8Index] = UDR ;

	/*Increment Data index of the buffer*/
	USART_uint8Index++ ;
	if (USART_puint8ReceiveData[USART_uint8Index] == USART_uint8BufferSize)
	{
		/*Receive Data Complete*/

		/*USART is now Active*/
		USART_uint8State = ACTIVE ;

		/*Call Notification Function*/
		USART_pvNotificationFunc() ;

		/*USART Receive Interrupt Enable*/
		CLR_BIT(UCSRB , UCSRB_RXCIE) ;
	}
	else
	{
		/*Do Noting*/
	}
}
