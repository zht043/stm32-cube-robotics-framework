#ifndef __SCR_I2C_H
#define __SCR_I2C_H 

/*

#include "scr_dependancy.h"


//#ifdef HAL_I2C_MODULE_ENABLED

#define I2C_Default_TxTimeOut 60000 // 1 second 
#define I2C_Default_RxTimeOut 60000 // 1 second


#define I2C_Default_Tx_BufferSize 3
#define I2C_Default_Rx_BufferSize 50
#define Max_Num_I2Cs 10 



namespace scr {
    class I2C {
    private:
        I2C_HandleTypeDef *hi2cx;

        // time-out default
        uint32_t tx_timeout = I2C_Default_TxTimeOut;
        uint32_t rx_timeout = I2C_Default_RxTimeOut;

        volatile periph_status tx_status = NotReady;
        volatile periph_status rx_status = NotReady;

        char *tx_buffer;
        char *rx_buffer;

        void hal_transmit(char* str_ptr, periph_mode mode);
        void hal_receive(char* str_ptr, uint16_t num_bytes, periph_mode mode);

    public:

        // Constructors & Destructors
        I2C(UART_HandleTypeDef *huartx, uint32_t tx_buffer_size = I2C_Default_Tx_BufferSize, 
                                          uint32_t rx_buffer_size = I2C_Default_Rx_BufferSize);
        ~I2C();

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
                                                  /*
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
scr::I2C& operator<<(scr::I2C& obj, const T& output) {
    std::stringstream newStream;
    newStream << output;
    std::string str = newStream.str();
    obj.transmit(str, scr::Polling);
    return obj;
}

// Callbacks
__weak void i2c_transmit_completed_interrupt_task(scr::I2C* instance);
extern "C" void HAL_i2c_TxCpltCallback(UART_HandleTypeDef *huart);

extern "C" void HAL_i2c_RxCpltCallback(UART_HandleTypeDef *huart);
__weak void i2c_receive_completed_interrupt_task(scr::I2C* instance);




//#endif
*/
#endif 
