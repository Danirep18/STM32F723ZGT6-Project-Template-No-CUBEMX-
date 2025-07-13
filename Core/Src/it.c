/*it.c
 *@brief: In this section all the interruptions will be placed
*/
#include "main.h"

void SysTick_Handler(void){
	 HAL_IncTick();
	 HAL_SYSTICK_IRQHandler();
}

