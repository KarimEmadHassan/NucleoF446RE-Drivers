/* 
* File:   RCC_Program.c
* Author: Karim Emad
*
* Created on May 2, 2024, 8:50 PM
*/
#include "Bit_Math.h"
#include "Std_Types.h"
#include "Stm32f446xx.h"
#include "RCC_Interface.h"
#include "RCC_Config.h"
#include "RCC_Private.h"

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
			RCC -> CR   = 0x00000001;
			RCC -> CFGR = 0x00;
			while ( !(READ_BIT(RCC -> CR , 1)) );
		}
		else if ( Clk_Config -> System_Clock == HSE_BYPASS_SYS_CLK){
			RCC -> CFGR = 0x00000001;
			RCC -> CR   = 0x00050000;
			while ( !(READ_BIT(RCC -> CR , 17)) );
		}
		else if ( Clk_Config -> System_Clock == HSE_RC_SYS_CLK){
			RCC -> CFGR = 0x00000001;
			RCC -> CR   = 0x00010000;
			while ( !(READ_BIT(RCC -> CR , 17)) );
		}
		else if ( Clk_Config -> System_Clock == PLL_SYS_CLK || Clk_Config -> System_Clock == PLLR_SYS_CLK){
			ret = RCC_PLL_Config(Clk_Config);
		}
		else{
			ret = E_NOT_OK;
		}
		/*Set the AHB prescaler*/
		MODIFY_REG(RCC->CFGR , 0xFUL << 4U , Clk_Config->AHB_Prescaler);
		/*Set the APB1 prescaler*/
		MODIFY_REG(RCC->CFGR , 0x7UL << 10U , Clk_Config->APB1_Prescaler);
		/*Set the APB2 prescaler*/
		MODIFY_REG(RCC->CFGR , 0x7UL << 13U , Clk_Config->APB2_Prescaler);
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
	else if ( Peripheral > 31 && Peripheral < 49 ){
		Peripheral = Peripheral - 40;
		SET_BIT( (RCC->AHB2ENR) , Peripheral);
	}
	else if ( Peripheral > 49 && Peripheral < 59 ){
		Peripheral = Peripheral - 50;
		SET_BIT( (RCC->AHB3ENR) , Peripheral);
	}
	else if ( Peripheral > 59 && Peripheral < 90 ){
		Peripheral = Peripheral - 60;
		SET_BIT( (RCC->APB1ENR) , Peripheral);
	}
	else if ( Peripheral > 90 && Peripheral < 114 ){
		Peripheral = Peripheral - 90;
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
	else if ( Peripheral > 31 && Peripheral < 49 ){
		Peripheral = Peripheral - 40;
		CLEAR_BIT( (RCC->AHB2ENR) , Peripheral);
	}
	else if ( Peripheral > 49 && Peripheral < 59 ){
		Peripheral = Peripheral - 50;
		CLEAR_BIT( (RCC->AHB3ENR) , Peripheral);
	}
	else if ( Peripheral > 59 && Peripheral < 90 ){
		Peripheral = Peripheral - 60;
		CLEAR_BIT( (RCC->APB1ENR) , Peripheral);
	}
	else if ( Peripheral > 90 && Peripheral < 114 ){
		Peripheral = Peripheral - 90;
		CLEAR_BIT( (RCC->APB2ENR) , Peripheral);
	}
	else {
		ret = E_NOT_OK;
	}
	return ret;
}

static Std_ReturnType RCC_PLL_Config (RCC_config_t *Clk_Config){
	Std_ReturnType ret = E_OK;
	/*Configure division and multiplication factors*/
	if ( (Clk_Config -> PLLM > 1 || Clk_Config -> PLLM <= 63) &&
		(Clk_Config -> PLLN > 1 || Clk_Config -> PLLN <= 432) &&
	    (Clk_Config -> PLLP > 1 || Clk_Config -> PLLP <= 8) )
	{
		/*Configure M,N,P,R*/
		RCC -> PLLCFGR = 0x00000000;
		RCC -> PLLCFGR |= (Clk_Config ->PLLM) << 0;
		RCC -> PLLCFGR |= (Clk_Config ->PLLN) << 6;
		Clk_Config ->PLLP = ((Clk_Config ->PLLP) - 2) / 2;
		RCC -> PLLCFGR |= (Clk_Config ->PLLP) << 16;
	}
	else { /* Nothing*/ }
	/*Configure PLL clock source*/
	if ( Clk_Config -> PLL_Source == PLL_HSI_CLK){
		CLEAR_BIT( RCC -> PLLCFGR , 22);
	}
	else if ( Clk_Config -> PLL_Source == PLL_HSE_CLK){
		SET_BIT( RCC -> PLLCFGR , 22);
	}
	else {
		ret = E_NOT_OK;
	}
	/*Configure the PLLR parameter*/
	if ( Clk_Config -> System_Clock == PLLR_SYS_CLK ){
		if ( Clk_Config -> PLLR > 1 || Clk_Config -> PLLR <= 7 ){
			RCC -> PLLCFGR |= (Clk_Config ->PLLR) << 28;
		}
		else { /* Nothing*/ }
		RCC -> CR   = 0x01000000;
		RCC -> CFGR = 0x00000011;
	}
	else {
		RCC -> CR   = 0x01000000;
		RCC -> CFGR = 0x00000010;
	}
	while ( !(READ_BIT(RCC -> CR , 25)) );
	return ret;
}
