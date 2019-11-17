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



void setup(void) {

}

void loop0(void) {
   /* if(button.read() == High) {
        blue_led.write(High);
    }
    else {
        blue_led.write(Low);
    }
    */

   while (true) {
       delay(500);
       blue_led.write(High);
       red_led.write(Low);
       delay(300);
       blue_led.write(Low);
       red_led.write(High);
   }
}



void loop1(void) {


    //string input;
    //input = serial.receive(3);
    //byte_t in_byte = serial.receive();

/*
	char str[10];
	serial.receive(str, 3, Interrupt);
	while(serial.get_rx_status() != Completed);
    serial << str << scr::endl;
*/

    string line = serial.readLine();
    serial << line << scr::endl;



/*
	vector<int> vec;
	vector<int> *vec2 = new vector<int>;


    stringstream ostr;
    ostr << "Hello" << ' ' << "World" << 123 <<endl;

    string hw = ostr.str();
    serial.transmit(hw, Interrupt);
    while(serial.get_tx_status() != Completed);


    std::string newline = "\n\r";
    std::string space = " ";
    serial.transmit(newline);

    
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
	}
    */
}
