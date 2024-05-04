/* 
 * File:   Bit_Math.h
 * Author: Karim Emad
 *
 * Created on September 12, 2023, 8:49 PM
 */

#ifndef BIT_MATH_H
#define	BIT_MATH_H

/*Includes Section*/

/*Macros Section*/

/*Function Like Macro Section*/
#define SET_BIT(REG , BIT)     					(REG |= (1<<BIT))
#define CLEAR_BIT(REG , BIT)  				    (REG &= ~(1<<BIT))
#define TOGGLE_BIT(REG , BIT)  					(REG ^= (1<<BIT))
#define READ_BIT(REG , BIT)    					((REG >> BIT)&1)
#define READ_REG(REG)							((REG))
#define WRITE_REG(REG , VAL)					(REG = VAL)
#define MODIFY_REG(REG , CLEARMASK , SETMASK)	(WRITE_REG(REG , (READ_REG(REG)) & (~(CLEARMASK)) | (SETMASK)))

/*Data Type Declaration Section*/

/*Function Declaration Section*/



#endif	/* BIT_MATH_H */
