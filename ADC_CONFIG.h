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
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/* Select the voltage reference
 * Choose between
 * 1. ADC_AREF_REFERENCE
 * 2. ADC_AVCC_REFERENCR
 * 3. ADC_INTERNAL_VOLTAGE
 */
#define ADC_VOLTAGE_REFERENCE		ADC_AVCC_REFERENCR

/* Set Left Adjust Result
 * Choose between
 * 1. ADC_RESOLUTION_10_BIT
 * 2. ADC_RESOLUTION_8_BIT
 */
#define ADC_RESOLUTION		ADC_RESOLUTION_8_BIT

/* Set ADC Prescaler
 * Choose between
 * 1. ADC_DIVISION_FACTOR_2
 * 2. ADC_DIVISION_FACTOR_4
 * 3. ADC_DIVISION_FACTOR_8
 * 4. ADC_DIVISION_FACTOR_16
 * 5. ADC_DIVISION_FACTOR_32
 * 6. ADC_DIVISION_FACTOR_64
 * 7. ADC_DIVISION_FACTOR_128
 */
#define ADC_PRESCALER_SELECTION		ADC_DIVISION_FACTOR_128

/*Set Timeout for ADC_uint8StartSingleConversionSynch
 * Choose uint32 value
 * Make sure you write UL after you number
 */
#define ADC_uint32TIMEOUT			10000UL

/* Set ADC Peripheral Control
 * Choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define ADC_PERIPHERAL_CONTROL		ENABLE

#endif
