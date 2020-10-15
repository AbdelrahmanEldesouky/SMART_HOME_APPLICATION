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
#ifndef TIMERS_REGISTER_H_
#define TIMERS_REGISTER_H_
	
	#define TIMSK			*((volatile uint8*)0X59)
	#define TIMSK_TOIE0		0
	#define TIMSK_OCIE0		1
	#define TIMSK_TOIE1		2
	#define TIMSK_OCIE1B	3
	#define TIMSK_OCIE1A	4
	#define TIMSK_TICIE1	5
	#define TIMSK_TOIE2		6
	#define TIMSK_OCIE2		7

	#define TIFR			*((volatile uint8*)0X58)
	#define TIFR_TOV0		0
	#define TIFR_OCF0		1
	#define TIFR_TOV1		2
	#define TIFR_OCF1B		3
	#define TIFR_OCF1A		4
	#define TIFR_ICF1		5
	#define TIFR_TOV2		6
	#define TIFR_OCV2		7
	
	/*Timer0*/
	#define TCCR0			*((volatile uint8*)0X53)
	#define TCCR0_WGM00		6
	#define TCCR0_COM01		5
	#define TCCR0_COM00		4
	#define TCCR0_WGM01		3
	
	#define TCNT0			*((volatile uint8*)0X52)

	#define OCR0			*((volatile uint8*)0X5C)

	/*Timer1*/

	#define TCCR1A			*((volatile uint8*)0X4F)
	#define TCCR1A_COM1A1		7
	#define TCCR1A_COM1A0		6
	#define TCCR1A_COM1B1		5
	#define TCCR1A_COM1B0		4
	#define TCCR1A_WGM11		1
	#define TCCR1A_WGM10		0

	#define TCCR1B			*((volatile uint8*)0X4E)
	#define TCCR1B_ICNC1		7
	#define TCCR1B_ICES1		6
	#define TCCR1B_WGM13		4
	#define TCCR1B_WGM12		3

	#define TCNT1			*((volatile uint16*)0X4C)

	#define OCR1A			*((volatile uint16*)0X4A)

	#define OCR1B			*((volatile uint16*)0X48)

	#define ICR1			*((volatile uint16*)0X46)

	/*Timer2*/

	#define TCCR2			*((volatile uint8*)0X45)
	#define TCCR2_WGM20		6
	#define TCCR2_COM21		5
	#define TCCR2_COM20		4
	#define TCCR2_WGM21		3

	#define TCNT2			*((volatile uint8*)0X44)

	#define OCR2			*((volatile uint8*)0X43)

#endif
