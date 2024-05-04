/* 
 * File:   RCC_Interface.h
 * Author: Karim Emad

 *
 * Created on May 2, 2024, 8:50 PM
 */
 
#ifndef RCC_INTERFACE_H 
#define RCC_INTERFACE_H
 
/*AHB1 Peripherals*/
#define GPIOA_PERIPHERAL	       0
#define GPIOB_PERIPHERAL	       1
#define GPIOC_PERIPHERAL	       2
#define GPIOD_PERIPHERAL	       3
#define GPIOE_PERIPHERAL	       4
#define GPIOF_PERIPHERAL	       5
#define GPIOG_PERIPHERAL	       6
#define GPIOH_PERIPHERAL		   7
#define CRC_PERIPHERAL			   12
#define BKPSRAM_PERIPHERAL 		   18
#define DMA1_PERIPHERAL 		   21
#define DMA2_PERIPHERAL  		   22
#define USB_OTG_HS_PERIPHERAL 	   29
#define OTGHSULPI_PERIPHERAL	   30

/*AHB2 Peripherals*/
#define DCMI_PERIPHERAL	       	   40
#define USB_OTG_FS_PERIPHERAL  	   47

/*AHB3 Peripherals*/
#define FMC_PERIPHERAL	       	   50
#define QUADSPI_PERIPHERAL     	   51

/*APB1 Peripherals*/
#define TIM2_PERIPHERAL    	  	   60
#define TIM3_PERIPHERAL 	  	   61
#define TIM4_PERIPHERAL 	  	   62
#define TIM5_PERIPHERAL	      	   63
#define TIM6_PERIPHERAL 	  	   64
#define TIM7_PERIPHERAL	      	   65
#define TIM12_PERIPHERAL	  	   66
#define TIM13_PERIPHERAL	  	   67
#define TIM14_PERIPHERAL  	  	   68
#define WWDG_PERIPHERAL  	  	   71
#define SPI2_I2S2_PERIPHERAL  	   74
#define SPI3_I2S3_PERIPHERAL  	   75
#define SPDIFRX_PERIPHERAL    	   76
#define USART2_PERIPHERAL     	   77
#define USART3_PERIPHERAL     	   78
#define USART4_PERIPHERAL     	   79
#define USART5_PERIPHERAL     	   80
#define I2C1_PERIPHERAL    	  	   81
#define I2C2_PERIPHERAL    	  	   82
#define I2C3_PERIPHERAL       	   83
#define FMPI2C1_PERIPHERAL    	   84
#define CAN1_PERIPHERAL       	   85
#define CAN2_PERIPHERAL       	   86
#define CEC_PERIPHERAL   	  	   87
#define PWR_PERIPHERAL        	   88
#define DAC_PERIPHERAL        	   89

/*APB2 Peripherals*/	           
#define TIM1_PERIPHERAL    	  	   90
#define TIM8_PERIPHERAL 	  	   91
#define USART1_PERIPHERAL 	  	   94
#define USART6_PERIPHERAL	  	   95
#define ADC1_PERIPHERAL 	  	   98
#define ADC2_PERIPHERAL	      	   99
#define ADC3_PERIPHERAL	  	  	   100
#define SDIO_PERIPHERAL	  	  	   101
#define SPI1_PERIPHERAL  	  	   102
#define SPI4_PERIPHERAL       	   103
#define SYSCFG_PERIPHERAL     	   104
#define TIM9_PERIPHERAL       	   106
#define TIM10_PERIPHERAL      	   107
#define TIM11_PERIPHERAL      	   108
#define SAI1_PERIPHERAL       	   112
#define SAI2_PERIPHERAL       	   113

/*System Clock*/
#define HSI_SYS_CLK				   0
#define HSE_BYPASS_SYS_CLK		   1
#define HSE_RC_SYS_CLK		   	   2
#define PLL_SYS_CLK				   3
#define PLLR_SYS_CLK			   4

/*PLL clock source*/
#define PLL_HSI_CLK				   0
#define PLL_HSE_CLK				   1

/*AHB prescaler values*/
#define RCC_AHB_PRESCALER_DIV_1			0x00000000
#define RCC_AHB_PRESCALER_DIV_2			0x00000080
#define RCC_AHB_PRESCALER_DIV_4			0x00000090
#define RCC_AHB_PRESCALER_DIV_8	 		0x000000A0
#define RCC_AHB_PRESCALER_DIV_16		0x000000B0
#define RCC_AHB_PRESCALER_DIV_64		0x000000C0
#define RCC_AHB_PRESCALER_DIV_128		0x000000D0
#define RCC_AHB_PRESCALER_DIV_256		0x000000E0
#define RCC_AHB_PRESCALER_DIV_512		0x000000F0

/*APB1 prescaler values*/
#define RCC_APB1_PRESCALER_DIV_1		0x00000000
#define RCC_APB1_PRESCALER_DIV_2		0x00001000
#define RCC_APB1_PRESCALER_DIV_4		0x00001400
#define RCC_APB1_PRESCALER_DIV_8	 	0x00001800
#define RCC_APB1_PRESCALER_DIV_16		0x00001C00

/*APB2 prescaler values*/
#define RCC_APB2_PRESCALER_DIV_1		0x00000000
#define RCC_APB2_PRESCALER_DIV_2		0x00008000
#define RCC_APB2_PRESCALER_DIV_4		0x0000A000
#define RCC_APB2_PRESCALER_DIV_8	 	0x0000C000
#define RCC_APB2_PRESCALER_DIV_16		0x0000E000

/*System Clock Config*/
typedef struct {
	uint8 System_Clock :4;	/*To choose the system clock from @System Clock section above*/
	uint8 PLL_Source   :1;	/*To choose the system clock from HSI or HSE*/
	uint8 PLLR         :3;	/*To choose the Value of Multiplication factor R*/
	uint16 PLLM        :6;	/*To choose the Value of division factor M*/
	uint16 PLLN        :9;	/*To choose the Value of Multiplication factor N*/
	uint8 PLLP         :4;	/*To choose the Value of Multiplication factor P*/
	uint8 RCC_Reserved :4;  /*NOT USED*/
	uint32 AHB_Prescaler;	/*To choose the system clock status from @AHB prescaler values section above*/
	uint32 APB1_Prescaler;	/*To choose the system clock status from @APB1 prescaler values section above*/
	uint32 APB2_Prescaler;	/*To choose the system clock status from @APB2 prescaler values section above*/
}RCC_config_t;

/************************************* Prototypes Section *************************************/
/**
* Function Name:   HAL_RCC_Clk_Config
* Description:		the function Enables system clock
* Parameters:	    1.Clk_Config: The user configuration of the clock
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_RCC_Clk_Config (const RCC_config_t *Clk_Config);

/**
* Function Name:   HAL_RCC_Enable_Clk
* Description:		the function Enables the clock on the different peripherals
* Parameters:	    1.Peripheral: The peripheral needed to be enabled
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_RCC_Enable_Clk (uint8 Peripheral);

/**
* Function Name:   HAL_RCC_Disable_Clk
* Description:		the function Disables the clock on the different peripherals
* Parameters:	    1.Peripheral: The peripheral needed to be enabled
* Return:			Std_ReturnType , Type:uint8 --> E_OK =  function done successfully ,, E_NOT_OK = function wasn't excuted right
**/
Std_ReturnType HAL_RCC_Disable_Clk (uint8 Peripheral);

#endif
