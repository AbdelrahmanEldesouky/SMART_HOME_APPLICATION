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
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

	#define SINGLE						0
	#define CHAIN						1

	#define DISABLE						0
	#define ENABLE						1

	#define ADC_AREF_REFERENCE		 	0
	#define ADC_AVCC_REFERENCR		 	1
	#define ADC_INTERNAL_VOLTAGE	 	3

	#define ADC_PRESCALER_MASK			0b11111000

	#define ADC_DIVISION_FACTOR_2	 	0
	#define ADC_DIVISION_FACTOR_4	 	2
	#define ADC_DIVISION_FACTOR_8	 	3
	#define ADC_DIVISION_FACTOR_16	 	4
	#define ADC_DIVISION_FACTOR_32		5
	#define ADC_DIVISION_FACTOR_64	 	6
	#define ADC_DIVISION_FACTOR_128	 	7

	#define ADC_CHANNEL_MASK			0b11100000

#endif
