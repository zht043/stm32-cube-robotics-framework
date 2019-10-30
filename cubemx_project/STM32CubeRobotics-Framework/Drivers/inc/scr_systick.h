#ifndef __SCR_SYSTICK_H
#define __SCR_SYSTICK_H

#include "scr_dependancy.h"


namespace scr {
    uint32_t millis(void);
    uint32_t micros(void);
    void delay_us(uint32_t Time); 
    void delay(uint32_t Time);
}

#endif // !__SCR_SYSTICK_H
