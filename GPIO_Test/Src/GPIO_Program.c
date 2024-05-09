/* 
 * File:   GPIO_Program.c
 * Author: Karim Emad

 *
 * Created on May 6, 2024, 8:50 PM
 */
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Stm32f446xx.h"
#include "GPIO_Config.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"

static GPIO_TypeDef *GPIO_Arr[3] = {GPIOA , GPIOB , GPIOC};
/**
* Function Name:    HAL_GPIO_Init
* Description:		the function Initialize a pin
* Parameters:	    1.GPIO_config_t: The user configuration of the pin
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_GPIO_Init (const GPIO_config_t *Pin_Config){
	Std_ReturnType ret = E_OK;
	if ( NULL == Pin_Config ){
		ret = E_NOT_OK;
	}
	else {
		ret = GPIO_Pin_Mode_Config (Pin_Config);
	}
	return ret;
}

/**
* Function Name:    HAL_GPIO_Set_Pin_Value
* Description:		the function sets the value of a pin
* Parameters:	    1.GPIO_config_t: The user configuration of the pin
* Parameters:	    2.Pin_Value: The desired value wanted to be wrriten on the pin
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_GPIO_Set_Pin_Value (const GPIO_config_t *Pin_Config , uint8 Pin_Value){
	Std_ReturnType ret = E_OK;
	if ( NULL == Pin_Config ){
		ret = E_NOT_OK;
	}
	else {
		switch (Pin_Value) {
			case GPIO_HIGH:
				GPIO_Arr[Pin_Config -> Port] -> BSRR = ( 1 << ((Pin_Config->Pin)/2) );
				break;
			case GPIO_LOW:
				GPIO_Arr[Pin_Config -> Port] -> BSRR = ( 1 << (((Pin_Config->Pin)/2)+16) );
				break;
			default:
				ret = E_NOT_OK;
				break;
		}
	}
	return ret;
}

/**
* Function Name:    HAL_GPIO_Get_Pin_Value
* Description:		the function gets the value of a pin
* Parameters:	    1.GPIO_config_t: The user configuration of the pin
* Parameters:	    2.Pin_Value: The value on the pin
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_GPIO_Get_Pin_Value (const GPIO_config_t *Pin_Config , uint8 *Pin_Value){
	Std_ReturnType ret = E_OK;
	if ( NULL == Pin_Config || NULL == Pin_Value ){
		ret = E_NOT_OK;
	}
	else {
		if ( Pin_Config -> Pin_Direction == GPIO_OUTPUT ){
			*Pin_Value = READ_BIT( GPIO_Arr[Pin_Config -> Port] -> ODR , (Pin_Config -> Pin)/2 );
		}
		else if ( Pin_Config -> Pin_Direction == GPIO_INPUT ){
			*Pin_Value = READ_BIT( GPIO_Arr[Pin_Config -> Port] -> ODR , (Pin_Config -> Pin)/2 );
		}
		else {
			ret = E_NOT_OK;
		}
	}
	return ret;
}

/**
* Function Name:    HAL_GPIO_Set_Pin_Direction
* Description:		the function sets the direction of a pin
* Parameters:	    1.GPIO_config_t: The user configuration of the pin
* Parameters:	    2.Pin_Direction: The desired direction wanted to be wrriten on the pin
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_GPIO_Set_Pin_Direction (const GPIO_config_t *Pin_Config , uint8 Pin_Direction){
	Std_ReturnType ret = E_OK;
	if ( NULL == Pin_Config ){
		ret = E_NOT_OK;
	}
	else {
		switch (Pin_Direction) {
			case GPIO_INPUT:
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> MODER , (Pin_Config->Pin) );
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> MODER , ((Pin_Config->Pin)+1) );
				break;
			case GPIO_OUTPUT:
				SET_BIT( GPIO_Arr[Pin_Config -> Port] -> MODER , (Pin_Config->Pin) );
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> MODER , ((Pin_Config->Pin)+1) );
				break;
			case GPIO_AF:
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> MODER , (Pin_Config->Pin) );
				SET_BIT( GPIO_Arr[Pin_Config -> Port] -> MODER , ((Pin_Config->Pin)+1) );
				break;
			case GPIO_ANALOG:
				SET_BIT( GPIO_Arr[Pin_Config -> Port] -> MODER , (Pin_Config->Pin) );
				SET_BIT( GPIO_Arr[Pin_Config -> Port] -> MODER , ((Pin_Config->Pin)+1) );
				break;
			default:
				ret = E_NOT_OK;
				break;
		}
	}
	return ret;
}

/**
* Function Name:    HAL_GPIO_Toggle_Pin
* Description:		the function toggles the logic on the pin
* Parameters:	    1.GPIO_config_t: The user configuration of the pin
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_GPIO_Toggle_Pin (const GPIO_config_t *Pin_Config){
	Std_ReturnType ret = E_OK;
	if ( NULL == Pin_Config ){
		ret = E_NOT_OK;
	}
	else {
		TOGGLE_BIT( GPIO_Arr[Pin_Config->Port] -> ODR , (Pin_Config->Pin)/2);
	}
	return ret;
}


static Std_ReturnType GPIO_Pin_Mode_Config (const GPIO_config_t *Pin_Config){
	Std_ReturnType ret = E_OK;
	if ( NULL == Pin_Config ){
		ret = E_NOT_OK;
	}
	else {
		/*GPIO port output type register*/
		switch (Pin_Config -> Pin_connection) {
			case GPIO_PUSH_PULL:
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> OTYPER , (Pin_Config->Pin)/2);
				break;
			case GPIO_OPEN_DRAIN:
				SET_BIT( GPIO_Arr[Pin_Config -> Port] -> OTYPER , (Pin_Config->Pin)/2);
				break;
			default:
				ret = E_NOT_OK;
				break;
		}
		/*GPIO port mode register */
		switch (Pin_Config -> Pin_Direction) {
			case GPIO_INPUT:
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> MODER , (Pin_Config->Pin) );
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> MODER , ((Pin_Config->Pin)+1) );
				break;
			case GPIO_OUTPUT:
				SET_BIT( GPIO_Arr[Pin_Config -> Port] -> MODER , (Pin_Config->Pin) );
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> MODER , ((Pin_Config->Pin)+1) );
				break;
			case GPIO_AF:
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> MODER , (Pin_Config->Pin) );
				SET_BIT( GPIO_Arr[Pin_Config -> Port] -> MODER , ((Pin_Config->Pin)+1) );
				break;
			case GPIO_ANALOG:
				SET_BIT( GPIO_Arr[Pin_Config -> Port] -> MODER , (Pin_Config->Pin) );
				SET_BIT( GPIO_Arr[Pin_Config -> Port] -> MODER , ((Pin_Config->Pin)+1) );
				break;
			default:
				ret = E_NOT_OK;
				break;
		}
		/*GPIO port pull-up/pull-down register*/
		switch (Pin_Config -> Pin_Pull) {
			case GPIO_FLOATING:
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> PUPDR , (Pin_Config->Pin) );
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> PUPDR , ((Pin_Config->Pin)+1) );
				break;
			case GPIO_PULL_UP:
				SET_BIT( GPIO_Arr[Pin_Config -> Port] -> PUPDR , (Pin_Config->Pin) );
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> PUPDR , ((Pin_Config->Pin)+1) );
				break;
			case GPIO_PULL_DOWN:
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> PUPDR , (Pin_Config->Pin) );
				SET_BIT( GPIO_Arr[Pin_Config -> Port] -> PUPDR , ((Pin_Config->Pin)+1) );
				break;
			default:
				ret = E_NOT_OK;
				break;
		}
		/*GPIO port output speed register*/
		switch (Pin_Config -> Pin_Speed) {
			case GPIO_OUTPUT_LOW_SPEED:
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> PUPDR , (Pin_Config->Pin) );
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> PUPDR , ((Pin_Config->Pin)+1) );
				break;
			case GPIO_OUTPUT_MEDIUM_SPEED:
				SET_BIT( GPIO_Arr[Pin_Config -> Port] -> PUPDR , (Pin_Config->Pin) );
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> PUPDR , ((Pin_Config->Pin)+1) );
				break;
			case GPIO_OUTPUT_FAST_SPEED:
				CLEAR_BIT( GPIO_Arr[Pin_Config -> Port] -> PUPDR , (Pin_Config->Pin) );
				SET_BIT( GPIO_Arr[Pin_Config -> Port] -> PUPDR , ((Pin_Config->Pin)+1) );
				break;
			case GPIO_OUTPUT_HIGH_SPEED:
				SET_BIT( GPIO_Arr[Pin_Config -> Port] -> PUPDR , (Pin_Config->Pin) );
				SET_BIT( GPIO_Arr[Pin_Config -> Port] -> PUPDR , ((Pin_Config->Pin)+1) );
				break;
			default:
				ret = E_NOT_OK;
				break;
		}
	}
	return ret;
}
