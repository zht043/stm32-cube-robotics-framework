################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../STM32CubeRobotics-Framework/Drivers/src/scr.cpp \
../STM32CubeRobotics-Framework/Drivers/src/scr_gpio.cpp \
../STM32CubeRobotics-Framework/Drivers/src/scr_systick.cpp \
../STM32CubeRobotics-Framework/Drivers/src/scr_usart.cpp 

OBJS += \
./STM32CubeRobotics-Framework/Drivers/src/scr.o \
./STM32CubeRobotics-Framework/Drivers/src/scr_gpio.o \
./STM32CubeRobotics-Framework/Drivers/src/scr_systick.o \
./STM32CubeRobotics-Framework/Drivers/src/scr_usart.o 

CPP_DEPS += \
./STM32CubeRobotics-Framework/Drivers/src/scr.d \
./STM32CubeRobotics-Framework/Drivers/src/scr_gpio.d \
./STM32CubeRobotics-Framework/Drivers/src/scr_systick.d \
./STM32CubeRobotics-Framework/Drivers/src/scr_usart.d 


# Each subdirectory must supply rules for building sources it contributes
STM32CubeRobotics-Framework/Drivers/src/scr.o: ../STM32CubeRobotics-Framework/Drivers/src/scr.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/zhang/Documents/GitHub/stm32-cube-robotics-framework/cubemx_project/STM32CubeRobotics-Framework/Drivers/inc" -I"C:/Users/zhang/Documents/GitHub/stm32-cube-robotics-framework/cubemx_project/STM32CubeRobotics-Framework/Applications/inc" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"STM32CubeRobotics-Framework/Drivers/src/scr.d" -MT"$@"  -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
STM32CubeRobotics-Framework/Drivers/src/scr_gpio.o: ../STM32CubeRobotics-Framework/Drivers/src/scr_gpio.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/zhang/Documents/GitHub/stm32-cube-robotics-framework/cubemx_project/STM32CubeRobotics-Framework/Drivers/inc" -I"C:/Users/zhang/Documents/GitHub/stm32-cube-robotics-framework/cubemx_project/STM32CubeRobotics-Framework/Applications/inc" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"STM32CubeRobotics-Framework/Drivers/src/scr_gpio.d" -MT"$@"  -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
STM32CubeRobotics-Framework/Drivers/src/scr_systick.o: ../STM32CubeRobotics-Framework/Drivers/src/scr_systick.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/zhang/Documents/GitHub/stm32-cube-robotics-framework/cubemx_project/STM32CubeRobotics-Framework/Drivers/inc" -I"C:/Users/zhang/Documents/GitHub/stm32-cube-robotics-framework/cubemx_project/STM32CubeRobotics-Framework/Applications/inc" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"STM32CubeRobotics-Framework/Drivers/src/scr_systick.d" -MT"$@"  -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
STM32CubeRobotics-Framework/Drivers/src/scr_usart.o: ../STM32CubeRobotics-Framework/Drivers/src/scr_usart.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DUSE_HAL_DRIVER -DSTM32F446xx -DDEBUG -c -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/zhang/Documents/GitHub/stm32-cube-robotics-framework/cubemx_project/STM32CubeRobotics-Framework/Drivers/inc" -I"C:/Users/zhang/Documents/GitHub/stm32-cube-robotics-framework/cubemx_project/STM32CubeRobotics-Framework/Applications/inc" -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"STM32CubeRobotics-Framework/Drivers/src/scr_usart.d" -MT"$@"  -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

