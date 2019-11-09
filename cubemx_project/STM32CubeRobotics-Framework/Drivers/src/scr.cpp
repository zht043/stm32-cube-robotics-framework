#include "scr.h"
#include "scr_dependancy.h"
#include <iostream>


//====================================================================//
/* Global overload of new & delete operator
 * let freeRTOS handle memory allocation for better efficiency
 * logging scheme is added to track memory leak
 * */

// Ignore the error squiggles

namespace scr {
    int new_cnt = 0;
}

void* operator new(size_t size)
{
    void *p = pvPortMalloc(size);
    scr::new_cnt++;
	return p;
}

void* operator new[](size_t size)
{
    void *p = pvPortMalloc(size);
    scr::new_cnt++;
	return p;
}

void operator delete(void *ptr)
{
    vPortFree(ptr);
    scr::new_cnt--;
}

void operator delete[](void *ptr)
{
    vPortFree(ptr);
    scr::new_cnt--;
}


//====================================================================//
