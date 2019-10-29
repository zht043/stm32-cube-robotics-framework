# GPIO & multitasking

### APIs

```c++
GPIO(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
~GPIO();
void write(logic_level level);
logic_level read(void);
void toggle(void);
```



### LED multitasking

**CubeMx Config:**

* Set task2 priority to be the same as DefaultTask 

**scr_main.cpp**

```c++
#include "scr_main.h"

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
    delay(100);
}

```

**Output**

* Red led constantly blinks at 100ms period
* Blue led turn on when user(blue) button is pushed, and it's off otherwise. 