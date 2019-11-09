#include "scr_usart.h"
#include "scr_systick.h"

using namespace scr;

/*==================================================================*/
/* active_usarts store pointers to all instantiated USART objects
 * globally, for ISR(interrupt service routine) extern functions to assign 
 * interrupt task for each different usart object. Ideally a hashtable or 
 * vector container should be implemented instead of a pointer array with 
 * a magic number of capacity, but ISR only support simple C-style 
 * operations, let's stick with the old-school fashion!
 * */
uint32_t num_usarts = 0;
USART* active_usarts[Max_Num_USARTs];
/*==================================================================*/


USART::USART(UART_HandleTypeDef *huartx, uint32_t tx_buffer_size, uint32_t rx_buffer_size) {
    this->huartx = huartx;

    tx_buffer = new char(tx_buffer_size);
    rx_buffer = new char(rx_buffer_size);

    tx_status = Initialized;
    rx_status = Initialized;
    active_usarts[num_usarts++] = this;
}

USART::~USART() {
    delete tx_buffer;
    delete rx_buffer;
}



void USART::hal_transmit(char* str_ptr, periph_mode mode) {
	if(tx_status == NotReady) return;

    HAL_StatusTypeDef status;
    if(mode == Polling) {
        status = HAL_UART_Transmit(huartx, (uint8_t*)(str_ptr), strlen(str_ptr), tx_timeout);
        if(status == HAL_BUSY) tx_status = InProgress;
        else if(status == HAL_TIMEOUT) {
            tx_status = TimeOut;

            //Unlock Usart
            __HAL_UNLOCK(huartx);
            huartx->gState = HAL_UART_STATE_READY;
            
            throwException("usart_transmit Polling | TimeOut");
        }
        else if(status == HAL_ERROR) {
            tx_status = Error;
            throwException("usart_transmit Polling | Error");
        }
        else if(status == HAL_OK) {
            tx_status = Completed;
        }
    }

    // Make sure interrupt is enabled within CubeMx software
    if(mode == Interrupt) {
        //check if the previous transmission is completed
        if(tx_status == InProgress) return;
        status = HAL_UART_Transmit_IT(huartx, (uint8_t*)str_ptr, strlen(str_ptr));
        if(status == HAL_ERROR) {
            tx_status = Error;
            throwException("usart_transmit interrupt | Error");
            return;
        }
        tx_status = InProgress;
    }

    // Make sure DMA and interrupt are both enabled within CubeMx software
    if(mode == DMA) {
        //check if the previous transmission is completed
        if(tx_status == InProgress) return;
        status = HAL_UART_Transmit_DMA(huartx, (uint8_t*)str_ptr, strlen(str_ptr));
        if(status == HAL_ERROR) {
            tx_status = Error;
            throwException("usart_transmit DMA | Error");
            return;
        }
        tx_status = InProgress;
    }
}


/* */
void USART::transmit(std::string& str, periph_mode mode) {
	hal_transmit((char*)str.c_str(), mode);
}


void USART::transmit(char* str_ptr, periph_mode mode) {
    hal_transmit(str_ptr, mode);
}

void USART::transmit(byte_t byte, periph_mode mode) {
    tx_buffer[0] = (char)byte;
    tx_buffer[1] = '\0';
    hal_transmit(tx_buffer, mode);
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {    
	for(uint32_t i = 0; i < num_usarts; i++) {
		if(active_usarts[i]->get_huartx() == huart) {
            //usart_transmit_completed_interrupt_task(active_usarts[i]);
            active_usarts[i]->set_tx_status(Completed);
		}
	}
}



__weak void USART_TxCplt_IT_Task(USART* instance) {
    UNUSED(instance);
}
