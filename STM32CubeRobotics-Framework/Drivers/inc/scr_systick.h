#ifndef __SCR_SYSTICK_H
#define __SCR_SYSTICK_H

#include "scr_dependancy.h"


namespace scr {
    uint32_t millis(void);
    uint32_t micros(void);
    void delay_us(uint32_t microseconds); 
    void delay(uint32_t milliseconds, delay_mode mode = RTOS);
}

#endif // !__SCR_SYSTICK_H
