/* 
 * File:   Stm32f446xx.h
 * Author: Karim Emad

 *
 * Created on May 12, 2024, 8:50 PM
 */

#ifndef STM32F446XX_H
#define	STM32F446XX_H

#define PERIPHERAL_BASE					0x40000000UL
#define AHB1PERIPHERAL_BASE				(PERIPHERAL_BASE + 0x00020000UL)

/******************************** RCC Registers ********************************/
typedef struct {
	volatile uint32 CR;					/*RCC clock control register (RCC_CR)*/
	volatile uint32 PLLCFGR;			/*RCC PLL configuration register (RCC_PLLCFGR)*/
	volatile uint32 CFGR;				/*RCC clock configuration register (RCC_CFGR)*/
	volatile uint32 CIR;				/*RCC clock interrupt register (RCC_CIR)*/
	volatile uint32 AHB1RSTR;			/*RCC AHB1 peripheral reset register (RCC_AHB1RSTR)*/
	volatile uint32 AHB2RSTR;			/*RCC AHB2 peripheral reset register (RCC_AHB2RSTR)*/
	volatile uint32 AHB3RSTR;			/*RCC AHB3 peripheral reset register (RCC_AHB3RSTR)*/
	volatile uint32 Reserved_1;			/*Reserved*/
	volatile uint32 APB1RSTR;			/*RCC APB1 peripheral reset register (RCC_APB1RSTR)*/
	volatile uint32 APB2RSTR;			/*RCC APB2 peripheral reset register (RCC_APB2RSTR)*/
	volatile uint32 Reserved_2[2];		/*Reserved*/
	volatile uint32 AHB1ENR;			/*RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)*/
	volatile uint32 AHB2ENR;			/*RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)*/
	volatile uint32 AHB3ENR;			/*RCC AHB3 peripheral clock enable register (RCC_AHB3ENR)*/
	volatile uint32 Reserved_3;			/*Reserved*/
	volatile uint32 APB1ENR;			/*RCC APB1 peripheral clock enable register (RCC_APB1ENR)*/
	volatile uint32 APB2ENR;			/*RCC APB2 peripheral clock enable register (RCC_APB2ENR)*/
	volatile uint32 Reserved_4[2];		/*Reserved*/
	volatile uint32 AHB1LPENR;			/*RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR)*/
	volatile uint32 AHB2LPENR;			/*RCC AHB2 peripheral clock enable in low power mode register (RCC_AHB2LPENR)*/
	volatile uint32 AHB3LPENR;			/*RCC AHB3 peripheral clock enable in low power mode register (RCC_AHB3LPENR)*/
	volatile uint32 Reserved_5;			/*Reserved*/
	volatile uint32 APB1LPENR;			/*RCC APB1 peripheral clock enable in low power mode register (RCC_APB1LPENR)*/
	volatile uint32 APB2LPENR;			/*RCC APB2 peripheral clock enable in low power mode register (RCC_APB2LPENR)*/
	volatile uint32 Reserved_6[2];		/*Reserved*/
	volatile uint32 BDCR;				/*RCC Backup domain control register (RCC_BDCR)*/
	volatile uint32 CSR;				/*RCC clock control & status register (RCC_CSR)*/
	volatile uint32 Reserved_7[2];		/*Reserved*/
	volatile uint32 SSCGR;				/*RCC spread spectrum clock generation register (RCC_SSCGR)*/
	volatile uint32 PLLI2SCFGR;			/*RCC PLLI2S configuration register (RCC_PLLI2SCFGR)*/
	volatile uint32 PLLSAICFGR;			/*RCC PLL configuration register (RCC_PLLSAICFGR)*/
	volatile uint32 DCKCFGR;			/*RCC dedicated clock configuration register (RCC_DCKCFGR)*/
	volatile uint32 CKGATENR;			/*RCC clocks gated enable register (CKGATENR)*/
	volatile uint32 DCKCFGR2;			/*RCC dedicated clocks configuration register 2 (DCKCFGR2)*/
}RCC_TypeDef;

#define RCC_BASE						(AHB1PERIPHERAL_BASE + 0x00003800UL)
#define RCC								((RCC_TypeDef *)RCC_BASE)

/******************************** GPIOA/B/C Registers ********************************/
typedef struct{
	volatile uint32 MODER;				/*GPIO port mode register (GPIOx_MODER) (x = A..C)*/
	volatile uint32 OTYPER;				/*GPIO port output type register (GPIOx_OTYPER) (x = A..C)*/				
	volatile uint32 OSPEEDR;			/*GPIO port output speed register (GPIOx_OSPEEDR) (x = A..C)*/
	volatile uint32 PUPDR;				/*GPIO port pull-up/pull-down register (GPIOx_PUPDR) (x = A..C)*/
	volatile uint32 IDR;				/*GPIO port input data register (GPIOx_IDR) (x = A..C)*/
	volatile uint32 ODR;				/*GPIO port output data register (GPIOx_ODR) (x = A..C)*/
	volatile uint32 BSRR;				/*GPIO port bit set/reset register (GPIOx_BSRR) (x = A..C)*/
	volatile uint32 LCKR;				/*GPIO port configuration lock register (GPIOx_LCKR) (x = A..C)*/
	volatile uint32 AFRL;				/*GPIO alternate function low register (GPIOx_AFRL) (x = A..C)*/
	volatile uint32 AFRH;				/*GPIO alternate function high register (GPIOx_AFRH) (x = A..C)*/
}GPIO_TypeDef;

#define GPIOA_BASE						(AHB1PERIPHERAL_BASE + 0x00000000UL)
#define GPIOA							((GPIO_TypeDef *)GPIOA_BASE)

#define GPIOB_BASE						(AHB1PERIPHERAL_BASE + 0x00000400UL)
#define GPIOB							((GPIO_TypeDef *)GPIOB_BASE)
	
#define GPIOC_BASE						(AHB1PERIPHERAL_BASE + 0x00000800UL)
#define GPIOC							((GPIO_TypeDef *)GPIOC_BASE)

/******************************** SysTick Registers ********************************/
typedef struct{
	volatile uint32 CTRL;				/*SysTick control and status register (STK_CTRL)*/
	volatile uint32 LOAD;				/*SysTick reload value register (STK_LOAD)*/				
	volatile uint32 VAL;				/*SysTick current value register (STK_VAL)*/
	volatile uint32 CALIB;				/*SysTick calibration value register (STK_CALIB)*/
}SYSTICK_TypeDef;

#define SYSTICK_BASE					(0xE000E010UL)
#define SYSTICK							((SYSTICK_TypeDef *)SYSTICK_BASE)

#endif	/* STM32F446XX_H */

