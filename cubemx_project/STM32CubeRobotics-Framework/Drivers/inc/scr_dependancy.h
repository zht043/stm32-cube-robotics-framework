#ifndef __SCR_DEPENDANCY_H
#define __SCR_DEPENDANCY_H


/*========================================================================*/
#define DEVICE_FAMILY_STM32F4
/*========================================================================*/

/*========================================================================*/
    /*C includes*/
extern "C" {

#ifdef DEVICE_FAMILY_STM32F1
    #include "stm32f1xx_hal.h"
#endif

#ifdef DEVICE_FAMILY_STM32F3
    #include "stm32f3xx_hal.h"
#endif

#ifdef DEVICE_FAMILY_STM32F4
    #include "stm32f4xx_hal.h"
#endif

#ifdef DEVICE_FAMILY_STM32F7
    #include "stm32f7xx_hal.h"
#endif

    #include "cmsis_os.h"
}
/*========================================================================*/


/*========================================================================*/
    /*C++ includes*/

#include <iostream>

/*========================================================================*/

namespace scr {
    enum logic_level {High, Low};
    enum periph_status {	
        NotReady,
        Initialized,
        InProgress,
        Completed,
        TimeOut,
        Error
    };
    enum periph_mode {
        Polling,
        Interrupt,
        DMA // direct memory access
    };
}



__weak void throwException(std::string str) {
    UNUSED(str);
}

#endif