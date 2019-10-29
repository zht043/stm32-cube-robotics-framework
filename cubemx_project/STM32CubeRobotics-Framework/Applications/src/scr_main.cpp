#include "scr_main.h"

#include <iostream>
#include <vector>
using namespace std;

GPIO button(USER_Btn_GPIO_Port, USER_Btn_Pin);
GPIO blue_led(LD2_GPIO_Port, LD2_Pin);
GPIO red_led(LD3_GPIO_Port, LD3_Pin);

void setup(void) {

}

void loop0(void) {
    //vector<int> *vec = new vector<int>(10);

    while(1) {
        if(button.gpioRead() == High) {
            blue_led.gpioWrite(High);
        }
        else {
            blue_led.gpioWrite(Low);
        }
    }
}

void loop1(void) {

}
