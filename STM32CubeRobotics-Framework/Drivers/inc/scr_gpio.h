#ifndef __SCR_GPIO_H
#define __SCR_GPIO_H 


#include "scr_dependancy.h"

namespace scr {
    class GPIO {
    private:
        GPIO_TypeDef *GPIOx;
        uint16_t GPIO_Pin;
        logic_level curr_level = Low;



    public:
        GPIO(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
            this->GPIOx = GPIOx;
            this->GPIO_Pin = GPIO_Pin;
        }
        ~GPIO() {}

        void write(logic_level level);
        logic_level read(void);
        void toggle(void);

    };
}




#endif 
