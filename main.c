#include "STD_TYPE.h"
#include <util/delay.h>

#include "PORT_INTERFACE.h"
#include "DIO_INTERFACE.h"
#include "USART_INTERFACE.h"
#include "TIMERS_INTERFACE.h"
#include "ADC_INTERFACE.h"

#include "LM35_INTERFACE.h"
#include "SSD_INTERFACE.h"

#include "BEEP_BUZZER.h"

#define ID_AND_PWD_SIZE			4
#define PWD_TRY					3

#define SSD_LOADING_TIME		1000

#define BLUETOOTH_MIN_VALUE		'0'

#define DOOR_OPEN_OPTION		'a'
#define DOOR_CLOSE_OPTION		'b'
#define LIGHT_OPEN_OPTION		'c'
#define LIGHT_CLOSE_OPTION		'd'
#define LIGHT_ADJUST_OPTION		'e'
#define FAN_OPEN_OPTION			'f'
#define FAN_CLOSE_OPTION		'g'
#define FAN_ADJUST_OPTION		'h'
#define MUSIC_PLAY_OPTION		'i'
#define SYSTEM_OFF_OPTION		'j'

void SmartHome_VoidID (void) ;
void SmartHome_VoidPWD (void) ;
void SmartHome_VoidControl (void) ;

void Door_VoidOpen1 (void) ;
void Door_VoidClose2 (void) ;
void Light_VoidOpen3 (void) ;
void Light_VoidClose4 (void) ;
void Light_VoidAdjust5 (void) ;
void Fan_VoidOpen6 (void) ;
void Fan_VoidClose7 (void) ;
void Fan_VoidAdjust8 (void) ;
void Music_VoidPlay9 (void) ;
void System_VoidOff10 (void) ;

void Buzzer_VoidToon (uint16 Copy_uint16beep , uint16 Copy_uint16delay) ;


LM35_CONFIG lm = {ADC_CHANNEL_SINGLE_ADC1 , 5 , ADC_RESOLUTION_8_BIT} ;
SSD_CONFIG ssd = {DIO_uint8PORTC , DIO_uint8PORTB , DIO_uint8PIN7 , COMMON_CATHODE_TYPE} ;

static uint8 Global_uint8Run = 0 ;

static uint8 Global_uint8ID[ID_AND_PWD_SIZE] = {0} ;
static uint8 Global_uint8PWD[ID_AND_PWD_SIZE] = {0} ;

void main (void)
{

	PORT_VoidInit() ;
	USART_VoidInit() ;
	TIMER0_VoidInit() ;
	TIMER1_VoidInit() ;
	TIMER2_VoidInit() ;
	ADC_VoidInit() ;

	while (1)
	{
		while (Global_uint8Run == 0)
		{
			SmartHome_VoidID() ;

			SmartHome_VoidPWD() ;

			SmartHome_VoidControl() ;
		}
	}
}

void SmartHome_VoidID (void)
{
	if (Global_uint8Run == 0)
	{
		uint8 Local_uint8BluetoothRes ;
		uint8 Local_uint8Counter = 0 ;

		USART_uint8SendStingSynch("Welcome in your Smart Home Application\nPlease enter your ID\n") ;

		while (Local_uint8Counter < ID_AND_PWD_SIZE)
		{
			USART_uint8RecevieData(&Local_uint8BluetoothRes) ;

			if ((Local_uint8BluetoothRes >= BLUETOOTH_MIN_VALUE))
			{
				Global_uint8ID[Local_uint8Counter++] = Local_uint8BluetoothRes ;
			}
		}

		USART_uint8SendStingSynch("\nWelcome ") ;
		for (Local_uint8Counter = 0 ; Local_uint8Counter < ID_AND_PWD_SIZE ; Local_uint8Counter++)
		{
			USART_uint8SendData(Global_uint8ID[Local_uint8Counter]) ;
		}
	}
}
void SmartHome_VoidPWD (void)
{
	if (Global_uint8Run == 0)
	{
		uint8 Local_uint8BluetoothRes ;
		uint8 Local_uint8Counter ;
		uint8 Local_uint8Try = PWD_TRY ;
		uint8 Local_uint8WrongPWDFlag = 0 ;

		SSD_uint8CONTROL(&ssd , SSD_ON) ;

		while (Global_uint8Run == 0)
		{
			SSD_uint8DISPLAYNUMBER(&ssd , Local_uint8Try--) ;
			USART_uint8SendStingSynch("\nPlease enter your Password\n") ;

			Local_uint8Counter = 0 ;
			while (Local_uint8Counter < ID_AND_PWD_SIZE)
			{
				USART_uint8RecevieData(&Local_uint8BluetoothRes) ;

				if ((Local_uint8BluetoothRes >= BLUETOOTH_MIN_VALUE))
				{
					Global_uint8PWD[Local_uint8Counter++] = Local_uint8BluetoothRes ;
				}
			}

			USART_uint8SendStingSynch("Your password is: ") ;
			for (Local_uint8Counter = 0 ; Local_uint8Counter < ID_AND_PWD_SIZE ; Local_uint8Counter++)
			{
				USART_uint8SendData(Global_uint8PWD[Local_uint8Counter]) ;

				if (Global_uint8PWD[Local_uint8Counter] != Global_uint8ID[ID_AND_PWD_SIZE - Local_uint8Counter - 1])
				{
					Local_uint8WrongPWDFlag = 1 ;
				}
			}

			if (Local_uint8WrongPWDFlag == 0)
			{
				SSD_uint8DISPLAYNUMBER(&ssd , 3) ;
				_delay_ms(SSD_LOADING_TIME) ;
				SSD_uint8DISPLAYNUMBER(&ssd , 2) ;
				_delay_ms(SSD_LOADING_TIME) ;
				SSD_uint8DISPLAYNUMBER(&ssd , 1) ;
				_delay_ms(SSD_LOADING_TIME) ;
				SSD_uint8DISPLAYNUMBER(&ssd , 0) ;
				_delay_ms(SSD_LOADING_TIME) ;
				SSD_uint8CONTROL(&ssd , SSD_OFF) ;
				break ;
			}
			else if (Local_uint8Try > 0)
			{
				USART_uint8SendStingSynch("\nWrong Password, Try Again..!") ;
			}
			else
			{
				USART_uint8SendStingSynch("\n\n\nSystem Failed :(\n") ;
				SSD_uint8CONTROL(&ssd , SSD_OFF) ;
				Global_uint8Run = 1 ;
			}
		}
	}
}
void SmartHome_VoidControl (void)
{
	if (Global_uint8Run == 0)
	{
		uint8 Local_uint8BluetoothRes ;

		USART_uint8SendStingSynch("Smart Home Option, please choose between:\na for Door Open\nb for Door Close\nc for Light Open\nd for Light Close\ne for Light Adjust\nf for Fan Open\ng for Fan Close\nh for Fan Adjust\ni for Music Play\nj for System Off\n") ;

		while (Global_uint8Run == 0)
		{
			USART_uint8RecevieData(&Local_uint8BluetoothRes) ;

			if (Local_uint8BluetoothRes >= BLUETOOTH_MIN_VALUE)
			{
				switch (Local_uint8BluetoothRes)
				{
				case DOOR_OPEN_OPTION : 	Door_VoidOpen1() ; 		break ;
				case DOOR_CLOSE_OPTION : 	Door_VoidClose2() ; 	break ;
				case LIGHT_OPEN_OPTION : 	Light_VoidOpen3() ; 	break ;
				case LIGHT_CLOSE_OPTION : 	Light_VoidClose4() ; 	break ;
				case LIGHT_ADJUST_OPTION : 	Light_VoidAdjust5() ; 	break ;
				case FAN_OPEN_OPTION : 		Fan_VoidOpen6() ; 		break ;
				case FAN_CLOSE_OPTION : 	Fan_VoidClose7() ; 		break ;
				case FAN_ADJUST_OPTION : 	Fan_VoidAdjust8() ; 	break ;
				case MUSIC_PLAY_OPTION :	Music_VoidPlay9() ; 	break ;
				case SYSTEM_OFF_OPTION : 	System_VoidOff10() ; 	break ;
				default: USART_uint8SendStingSynch("Wrong Choose, please try again") ; break ;
				}
			}
		}
	}
}

void Door_VoidOpen1 (void)
{
	TIMER1_VoidSetCTCA(2500) ;
}

void Door_VoidClose2 (void)
{
	TIMER1_VoidSetCTCA(500) ;
}

void Light_VoidOpen3 (void)
{
	TIMER1_VoidSetCTCB(20000) ;
}
void Light_VoidClose4 (void)
{
	TIMER1_VoidSetCTCB(0) ;
}
void Light_VoidAdjust5 (void)
{
	uint16 Local_uint16LDRValue ;
	ADC_uint8StartSingleConversionSynch(ADC_CHANNEL_SINGLE_ADC0 , &Local_uint16LDRValue) ;
	switch (Local_uint16LDRValue)
	{
	case 0 ... 185 :   TIMER1_VoidSetCTCB(20000) ; 	break ;
	case 186 ... 200 : TIMER1_VoidSetCTCB(15000) ; 	break ;
	case 201 ... 215 : TIMER1_VoidSetCTCB(10000) ; 	break ;
	case 216 ... 230 : TIMER1_VoidSetCTCB(5000) ; 	break ;
	case 231 ... 245 : TIMER1_VoidSetCTCB(0) ; 		break ;
	default: 		   TIMER1_VoidSetCTCB(0) ; 		break ;
	}
}

void Fan_VoidOpen6 (void)
{
	TIMER0_VoidSetCTC(255) ;
}
void Fan_VoidClose7 (void)
{
	TIMER0_VoidSetCTC(0) ;
}
void Fan_VoidAdjust8 (void)
{
	uint8 Local_uint8Temp ;
	LM35_uint8GetTempSynch(&lm , &Local_uint8Temp) ;
	switch (Local_uint8Temp)
	{
	case 24 ... 27 : TIMER0_VoidSetCTC(50) ; 	break ;
	case 28 ... 30 : TIMER0_VoidSetCTC(100) ; 	break ;
	case 31 ... 33 : TIMER0_VoidSetCTC(150) ; 	break ;
	case 34 ... 36 : TIMER0_VoidSetCTC(200) ; 	break ;
	default: 		 TIMER0_VoidSetCTC(255) ; 	break ;
	}
}

void Music_VoidPlay9 (void)
{
	Buzzer_VoidToon(a, 500);
	Buzzer_VoidToon(a, 500);
	Buzzer_VoidToon(a, 500);
	Buzzer_VoidToon(f, 350);
	Buzzer_VoidToon(cH, 150);
	Buzzer_VoidToon(a, 500);
	Buzzer_VoidToon(f, 350);
	Buzzer_VoidToon(cH, 150);
	Buzzer_VoidToon(a, 650);

	_delay_ms(500);

	Buzzer_VoidToon(eH, 500);
	Buzzer_VoidToon(eH, 500);
	Buzzer_VoidToon(eH, 500);
	Buzzer_VoidToon(fH, 350);
	Buzzer_VoidToon(cH, 150);
	Buzzer_VoidToon(gS, 500);
	Buzzer_VoidToon(f, 350);
	Buzzer_VoidToon(cH, 150);
	Buzzer_VoidToon(a, 650);

	_delay_ms(500);

	Buzzer_VoidToon(aH, 500);
	Buzzer_VoidToon(a, 300);
	Buzzer_VoidToon(a, 150);
	Buzzer_VoidToon(aH, 500);
	Buzzer_VoidToon(gSH, 325);
	Buzzer_VoidToon(gH, 175);
	Buzzer_VoidToon(fSH, 125);
	Buzzer_VoidToon(fH, 125);
	Buzzer_VoidToon(fSH, 250);

	_delay_ms(325);

	Buzzer_VoidToon(aS, 250);
	Buzzer_VoidToon(dSH, 500);
	Buzzer_VoidToon(dH, 325);
	Buzzer_VoidToon(cSH, 175);
	Buzzer_VoidToon(cH, 125);
	Buzzer_VoidToon(b, 125);
	Buzzer_VoidToon(cH, 250);

	_delay_ms(350);

	Buzzer_VoidToon(f, 250);
	Buzzer_VoidToon(gS, 500);
	Buzzer_VoidToon(f, 350);
	Buzzer_VoidToon(a, 125);
	Buzzer_VoidToon(cH, 500);
	Buzzer_VoidToon(a, 375);
	Buzzer_VoidToon(cH, 125);
	Buzzer_VoidToon(eH, 650);

	_delay_ms(500);

	Buzzer_VoidToon(aH, 500);
	Buzzer_VoidToon(a, 300);
	Buzzer_VoidToon(a, 150);
	Buzzer_VoidToon(aH, 500);
	Buzzer_VoidToon(gSH, 325);
	Buzzer_VoidToon(gH, 175);
	Buzzer_VoidToon(fSH, 125);
	Buzzer_VoidToon(fH, 125);
	Buzzer_VoidToon(fSH, 250);

	_delay_ms(325);

	Buzzer_VoidToon(aS, 250);
	Buzzer_VoidToon(dSH, 500);
	Buzzer_VoidToon(dH, 325);
	Buzzer_VoidToon(cSH, 175);
	Buzzer_VoidToon(cH, 125);
	Buzzer_VoidToon(b, 125);
	Buzzer_VoidToon(cH, 250);

	_delay_ms(350);

	Buzzer_VoidToon(f, 250);
	Buzzer_VoidToon(gS, 500);
	Buzzer_VoidToon(f, 375);
	Buzzer_VoidToon(cH, 125);
	Buzzer_VoidToon(a, 500);
	Buzzer_VoidToon(f, 375);
	Buzzer_VoidToon(cH, 125);
	Buzzer_VoidToon(a, 650);

	_delay_ms(650);
}

void System_VoidOff10 (void)
{
	Door_VoidClose2() ;
	Light_VoidClose4() ;
	Fan_VoidClose7() ;
	TIMER2_VoidSetCTC(0) ;
	USART_uint8SendStingSynch("\nSYSTEM CLOSING\n\n\nGood Bye sir... :)\n") ;
	Global_uint8Run = 1 ;
}


void Buzzer_VoidToon (uint16 Copy_uint16beep , uint16 Copy_uint16delay)
{
	TIMER2_VoidSetCTC((uint8)(Copy_uint16beep / 4)) ;
	_delay_ms(Copy_uint16delay) ;
	TIMER2_VoidSetCTC(0) ;
	_delay_ms(50) ;
}
