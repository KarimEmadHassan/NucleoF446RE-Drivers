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


## 2. GPIO Driver

The GPIO (General Purpose Input/Output) driver provides an interface for configuring and controlling GPIO pins on the Nucleo-F446RE board. GPIO pins can be used for various purposes such as digital input, digital output, or alternate function mode.

### Features

- Pin initialization and configuration
- Digital input and output
- Pin toggle and state read

### Usage

To use the GPIO driver in your project:

1. Clone or download this repository.
2. Include the GPIO driver source files (`gpio.c` and `gpio.h`) in your project.
3. Include the `gpio.h` header file in your source files where GPIO functionality is required.
4. Initialize GPIO pins using the provided initialization functions.
5. Configure pins for input or output mode as needed.
6. Read or write pin states using the provided functions.

