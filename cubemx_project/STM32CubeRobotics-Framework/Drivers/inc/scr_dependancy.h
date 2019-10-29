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


enum logic_level {High, Low};


#endif