#ifndef __SCR_USART_H
#define __SCR_USART_H 


#include "scr_dependancy.h"

#define USART_Default_TxTimeOut 1000000; // 1 second 
#define USART_Default_RxTimeOut 1000000000; // 1000 seconds


#define USART_Default_BufferSize 30
#define Max_Num_USARTs 10 



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

        void hal_transmit(char* str_ptr, periph_mode mode);

    public:
        USART(UART_HandleTypeDef *huartx, uint32_t tx_buffer_size = USART_Default_BufferSize, 
                                          uint32_t rx_buffer_size = USART_Default_BufferSize);
        ~USART();


        void transmit(std::string& str, periph_mode mode = Polling);
        void transmit(char* str_ptr, periph_mode mode = Polling);
        void transmit(byte_t byte, periph_mode mode = Polling);

        char* receive(uint16_t size, periph_mode mode = Polling);

        UART_HandleTypeDef *get_huartx(void) {
            return huartx;
        }

        inline void set_tx_timeout(uint32_t t) {
            tx_timeout = t;
        }

        inline void set_rx_timeout(uint32_t t) {
            rx_timeout = t;
        }

        inline periph_status get_tx_status() {
            return tx_status;
        }

        inline periph_status get_rx_status() {
            return rx_status;
        }

        inline void set_tx_status(periph_status status) {
            tx_status = status;
        }
        
        inline void set_rx_status(periph_status status) {
            rx_status = status;
        }
    };
}


__weak void USART_TxCplt_IT_Task(scr::USART* instance);
extern "C" void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);



#endif 
