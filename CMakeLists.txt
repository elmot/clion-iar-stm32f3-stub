cmake_minimum_required(VERSION 3.21)
set(CMAKE_SYSTEM_NAME Generic)

project(clion-iar-stm32f3-stub C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/EWARM/stm32f303xc_flash.icf")

set(TARGET_MCU_CORE Cortex-M4F)

#Common compiler flag for both C, C++, and ASM
add_compile_options(--cpu ${TARGET_MCU_CORE})


#Compiler flag for C and C++ only
add_compile_options($<$<COMPILE_LANGUAGE:C,CXX>:--dlib_config=normal>)

#Enable IAR language extensions for C and C++
add_compile_options($<$<COMPILE_LANGUAGE:C,CXX>:-e>)

add_link_options(--semihosting --config "${LINKER_SCRIPT}")

file(GLOB_RECURSE SOURCES "Core/*.*"  "Drivers/*.*")

include_directories(Core/Inc
        Drivers/CMSIS/Include
        Drivers/CMSIS/Device/ST/STM32F3xx/Include
        Drivers/STM32F3xx_HAL_Driver/Inc
        Drivers/STM32F3xx_HAL_Driver/Inc/Legacy)

add_definitions(-DUSE_HAL_DRIVER -DSTM32F303xC -DDEBUG)

add_executable(clion_iar_stm32f3_stub ${SOURCES}
        ${LINKER_SCRIPT}
        Core/Src/arm_bitreversal2.S
        Core/Src/cppmain.cpp
        EWARM/startup_stm32f303xc.s)
