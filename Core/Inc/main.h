/*
 * main.h
 *
 *  Created on: Jul 11, 2025
 *      Author: sonic
 */

#ifndef INC_MAIN_H_
#define INC_MAIN_H_

#include "stm32h7xx_hal.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define oneMHz 1000000


void System_Start(void);
void UART1_Init(void);
void Clock_Init(void);
void Osc_Init(void);
void Clk_Init(void);
void System_Clock_Config(void);
void Error_Handler(void);
void SysTick_Handler(void);


uint8_t Convert_to_capital(uint8_t data);

#endif /* INC_MAIN_H_ */
