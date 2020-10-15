/***************************************************************/
/***************************************************************/
 /************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: TIMERS						************/
/************		Date: 26-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

/*File Gard*/
#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

	#define TIMER0_OVF_VECTOR_ID		11
	#define TIMER0_CTC_VECTOR_ID		10

	#define TIMER1_OVF_VECTOR_ID		9
	#define TIMER1_CTCB_VECTOR_ID		8
	#define TIMER1_CTCA_VECTOR_ID		7
	#define TIMER1_ICU_VECTOR_ID		6

	#define TIMER2_OVF_VECTOR_ID		5
	#define TIMER2_CTC_VECTOR_ID		4

	uint8 TIMERS_uint8SetCallBackFunc(void (*Copy_pvCallBackFunc)(void) , uint8 Copy_uint8VectorID) ;

	void TIMER0_VoidInit(void) ;
	void TIMER0_VoidSetPreload (uint8 Copy_uint8Preload) ;
	void TIMER0_VoidSetCTC (uint8 Copy_uint8CTC) ;
	uint8 TIMER0_uint8GetTimerValue (void) ;
	
	void TIMER1_VoidInit(void) ;
	void TIMER1_VoidSetPreload (uint16 Copy_uint16Preload) ;
	void TIMER1_VoidSetCTCA (uint16 Copy_uint16CTCA) ;
	void TIMER1_VoidSetCTCB (uint16 Copy_uint16CTCB) ;
	void TIMER1_VoidSetICR1 (uint16 Copy_uint16ICR1) ;
	uint16 TIMER1_uint16GetTimerValue (void) ;

	void TIMER2_VoidInit(void) ;
	void TIMER2_VoidSetPreload (uint8 Copy_uint8Preload) ;
	void TIMER2_VoidSetCTC (uint8 Copy_uint8CTC) ;
	uint8 TIMER2_uint8GetTimerValue (void) ;

#endif
