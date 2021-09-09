cmake_minimum_required(VERSION 3.20)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

function(add_assembly_source EXECUTABLE FILE_NAME)
    string(REPLACE / _ OUT_FILE "${FILE_NAME}")
    set(OUT_FILE "${CMAKE_CURRENT_BINARY_DIR}/${OUT_FILE}.o")
    get_filename_component(_ASM_COMPILER_DIR ${CMAKE_C_COMPILER} DIRECTORY)
    set(_ASM_COMPILER ${_ASM_COMPILER_DIR}/iasmarm)

    add_custom_command(OUTPUT ${OUT_FILE}
            COMMAND ${_ASM_COMPILER} ${CMAKE_SOURCE_DIR}/${FILE_NAME} -s+ -w+ -r --cpu ${TARGET_MCU_CORE} -o ${OUT_FILE}
            DEPENDS ${CMAKE_SOURCE_DIR}/${FILE_NAME}
            COMMENT "Building ASM object ${FILE_NAME}"
            )
    target_sources(${EXECUTABLE} PRIVATE ${OUT_FILE})

endfunction()

project(clion-iar-stm32f3-stub C CXX)

set(CMAKE_C_STANDARD 11)

set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/EWARM/stm32f303xc_flash.icf")

set(TARGET_MCU_CORE Cortex-M4F)

add_compile_options(--cpu ${TARGET_MCU_CORE} --dlib_config=normal)

add_link_options(--semihosting --config "${LINKER_SCRIPT}")

file(GLOB_RECURSE SOURCES "Core/*.*"  "Drivers/*.*")

include_directories(Core/Inc
        Drivers/CMSIS/Include
        Drivers/CMSIS/Device/ST/STM32F3xx/Include
        Drivers/STM32F3xx_HAL_Driver/Inc
        Drivers/STM32F3xx_HAL_Driver/Inc/Legacy)

add_definitions(-DUSE_HAL_DRIVER -DSTM32F303xC -DDEBUG)

add_executable(clion_iar_stm32f3_stub ${SOURCES} ${LINKER_SCRIPT})

add_assembly_source(clion_iar_stm32f3_stub Core/Src/arm_bitreversal2.S)
add_assembly_source(clion_iar_stm32f3_stub EWARM/startup_stm32f303xc.s)