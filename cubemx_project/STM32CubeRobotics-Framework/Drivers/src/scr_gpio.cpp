#include "scr_gpio.h"


void GPIO::gpioWrite(logic_level Bit) {
    if(Bit == High) HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
}
logic_level GPIO::gpioRead(void) {
    return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == GPIO_PIN_SET ? High : Low;
}
