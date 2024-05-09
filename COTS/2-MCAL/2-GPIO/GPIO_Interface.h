/* 
 * File:   GPIO_Interface.h
 * Author: Karim Emad

 *
 * Created on May 6, 2024, 8:50 PM
 */
 
#ifndef GPIO_INTERFACE_H 
#define GPIO_INTERFACE_H

/****************Ports****************/
#define GPIO_PORTA			0
#define GPIO_PORTB			1
#define GPIO_PORTC			2

/****************Pins****************/
#define GPIO_PIN0			0
#define GPIO_PIN1			2
#define GPIO_PIN2			4
#define GPIO_PIN3			6
#define GPIO_PIN4			8
#define GPIO_PIN5			10
#define GPIO_PIN6			12
#define GPIO_PIN7			14
#define GPIO_PIN8			16
#define GPIO_PIN9			18
#define GPIO_PIN10			20
#define GPIO_PIN11			22
#define GPIO_PIN12			24
#define GPIO_PIN13			26
#define GPIO_PIN14			28
#define GPIO_PIN15			30

/****************Pin Direction****************/
#define GPIO_INPUT							0
#define GPIO_OUTPUT							1
#define GPIO_AF								2
#define GPIO_ANALOG							3

/****************Pin Push pull / Open drain****************/
#define GPIO_PUSH_PULL						0
#define GPIO_OPEN_DRAIN						1

/****************Output Pin Speed****************/
#define GPIO_OUTPUT_LOW_SPEED				0
#define GPIO_OUTPUT_MEDIUM_SPEED			1
#define GPIO_OUTPUT_FAST_SPEED				2
#define GPIO_OUTPUT_HIGH_SPEED				3

/****************Pin Pull****************/
#define GPIO_FLOATING						0
#define GPIO_PULL_UP						1
#define GPIO_PULL_DOWN						2


/****************Pin Value****************/
#define GPIO_LOW							0
#define GPIO_HIGH							1


/****************Pin Config****************/
typedef struct {
	uint8 Port:2;				/*To choose the Port from @Ports section above*/
	uint8 Pin:5;				/*To choose the Pin from @pins section above*/
	uint8 Pin_connection:1;		/*To choose the Pin from @Pin Push pull / Open drain section above*/
	uint8 Pin_Direction:2;		/*To choose the Pin Speed from @Pin Direction Pin Speed section above*/
	uint8 Pin_Pull :2;			/*To choose the Pin Speed from @Pin Pull section above*/
	uint8 Pin_Speed:2;			/*To choose the Pin Speed from @Output Pin Speed section above*/
	uint8 reserved :2;			/*NOT USED*/
}GPIO_config_t;

/************************************* Prototypes Section *************************************/
/**
* Function Name:    HAL_GPIO_Init
* Description:		the function Initialize a pin 
* Parameters:	    1.GPIO_config_t: The user configuration of the pin
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_GPIO_Init 			  (const GPIO_config_t *Pin_Config);
/**
* Function Name:    HAL_GPIO_Set_Pin_Value
* Description:		the function sets the value of a pin 
* Parameters:	    1.GPIO_config_t: The user configuration of the pin
* Parameters:	    2.Pin_Value: The desired value wanted to be wrriten on the pin
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_GPIO_Set_Pin_Value     (const GPIO_config_t *Pin_Config , uint8 Pin_Value);
/**
* Function Name:    HAL_GPIO_Get_Pin_Value
* Description:		the function gets the value of a pin 
* Parameters:	    1.GPIO_config_t: The user configuration of the pin
* Parameters:	    2.Pin_Value: The value on the pin
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_GPIO_Get_Pin_Value 	  (const GPIO_config_t *Pin_Config , uint8 *Pin_Value);
/**
* Function Name:    HAL_GPIO_Set_Pin_Direction
* Description:		the function sets the direction of a pin 
* Parameters:	    1.GPIO_config_t: The user configuration of the pin
* Parameters:	    2.Pin_Direction: The desired direction wanted to be wrriten on the pin
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_GPIO_Set_Pin_Direction (const GPIO_config_t *Pin_Config , uint8 Pin_Direction);

/**
* Function Name:    HAL_GPIO_Toggle_Pin
* Description:		the function toggles the logic on the pin 
* Parameters:	    1.GPIO_config_t: The user configuration of the pin
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_GPIO_Toggle_Pin 		  (const GPIO_config_t *Pin_Config);


#endif
 
