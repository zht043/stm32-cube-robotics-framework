#ifndef __SCR_USART_H
#define __SCR_USART_H 


#include "scr_dependancy.h"

//#define USART_Default_TxTimeOut 1000000; // 1 second 
//#define USART_Default_RxTimeOut 1000000000; // 1000 seconds


#define USART_Default_TxTimeOut 0xFFFF; // 1 second 
#define USART_Default_RxTimeOut 0xFFFFFFFF; // 1000 seconds



#define USART_Default_BufferSize 30

namespace scr {
    class USART {
    private:
        UART_HandleTypeDef *huartx;

        // time-out default
        uint32_t tx_timeout = USART_Default_TxTimeOut;
        uint32_t rx_timeout = USART_Default_RxTimeOut;

        volatile periph_status tx_status = NotReady;
        volatile periph_status rx_status = NotReady;

        char *tx_buffer;
        char *rx_buffer;
         

    public:
        USART(UART_HandleTypeDef *huartx, uint32_t tx_buffer_size = USART_Default_BufferSize, 
                                          uint32_t rx_buffer_size = USART_Default_BufferSize);
        ~USART();


        void writeByte(uint8_t byte, periph_mode mode);
        uint8_t readByte(uint8_t byte, periph_mode mode);


        void write_tx_buffer(std::string str);
        void write_tx_buffer(char *str);

        std::string read_rx_string(void);
        char* read_rx_buffer(void);
        

        void transmit(periph_mode mode = Polling);
        void receive(uint16_t size, periph_mode mode = Polling);

        void print(std::string str);
        void println(std::string str);

        UART_HandleTypeDef *get_huartx(void) {
            return huartx;
        }

        void set_tx_timeout(uint32_t t) {
            tx_timeout = t;
        }

        void set_rx_timeout(uint32_t t) {
            rx_timeout = t;
        }

        periph_status get_tx_status() {
            return tx_status;
        }

        periph_status get_rx_status() {
            return rx_status;
        }
    };
}




#endif 
