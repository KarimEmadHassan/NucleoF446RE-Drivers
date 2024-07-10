/* 
 * File:   STK_Interface.h
 * Author: Karim Emad

 *
 * Created on May 10, 2024, 8:50 PM
 */
 
#ifndef STK_INTERFACE_H 
#define STK_INTERFACE_H

#define STK_AHB_8_CLK				0
#define STK_AHB_CLK					1

#define STK_DISABLE					0
#define STK_ENABLE					1

#define STK_SINGLE_SHOT				0
#define STK_MULTI_SHOT				1

/****************Pin Config****************/
typedef struct {
	uint8 stk_clk ;							/*To choose the systick clock from STK_AHB_8_CLK or STK_AHB_CLK*/
	uint32 stk_value;						/*To choose the value of the counter to be inserted in the VAL register*/
	void (*stk_InterruptHandler) (void);	/*Callback function*/
}STK_config_t;

/************************************* Prototypes Section *************************************/
/**
* Function Name:    HAL_STK_Init
* Description:		the function initalise systick timer
* Parameters:	    1.Stk_Config: The user configuration of the timer
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_STK_Init 		    	(const STK_config_t *Stk_Config);
/**
* Function Name:    HAL_STK_Deinit
* Description:		the function stops systick timer
* Parameters:	    1.Stk_Config: The user configuration of the timer
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_STK_Deinit 		    	(const STK_config_t *Stk_Config);
/**
* Function Name:    HAL_STK_Set_Busy_Wait
* Description:		the function waits for the timer to finish (Sync. Function)
* Parameters:	    1.Stk_Config: The user configuration of the timer
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_STK_Set_Busy_Wait    	(const STK_config_t *Stk_Config);
/**
* Function Name:    HAL_STK_Set_Single_Shot
* Description:		the function sets the timer for a single shot (Async. Function)
* Parameters:	    1.Stk_Config: The user configuration of the timer
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_STK_Set_Single_Shot  	(const STK_config_t *Stk_Config);
/**
* Function Name:    HAL_STK_Set_Single_Shot
* Description:		the function sets the timer for a single shot (Async. Function)
* Parameters:	    1.Stk_Config: The user configuration of the timer
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_STK_Set_Multi_Shot  		(const STK_config_t *Stk_Config);
/**
* Function Name:    HAL_STK_Get_Elapsed_Time
* Description:		the function gets the elapsed time
* Parameters:	    1.Stk_Config:   The user configuration of the timer
* Parameters:	    2.Elapsed_Time: The time counted by the timer
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_STK_Get_Elapsed_Time 	(const STK_config_t *Stk_Config , uint32 *Elapsed_Time);
/**
* Function Name:    HAL_STK_Get_Remaining_Time
* Description:		the function gets the remaining time
* Parameters:	    1.Stk_Config:   The user configuration of the timer
* Parameters:	    2.Remaining_Time: The time remaind by the timer to back to zero
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_STK_Get_Remaining_Time   (const STK_config_t *Stk_Config , uint32 *Remaining_Time);

#endif
 
