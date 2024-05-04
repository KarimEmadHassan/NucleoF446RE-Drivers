/* 
 * File:   Stm32f446xx.h
 * Author: Karim Emad

 *
 * Created on May 12, 2024, 8:50 PM
 */

#ifndef STM32F446XX_H
#define	STM32F446XX_H

/******************************** RCC Register ********************************/
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

#define PERIPHERAL_BASE			0x40000000UL
#define AHB1PERIPHERAL_BASE		(PERIPHERAL_BASE + 0x00020000UL)
#define RCC_BASE				(AHB1PERIPHERAL_BASE + 0x00003800UL)
#define RCC						((RCC_TypeDef *)RCC_BASE)


#endif	/* STM32F446XX_H */

