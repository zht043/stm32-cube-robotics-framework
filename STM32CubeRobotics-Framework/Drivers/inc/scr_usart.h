#ifndef __SCR_USART_H
#define __SCR_USART_H 


#include "scr_dependancy.h"


#ifdef HAL_UART_MODULE_ENABLED

#define USART_Default_TxTimeOut 60000 // 1 second 
#define USART_Default_RxTimeOut 60000 // 1 second


#define USART_Default_Tx_BufferSize 3
#define USART_Default_Rx_BufferSize 50
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
        void hal_receive(char* str_ptr, uint16_t num_bytes, periph_mode mode);

    public:

        // Constructors & Destructors
        USART(UART_HandleTypeDef *huartx, uint32_t tx_buffer_size = USART_Default_Tx_BufferSize, 
                                          uint32_t rx_buffer_size = USART_Default_Rx_BufferSize);
        ~USART();

        // Transmit & Receive
        void transmit(std::string& str, periph_mode mode = Polling);
        void transmit(char* str_ptr, periph_mode mode = Polling);
        void transmit(byte_t byte, periph_mode mode = Polling);
        std::string receive(uint16_t num_bytes); /* only support Polling mode if the return type is a string, 
                                                   * this is due to c++ string constructor only does deep copy 
                                                   * instead of shallow copy, can't copy a char array (rx_buffer) right away
                                                   * when non-blocking receive is still in the middle of filling
                                                   * content into the array
                                                   * (non-blocking methods are {Interrupt, DMA})
                                                   */
        void receive(char* buffer_ptr, uint16_t num_bytes, periph_mode mode = Polling);
        byte_t receive(void); //only support Polling mode too, no need to use non-blocking methods for just one byte
        const std::string readWord(void);
        const std::string readLine(void);

        // Getters & Setters
        inline UART_HandleTypeDef *get_huartx(void) {  return huartx; }
        inline void set_tx_timeout(uint32_t t) { tx_timeout = t; }
        inline void set_rx_timeout(uint32_t t) { rx_timeout = t;}
        inline periph_status get_tx_status() { return tx_status; }
        inline periph_status get_rx_status() { return rx_status; }
        inline void set_tx_status(periph_status status) { tx_status = status; }
        inline void set_rx_status(periph_status status) { rx_status = status; } 
        inline char* get_tx_buffer_ptr(void) {return tx_buffer;}                                                                                         
        inline char* get_rx_buffer_ptr(void) {return rx_buffer;}

    };
}

// Operators
template<typename T>
scr::USART& operator<<(scr::USART& obj, const T& output) {
    std::stringstream newStream;
    newStream << output;
    std::string str = newStream.str();
    obj.transmit(str, scr::Polling);
    return obj;
}

// Callbacks
__weak void usart_transmit_completed_interrupt_task(scr::USART* instance);
extern "C" void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);

extern "C" void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
__weak void usart_receive_completed_interrupt_task(scr::USART* instance);




#endif

#endif 
