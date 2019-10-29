#ifndef __SCR_GPIO_H
#define __SCR_GPIO_H 


#include "scr_dependancy.h"

class GPIO {
private:
    GPIO_TypeDef *GPIOx;
    uint16_t GPIO_Pin;



public:
    GPIO(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin): GPIOx(GPIOx), GPIO_Pin(GPIO_Pin) {}
    ~GPIO() {}

    void gpioWrite(logic_level Bit);
    logic_level gpioRead(void);

};




#endif 
