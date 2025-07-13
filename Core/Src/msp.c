#include "main.h"

void HAL_MspInit(void)
{
	//1. Setup the priority grouping of the M7 Cortex

	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	//2.Enable the required system exceptions

	SCB->SHCSR |= 0x7 << 16;

	//3. Configure the priority for the system Application

	HAL_NVIC_SetPriority( MemoryManagement_IRQn,0, 0);
	HAL_NVIC_SetPriority( BusFault_IRQn,0, 0);
	HAL_NVIC_SetPriority( UsageFault_IRQn,0, 0);

}

 void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	 GPIO_InitTypeDef GPIO_UART = {0};
	 //Low level initialization of the USART1

	 //1. Enable the clock for the peripheral
	 __HAL_RCC_USART1_CLK_ENABLE();
	 __HAL_RCC_GPIOA_CLK_ENABLE();
	 //2. Do pin muxing configuration
	 GPIO_UART.Pin = GPIO_PIN_9; //PA9 -> TX
	 GPIO_UART.Mode = GPIO_MODE_AF_PP;
	 GPIO_UART.Pull = GPIO_PULLUP;
	 GPIO_UART.Speed = GPIO_SPEED_FREQ_LOW;
	 GPIO_UART.Alternate = GPIO_AF7_USART1;
	 HAL_GPIO_Init(GPIOA, &GPIO_UART);

	 GPIO_UART.Pin = GPIO_PIN_10;
	 HAL_GPIO_Init(GPIOA, &GPIO_UART);

	 //3. Enable the IRQ and set up the priority (NVIC Settings)
	 HAL_NVIC_EnableIRQ(USART1_IRQn);
	 HAL_NVIC_SetPriority(USART1_IRQn, 15, 0);

}
