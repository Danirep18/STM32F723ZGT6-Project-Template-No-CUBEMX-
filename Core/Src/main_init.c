/* main_init.c */
#include "main.h"

extern UART_HandleTypeDef huart1;
extern RCC_OscInitTypeDef Osc;
extern RCC_ClkInitTypeDef Clk;

char msg[100];
#define oneMHz 1000000

void SystemClock_Config(void);
void Print_Clock_Config(void);

void System_Start(void){
    HAL_Init();
    Osc_Init();
    Clk_Init();
    UART1_Init();
}

void UART1_Init(void){
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;

    if(HAL_UART_Init(&huart1) != HAL_OK){
        Error_Handler();
    }
}

void Osc_Init(void){
	memset(&Osc, 0, sizeof(Osc));
	Osc.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	Osc.HSEState = RCC_HSE_ON;
	Osc.PLL.PLLState = RCC_PLL_ON;
	Osc.PLL.PLLSource = RCC_PLLSOURCE_HSE;

	Osc.PLL.PLLM = 5;
	Osc.PLL.PLLN = 160;
	Osc.PLL.PLLP = 2;
	Osc.PLL.PLLQ = 4;
	Osc.PLL.PLLR = 4;

	Osc.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
	Osc.PLL.PLLFRACN = 0;

	if(HAL_RCC_OscConfig(&Osc) != HAL_OK){
		Error_Handler();
	}
}


void Clk_Init(void){

	Clk.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | \
						RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | \
						RCC_CLOCKTYPE_D1PCLK1 | RCC_CLOCKTYPE_D3PCLK1;
	Clk.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	Clk.SYSCLKDivider = RCC_SYSCLK_DIV1;
	Clk.AHBCLKDivider = RCC_HCLK_DIV2;
	Clk.APB1CLKDivider = RCC_APB1_DIV2;
	Clk.APB2CLKDivider = RCC_APB2_DIV2;
	Clk.APB3CLKDivider = RCC_APB3_DIV2;
	Clk.APB4CLKDivider = RCC_APB4_DIV2;

	if(HAL_RCC_ClockConfig(&Clk, FLASH_LATENCY_DEFAULT) != HAL_OK){
		Error_Handler();
	}

	__HAL_RCC_HSI_DISABLE();

	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

	UART1_Init();

	memset(msg, 0, sizeof(msg));
	sprintf(msg, "-----------------------------------\r\n");
	HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(msg, 0, sizeof(msg));
	sprintf(msg, "Application running (STM32H723ZGT6)\r\n");
	HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(msg, 0, sizeof(msg));
	sprintf(msg, "SYSCLK : %ld MHz\r\n", HAL_RCC_GetSysClockFreq()/oneMHz);
	HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(msg, 0, sizeof(msg));
	sprintf(msg, "HCLK : %ld MHz\r\n", HAL_RCC_GetHCLKFreq()/oneMHz);
	HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(msg, 0, sizeof(msg));
	sprintf(msg, "PLL1 : %ld MHz\r\n", HAL_RCC_GetPCLK1Freq()/oneMHz);
	HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(msg, 0, sizeof(msg));
	sprintf(msg, "D1PCLK1 : %ld MHz\r\n", HAL_RCCEx_GetD1PCLK1Freq()/oneMHz);
	HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(msg, 0, sizeof(msg));
	sprintf(msg, "D3PCLK1 : %ld MHz\r\n", HAL_RCCEx_GetD3PCLK1Freq()/oneMHz);
	HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(msg, 0, sizeof(msg));
	sprintf(msg, "main.c in execution in next line\r\n");
	HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	memset(msg, 0, sizeof(msg));
	sprintf(msg, "-----------------------------------\r\n");
	HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
}





