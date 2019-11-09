#include "scr_main.h"

#include <iostream>
#include <vector>
#include <sstream>


using namespace scr;
using namespace std;

GPIO button(USER_Btn_GPIO_Port, USER_Btn_Pin);
GPIO blue_led(LD2_GPIO_Port, LD2_Pin);
GPIO red_led(LD3_GPIO_Port, LD3_Pin);


extern UART_HandleTypeDef huart3;
USART serial(&huart3);



char fuck[6] = "FUCK\n";
void setup(void) {
	HAL_UART_Transmit_DMA(&huart3, (uint8_t*)fuck, 3);
	delay(1000, HAL);
}

void loop0(void) {
	/*

    if(button.read() == High) {
        blue_led.write(High);
    }
    else {
        blue_led.write(Low);
    }*/
	osDelay(1);
}



void loop1(void) {


	vector<int> vec;
	vector<int> *vec2 = new vector<int>;


    stringstream ostr;
    ostr << "Hello" << ' ' << "World" << 123 <<endl;

    string hw = ostr.str();
   /* serial.transmit(hw, Interrupt);
    while(serial.get_tx_status() != Completed);*/

/*
    std::string newline = "\n\r";
    std::string space = " ";
    serial.transmit(newline);
*/


//    serial.transmit(fuck, DMA);

    osDelay(100);

    serial.transmit(hw);

    /*
	for(int i = 0; i < 10; i++) {
        vec.push_back(i);
        vec2->push_back(10 - i);
        ostr.str("");
        for(auto elem : vec) {
        	ostr << to_string(elem) << " ";
        }
        string str = ostr.str();
        serial.transmit(str, DMA);
        while(serial.get_tx_status() != Completed);

        
        for(auto elem : *vec2) {
        	ostr << to_string(elem) << " ";
        }
        str = ostr.str();
        serial.transmit(str, DMA);
        while(serial.get_tx_status() != Completed);

        serial.transmit(newline);
		delay(500);
	}*/
}
