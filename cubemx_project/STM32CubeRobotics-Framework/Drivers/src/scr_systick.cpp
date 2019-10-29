#include "scr_systick.h"


static uint32_t SysTime_T0 = 0;

uint32_t millis(void) {
	return HAL_GetTick() - SysTime_T0;
}
uint32_t micros(void) {
	//the second 1000 here corresponds to the default 1ms interrupt for teh Systick timer
	return HAL_GetTick()*1000 + 1000 - (SysTick->VAL)/(HAL_RCC_GetHCLKFreq() / 1000000);
}

void delay_us(uint32_t Time) {
	uint32_t T_init = micros();
	while(micros() - T_init < Time);
}
void delay(uint32_t Time) {
	uint32_t T_init = millis();
	while(millis() - T_init < Time);
}
