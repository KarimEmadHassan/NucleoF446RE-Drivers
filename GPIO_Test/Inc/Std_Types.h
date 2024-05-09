/* 
 * File:   MCAL_Std_Types.h
 * Author: Karim Emad

 *
 * Created on September 12, 2023, 8:50 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H


/*Includes Section*/
#include "Bit_Math.h"

/*Function Like Macro Section*/

/*Data Type Declaration Section*/
typedef unsigned char   uint8;
typedef unsigned short  uint16;
typedef unsigned long   uint32;

typedef signed char   sint8;
typedef signed short  sint16;
typedef signed long   sint32;

typedef uint8 Std_ReturnType;

/*Macros Section*/
#define E_OK        (Std_ReturnType)0x01
#define E_NOT_OK    (Std_ReturnType)0x00
#define NULL		((void *) 0)
/*Function Declaration Section*/


#endif	/* MCAL_STD_TYPES_H */

