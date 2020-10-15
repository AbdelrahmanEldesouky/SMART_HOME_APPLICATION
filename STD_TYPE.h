/*
 * StdType.h
 *
 * Created: 7/19/2020 8:07:32 PM
 *  Author: A-ELDESOUKY
 */ 


#ifndef STDTYPE_H_
#define STDTYPE_H_
	
	typedef unsigned char uint8 ; 
	typedef signed char int8 ;
	
	typedef unsigned short uint16 ;
	typedef signed short int16 ;
	
	typedef unsigned long uint32 ;
	typedef signed long int32 ;
	
	typedef unsigned long long uint64 ;
	typedef signed long long int64 ;
	
	typedef float float32 ;
	typedef double float64 ;
	
	typedef enum
	{
		fasle,
		true,
	}bool;

	#define ACTIVE 			0
	#define BUSY			1

	#define OK				0
	#define NOK 			1
	#define NULL_POINTER	2
	#define TIMEOUT_STATE	3
	#define BUSY_STATE		4

	#define NULL 			0

#endif /* STDTYPE_H_ */
