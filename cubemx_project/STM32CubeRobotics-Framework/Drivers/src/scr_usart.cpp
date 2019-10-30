#include "scr_usart.h"
#include "scr_systick.h"
#include <cstring>
#include <vector>

using namespace scr;

static std::vector<USART*> active_usarts;



USART::USART(UART_HandleTypeDef *huartx, uint32_t tx_buffer_size, uint32_t rx_buffer_size) {
    this->huartx = huartx;
    tx_buffer = new char(tx_buffer_size);
    rx_buffer = new char(rx_buffer_size);
    tx_status = Initialized;
    rx_status = Initialized;
    active_usarts.push_back(this);
}

USART::~USART() {
    delete tx_buffer;
    delete rx_buffer;
}


void USART::writeByte(uint8_t byte, periph_mode mode) {


}
uint8_t USART::readByte(uint8_t byte, periph_mode mode) {

}


void USART::write_tx_buffer(std::string str) {
    
}

void USART::write_tx_buffer(char *str) {
    tx_buffer = str;
}

std::string USART::read_rx_string(void) {

}
char* read_rx_buffer(void) {

}


void USART::transmit(periph_mode mode) {
    HAL_StatusTypeDef status;
    if(mode == Polling) {

        status = HAL_UART_Transmit(huartx, (uint8_t*)(tx_buffer), strlen(tx_buffer), tx_timeout);
        if(status == HAL_BUSY) tx_status = InProgress;
        else if(status == HAL_TIMEOUT) {
            tx_status = TimeOut;

            //Unlock Usart
            __HAL_UNLOCK(huartx);
            huartx->gState = HAL_UART_STATE_READY;
            
            throwException("THL_Usart.c: usartWrite() | TimeOut");
        }
        else if(status == HAL_ERROR) {
            tx_status = Error;
            throwException("THL_Usart.c: usartWrite() | Error");
        }
        else if(status == HAL_OK) {
            tx_status = Completed;
        }
    }
}

void USART::receive(uint16_t size, periph_mode mode) {

}


void USART::print(std::string str) {
    //this->write(str);
}

void USART::println(std::string str) {
    //this->write(str);
    //this->write("\n");
}
