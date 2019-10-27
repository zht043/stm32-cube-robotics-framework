#ifndef __SCR_MAIN_H
#define __SCR_MAIN_H

#include "scr.h"

//====================================================================//
/*For C and C++ mix programming*/
extern "C" {
	#include "main.h"
	
}
//====================================================================//


//====================================================================//
/*Callback functions called by different thread task func in main.c*/ 
//omit "_callback" postfix to make it less intimidating

// equivalent to task0 if multitasking
extern "C" __weak void scr_main(void); 

// user may modify it to accept params if needed, 
extern "C" __weak void scr_task1(void);

/* For task2 ... task 3...  configure their settings in cubemx GUI 
 * and generate new code, 
 * then call the scr_task# func in the loop of startTask0#  
 */
//====================================================================//






#endif
