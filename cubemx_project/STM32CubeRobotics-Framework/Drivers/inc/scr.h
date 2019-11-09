#ifndef __SCR_H
#define __SCR_H

#include "scr_gpio.h"
#include "scr_systick.h"
#include "scr_usart.h"


//====================================================================//
/*For C and C++ mix programming*/
extern "C" {
	#include "main.h"
	
}
//====================================================================//


void* operator new(size_t size);
void* operator new[](size_t size);
void operator delete(void * ptr);
void operator delete[](void * ptr);

namespace scr {
	extern int new_cnt;
}

#endif
