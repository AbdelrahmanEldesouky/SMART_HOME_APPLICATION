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
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

	typedef struct
	{
		uint8 * ADC_Channel ;
		uint8 ChainSize ;
		uint16 * ADC_Result ;
		void (*NotificationFunc)(void) ;
	}ADC_Chain;

	void ADC_VoidInit(void) ;
	
	void ADC_VoidEnable (void) ;

	void ADC_VoidDisable (void) ;

	void ADC_VoidInterruptEnable (void) ;

	void ADC_VoidInterruptDisable (void) ;

	uint8 ADC_uint8StartSingleConversionSynch (uint8 Copy_uint8Channel , uint16 * Copy_puint16Result) ;

	uint8 ADC_uint8StartSingleConversionAsynch (uint8 Copy_uint8Channel , uint16 * Copy_puint16Result , void (*Copy_pvNotificationFunc)(void)) ;

	uint8 ADC_uint8StartChainConversionAsynch (ADC_Chain * Copy_Chain) ;

	
	#define ADC_RESOLUTION_10_BIT		0
	#define ADC_RESOLUTION_8_BIT		1

	#define ADC_CHANNEL_SINGLE_ADC0							0
	#define ADC_CHANNEL_SINGLE_ADC1							1
	#define ADC_CHANNEL_SINGLE_ADC2							2
	#define ADC_CHANNEL_SINGLE_ADC3							3
	#define ADC_CHANNEL_SINGLE_ADC4							4
	#define ADC_CHANNEL_SINGLE_ADC5							5
	#define ADC_CHANNEL_SINGLE_ADC6							6
	#define ADC_CHANNEL_SINGLE_ADC7							7
	#define ADC_CHANNEL_DIFF_ADC0_P_ADC0_N_GAIN_10			8
	#define ADC_CHANNEL_DIFF_ADC1_P_ADC0_N_GAIN_10			9
	#define ADC_CHANNEL_DIFF_ADC0_P_ADC0_N_GAIN_200			10
	#define ADC_CHANNEL_DIFF_ADC1_P_ADC0_N_GAIN_200			11
	#define ADC_CHANNEL_DIFF_ADC2_P_ADC2_N_GAIN_10			12
	#define ADC_CHANNEL_DIFF_ADC3_P_ADC2_N_GAIN_10			13
	#define ADC_CHANNEL_DIFF_ADC2_P_ADC2_N_GAIN_200			14
	#define ADC_CHANNEL_DIFF_ADC3_P_ADC2_N_GAIN_200			15
	#define ADC_CHANNEL_DIFF_ADC0_P_ADC1_N_GAIN_1			16
	#define ADC_CHANNEL_DIFF_ADC1_P_ADC1_N_GAIN_1			17
	#define ADC_CHANNEL_DIFF_ADC2_P_ADC1_N_GAIN_1			18
	#define ADC_CHANNEL_DIFF_ADC3_P_ADC1_N_GAIN_1			19
	#define ADC_CHANNEL_DIFF_ADC4_P_ADC1_N_GAIN_1			20
	#define ADC_CHANNEL_DIFF_ADC5_P_ADC1_N_GAIN_1			21
	#define ADC_CHANNEL_DIFF_ADC6_P_ADC1_N_GAIN_1			22
	#define ADC_CHANNEL_DIFF_ADC7_P_ADC2_N_GAIN_1			23
	#define ADC_CHANNEL_DIFF_ADC0_P_ADC2_N_GAIN_1			24
	#define ADC_CHANNEL_DIFF_ADC1_P_ADC2_N_GAIN_1			25
	#define ADC_CHANNEL_DIFF_ADC2_P_ADC2_N_GAIN_1			26
	#define ADC_CHANNEL_DIFF_ADC3_P_ADC2_N_GAIN_1			27
	#define ADC_CHANNEL_DIFF_ADC4_P_ADC2_N_GAIN_1			28
	#define ADC_CHANNEL_DIFF_ADC5_P_AD2C_N_GAIN_1			29
	#define ADC_CHANNEL_1220m_VOLT							30
	#define ADC_CHANNEL_GND									31

#endif
