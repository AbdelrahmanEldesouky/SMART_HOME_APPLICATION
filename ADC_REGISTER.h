/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: ADC						************/
/************		Date: 28-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

/*File Gard*/
#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_
	
	#define ADMUX			*((volatile uint8*)0X27)
	#define ADMUX_REFS1		7
	#define ADMUX_REFS0		6
	#define ADMUX_ADLAR		5
	
	#define ADSAR			*((volatile uint8*)0X26)
	#define ADSAR_ADEN		7
	#define ADSAR_ADSC		6
	#define ADSAR_ADATE		5
	#define ADSAR_ADIF		4
	#define ADSAR_ADIE		3
	
	#define ADCH			*((volatile uint8*)0X25)
	#define ADCL			*((volatile uint8*)0X24)

#endif
