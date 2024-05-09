# Nucleof446re Drivers

This repository contains a collection of drivers for the Nucleo-F446RE development board, written to facilitate peripheral interaction and functionality. Each driver is designed to provide an interface for a specific peripheral or functionality.

## 1. RCC Driver

The RCC (Reset and Clock Control) driver is responsible for configuring the system clock, enabling/disabling peripheral clocks, and resetting peripherals. This driver is essential for initializing the microcontroller and configuring its operating parameters.

### Features

- System clock configuration
- Peripheral clock enable/disable
- Peripheral reset

### Usage

To use the RCC driver in your project:

1. Clone or download this repository.
2. Include the RCC driver source files in your project.
3. Include the header files in your source files where RCC functionality is required.
4. Initialize the RCC module using the provided initialization function.
5. Configure the system and peripheral clocks as needed using the available functions.

### Example

```c
#include <stdint.h>
#include "Bit_Math.h"
#include "Std_Types.h"
#include "RCC_Interface.h"

RCC_config_t rcc = { .System_Clock = PLL_SYS_CLK, .PLL_Source = PLL_HSI_CLK , .PLLM = 4 , .PLLN = 50 , .PLLP = 4 ,
                     .AHB_Prescaler = RCC_AHB_PRESCALER_DIV_2, .APB1_Prescaler = RCC_APB1_PRESCALER_DIV_16, .APB2_Prescaler = RCC_APB2_PRESCALER_DIV_16};

int main(void)
{
    Std_ReturnType RET = E_OK;
    RET = HAL_RCC_Clk_Config(&rcc);
    RET = HAL_RCC_Enable_Clk(OTGHSULPI_PERIPHERAL);
    RET = HAL_RCC_Enable_Clk(DCMI_PERIPHERAL);
    RET = HAL_RCC_Enable_Clk(QUADSPI_PERIPHERAL);
    RET = HAL_RCC_Enable_Clk(USART3_PERIPHERAL);
    RET = HAL_RCC_Enable_Clk(USART6_PERIPHERAL);
    return 0;
}
