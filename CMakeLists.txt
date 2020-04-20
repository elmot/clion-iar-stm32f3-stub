cmake_minimum_required(VERSION 3.16)
set(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_VERSION 1)

project(clion-iar-stm32f3-stub C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

set(COMMON_COMPILER_FLAGS "--cpu Cortex-M4F --dlib_config=normal")

set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/EWARM/stm32f303xc_flash.icf")

set(COMMON_LINKER_FLAGS "--semihosting --config \"${LINKER_SCRIPT}\"")


set(CMAKE_C_FLAGS "${COMMON_COMPILER_FLAGS}")
set(CMAKE_CXX_FLAGS "${COMMON_COMPILER_FLAGS}")

set(CMAKE_C_LINK_FLAGS "${COMMON_LINKER_FLAGS}")
set(CMAKE_CXX_LINK_FLAGS "${COMMON_LINKER_FLAGS}")

file(GLOB_RECURSE SOURCES "Core/*.*"  "Drivers/*.*" EWARM/startup_stm32f303xc.s)

include_directories(Core/Inc
        Drivers/CMSIS/Include
        Drivers/CMSIS/Device/ST/STM32F3xx/Include
        Drivers/STM32F3xx_HAL_Driver/Inc
        Drivers/STM32F3xx_HAL_Driver/Inc/Legacy)

add_definitions(-DUSE_HAL_DRIVER -DSTM32F303xC -DDEBUG)

add_executable(clion_iar_stm32f3_stub ${SOURCES} ${LINKER_SCRIPT})