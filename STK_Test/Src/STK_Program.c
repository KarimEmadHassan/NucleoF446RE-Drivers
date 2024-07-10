/* 
 * File:   STK_Program.c
 * Author: Karim Emad

 *
 * Created on May 10, 2024, 8:50 PM
 */
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Stm32f446xx.h"
#include "STK_Config.h"
#include "STK_Interface.h"
#include "STK_Private.h"

static void (*STK_InterruptHandler) (void) = NULL ;
static uint8 STK_Interval_Mode = 0;
/**
* Function Name:    HAL_STK_Init
* Description:		the function initalise systick timer
* Parameters:	    1.Stk_Config: The user configuration of the timer
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_STK_Init (const STK_config_t *Stk_Config){
	Std_ReturnType ret = E_OK;
	if ( NULL == Stk_Config ){
		ret = E_NOT_OK;
	}
	else {
		/*Disable the moduale*/
		CLEAR_BIT( (SYSTICK -> CTRL) , 0);
		/*Clock source selection*/
		if ( Stk_Config -> stk_clk == STK_AHB_CLK ){
			SET_BIT( (SYSTICK -> CTRL ) , 2);
		}
		else if ( Stk_Config -> stk_clk == STK_AHB_8_CLK ){
			CLEAR_BIT( (SYSTICK -> CTRL ) , 2);
		}
		else {	/*Nothing*/  }
		/*Moduele Won't be enabled here because it will start counting*/
	}
	return ret;
}

/**
* Function Name:    HAL_STK_Deinit
* Description:		the function stops systick timer
* Parameters:	    1.Stk_Config: The user configuration of the timer
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_STK_Deinit (const STK_config_t *Stk_Config){
	Std_ReturnType ret = E_OK;
	if ( NULL == Stk_Config ){
		ret = E_NOT_OK;
	}
	else {
		/*Disable the moduale*/
		CLEAR_BIT( (SYSTICK -> CTRL) , 0);
		/*Disable the interrupt*/
		CLEAR_BIT( (SYSTICK -> CTRL) , 1);
		/*Set VAL & Reload to zero*/
		SYSTICK -> VAL = 0;
		SYSTICK -> LOAD = 0;
		/*CLear Flag*/
		CLEAR_BIT((SYSTICK -> CTRL) , 16);
	}
	return ret;
}

/**
* Function Name:    HAL_STK_Set_Busy_Wait
* Description:		the function waits for the timer to finish (Sync. Function)
* Parameters:	    1.Stk_Config: The user configuration of the timer
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_STK_Set_Busy_Wait (const STK_config_t *Stk_Config){
	Std_ReturnType ret = E_OK;
	if ( NULL == Stk_Config ){
		ret = E_NOT_OK;
	}
	else {
		/*Set reload value*/
		if ( Stk_Config -> stk_value <= 0x00FFFFFF ){
			SYSTICK -> LOAD = Stk_Config -> stk_value ;
			/*Enable the moduele*/
			SET_BIT( (SYSTICK -> CTRL) , 0);
			/*Wait for the flag to be 1*/
			while ( !(READ_BIT((SYSTICK -> CTRL) , 16)));
			/*Disable the moduale*/
			CLEAR_BIT( (SYSTICK -> CTRL) , 0);
			CLEAR_BIT( (SYSTICK -> CTRL) , 1);
			SYSTICK -> VAL = 0;
			SYSTICK -> LOAD = 0;
		}
	}
	return ret;
}

/**
* Function Name:    HAL_STK_Set_Single_Shot
* Description:		the function sets the timer for a single shot (Async. Function)
* Parameters:	    1.Stk_Config: The user configuration of the timer
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_STK_Set_Single_Shot (const STK_config_t *Stk_Config){
	Std_ReturnType ret = E_OK;
	if ( NULL == Stk_Config ){
		ret = E_NOT_OK;
	}
	else {
		/*Set reload value*/
		if ( (Stk_Config -> stk_value <= 0x00FFFFFF) ){
			SYSTICK -> LOAD = Stk_Config -> stk_value ;
			/*Enable the moduele*/
			SET_BIT( (SYSTICK -> CTRL) , 0);
			/*Assign the address of the callback function*/
			STK_InterruptHandler = Stk_Config -> stk_InterruptHandler;
			/* set mode of interval */
			STK_Interval_Mode = STK_SINGLE_INTERVAL;
			/*Enable interrupt*/
			SET_BIT( (SYSTICK -> CTRL) , 1);
		}

	}
	return ret;
}

/**
* Function Name:    HAL_STK_Set_Single_Shot
* Description:		the function sets the timer for a single shot (Async. Function)
* Parameters:	    1.Stk_Config: The user configuration of the timer
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_STK_Set_Multi_Shot (const STK_config_t *Stk_Config){
	Std_ReturnType ret = E_OK;
	if ( NULL == Stk_Config ){
		ret = E_NOT_OK;
	}
	else {
		/*Set reload value*/
		if ( (Stk_Config -> stk_value <= 0x00FFFFFF)){
			SYSTICK -> LOAD = (Stk_Config -> stk_value)-1 ;
			/*Enable the moduele*/
			SET_BIT( (SYSTICK -> CTRL) , 0);
			/*Assign the address of the callback function*/
			 STK_InterruptHandler = Stk_Config -> stk_InterruptHandler;
			 /* set mode of interval */
			 STK_Interval_Mode = STK_MULTI_INTERVAL;
			/*Enable interrupt*/
			SET_BIT( (SYSTICK -> CTRL) , 1);
		}

	}
	return ret;
}

/**
* Function Name:    HAL_STK_Get_Elapsed_Time
* Description:		the function gets the elapsed time
* Parameters:	    1.Stk_Config:   The user configuration of the timer
* Parameters:	    2.Elapsed_Time: The time counted by the timer
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_STK_Get_Elapsed_Time (const STK_config_t *Stk_Config , uint32 *Elapsed_Time){
	Std_ReturnType ret = E_OK;
	if ( NULL == Stk_Config || NULL == Elapsed_Time){
		ret = E_NOT_OK;
	}
	else {
		*Elapsed_Time = (SYSTICK -> LOAD) - (SYSTICK -> VAL);
	}
	return ret;
}

/**
* Function Name:    HAL_STK_Get_Remaining_Time
* Description:		the function gets the remaining time
* Parameters:	    1.Stk_Config:   The user configuration of the timer
* Parameters:	    2.Remaining_Time: The time remaind by the timer to back to zero
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_STK_Get_Remaining_Time (const STK_config_t *Stk_Config , uint32 *Remaining_Time){
	Std_ReturnType ret = E_OK;
	if ( NULL == Stk_Config || NULL == Remaining_Time ){
		ret = E_NOT_OK;
	}
	else {
		*Remaining_Time = (SYSTICK -> VAL) ;
	}
	return ret;
}

void SysTick_Handler (void){
	static volatile uint8 local_temp = 0;
	if ( STK_Interval_Mode == STK_SINGLE_INTERVAL){
		/*Disable the interrupt*/
		CLEAR_BIT( (SYSTICK -> CTRL) , 1);
		/*Disable the moduale*/
		CLEAR_BIT( (SYSTICK -> CTRL) , 0);
		/*Set VAL & Reload to zero*/
		SYSTICK -> VAL = 0;
		SYSTICK -> LOAD = 0;
	}

	if (STK_InterruptHandler != NULL){
		STK_InterruptHandler();
	}

	/*Read the flag to clear it*/
	local_temp = READ_BIT( (SYSTICK -> CTRL) , 16);
}
