#include "scr_main.h"

#include <iostream>
#include <vector>
using namespace std;

GPIO button;
GPIO blue_led;
GPIO red_led;

void setup(void) {
    button = GPIO(USER_Btn_GPIO_Port, USER_Btn_Pin);
    blue_led = GPIO(LD2_GPIO_Port, LD2_Pin);
    red_led = GPIO(LD3_GPIO_Port, LD3_Pin);
}

void loop0(void) {
    vector<int> *vec = new vector<int>(10);

    while(1) {
        if(button.gpioRead() == Low) {
            blue_led.gpioWrite(High);
        }
        else {
            blue_led.gpioWrite(Low);
        }
    }
}

void loop1(void) {

}