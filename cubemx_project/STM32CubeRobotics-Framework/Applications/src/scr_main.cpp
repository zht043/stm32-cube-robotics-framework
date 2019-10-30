#include "scr_main.h"

using namespace scr;


GPIO button(USER_Btn_GPIO_Port, USER_Btn_Pin);
GPIO blue_led(LD2_GPIO_Port, LD2_Pin);
GPIO red_led(LD3_GPIO_Port, LD3_Pin);

void setup(void) {

}

void loop0(void) {
    if(button.read() == High) {
        blue_led.write(High);
    }
    else {
        blue_led.write(Low);
    }
}

void loop1(void) {
    red_led.toggle();
    delay(1000);
}
