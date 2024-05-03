/* 
* File:   RCC_Program.c
* Author: Karim Emad
*
* Created on May 2, 2024, 8:50 PM
*/
#include "../../1-LIB/Bit_Math.h"
#include "../../1-LIB/Std_Types.h"
#include "../../1-LIB/Stm32f446xx.h"
#include "RCC_Interface"
#include "RCC_Config"
#include "RCC_Private"

/**
* Function Name:    HAL_RCC_Clk_Config
* Description:		the function Enables system clock
* Parameters:	    1.Clk_Config: The user configuration of the clock
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_RCC_Clk_Config (const RCC_config_t *Clk_Config){
	Std_ReturnType ret = E_OK;
	if ( NULL == Clk_Config ){
		ret = E_NOT_OK;
	}
	else {
		if ( Clk_Config -> System_Clock == HSI_SYS_CLK){
			
		}
		else if ( Clk_Config -> System_Clock == HSE_SYS_CLK){
			
		}
		else if ( Clk_Config -> System_Clock == PLL_SYS_CLK){
			
		}
		else if ( Clk_Config -> System_Clock == PLLR_SYS_CLK){
			
		}
		else 
	}
	return ret;
}

/**
* Function Name:    HAL_RCC_Enable_Clk
* Description:		the function Enables the clock on the different peripherals
* Parameters:	    1.Peripheral: The peripheral needed to be enabled
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_RCC_Enable_Clk (uint8 Peripheral){
	Std_ReturnType ret = E_OK;
	if ( Peripheral <= 31 ){
		SET_BIT( (RCC->AHB1ENR) , Peripheral);
	}
	else if ( Peripheral > 31 && peripheral < 49 ){
		SET_BIT( (RCC->AHB2ENR) , Peripheral);
	}
	else if ( Peripheral > 49 && peripheral < 59 ){
		SET_BIT( (RCC->AHB3ENR) , Peripheral);
	}
	else if ( Peripheral > 59 && peripheral < 90 ){
		SET_BIT( (RCC->APB1ENR) , Peripheral);
	}
	else if ( Peripheral > 90 && peripheral < 114 ){
		SET_BIT( (RCC->APB2ENR) , Peripheral);
	}
	else {
		ret = E_NOT_OK;
	}
	return ret;
}

/**
* Function Name:    HAL_RCC_Disable_Clk
* Description:		the function Disables the clock on the different peripherals
* Parameters:	    1.Peripheral: The peripheral needed to be enabled
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_RCC_Disable_Clk (uint8 Peripheral){
	Std_ReturnType ret = E_OK;
	if ( Peripheral <= 31 ){
		CLEAR_BIT( (RCC->AHB1ENR) , Peripheral);
	}
	else if ( Peripheral > 31 && peripheral < 49 ){
		CLEAR_BIT( (RCC->AHB2ENR) , Peripheral);
	}
	else if ( Peripheral > 49 && peripheral < 59 ){
		CLEAR_BIT( (RCC->AHB3ENR) , Peripheral);
	}
	else if ( Peripheral > 59 && peripheral < 90 ){
		CLEAR_BIT( (RCC->APB1ENR) , Peripheral);
	}
	else if ( Peripheral > 90 && peripheral < 114 ){
		CLEAR_BIT( (RCC->APB2ENR) , Peripheral);
	}
	else {
		ret = E_NOT_OK;
	}
	return ret;
}