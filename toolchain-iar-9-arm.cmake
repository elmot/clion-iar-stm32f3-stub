set(IAR_TOOLCHAIN_ROOT "C:/Program Files/IAR Systems/Embedded Workbench 9.0/arm")

find_program(CMAKE_C_COMPILER iccarm HINTS "${IAR_TOOLCHAIN_ROOT}/bin")
find_program(CMAKE_CXX_COMPILER iccarm HINTS "${IAR_TOOLCHAIN_ROOT}/bin")
find_program(CMAKE_ASM_COMPILER iasmarm HINTS "${IAR_TOOLCHAIN_ROOT}/bin")