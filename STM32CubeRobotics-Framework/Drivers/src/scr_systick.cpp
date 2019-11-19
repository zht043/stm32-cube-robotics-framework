#include "scr_systick.h"


static uint32_t SysTime_T0 = 0;

uint32_t scr::millis(void) {
	return HAL_GetTick() - SysTime_T0;
}
uint32_t scr::micros(void) {
	//the second 1000 here corresponds to the default 1ms interrupt for teh Systick timer
	return HAL_GetTick()*1000 + 1000 - (SysTick->VAL)/(HAL_RCC_GetHCLKFreq() / 1000000);
}


/* regular microsecond HAL-style delay*/
void scr::delay_us(uint32_t Time) {
	uint32_t T_init = scr::micros();
	while(scr::micros() - T_init < Time);
}

/* milliseconds delay that supports osDelay 
 * which notify RTOS scheduler when a task
 * is at idle time, which allow mutitask with
 * tasks of lower priority
 * */
void scr::delay(uint32_t Time, delay_mode mode) {
	if(mode == HAL) {
		uint32_t T_init = scr::millis();
		while(scr::millis() - T_init < Time);
	}
	if(mode == RTOS) {
		osDelay(Time);
	}
}


