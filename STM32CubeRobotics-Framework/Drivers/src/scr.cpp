#include "scr.h"
#include "scr_dependancy.h"
#include <iostream>


//====================================================================//
/* Global overload of new & delete operator
 * let freeRTOS handle memory allocation for better efficiency
 * logging scheme is added to track memory leak
 * */

// Ignore the error squiggles

void* operator new(size_t size)
{
    void *p = pvPortMalloc(size);

	return p;
}

void* operator new[](size_t size)
{
    void *p = pvPortMalloc(size);

	return p;
}

void operator delete(void * ptr)
{
    vPortFree(ptr);
}

void operator delete[](void * ptr)
{
    vPortFree(ptr);
}


//====================================================================//
