
# Preface

We use STM32CubeMX because it’s very easy to use.   \
If it’s not used(i.e. you do not use that or your chip is not STM32), just skip stage I and write your own startup code.


# Prerequisites

* CLion 2021.3+
* Stm32CubeMX 6.3.0+
* CMake 3.22 (3.22-rc2 as on 9-Nov-2021)
* IAR Embedded WorkBench for ARM with a license
* STM32F3-Discovery
* OpenOCD

# Create a project

Start Stm32CubeMX, open board selector, STM32F3-Discovery, and create the project. Important changes: 

![Pin Modes](docs/project-1.png "LED pins modes")

![Project Settings](docs/project-2.png "Project Settings")

![Code Generator Settings](docs/project-3.png "Project Code Generation Settings")

Then generate the project

# Clion Toolchains settings

![Clion Settings Toolchains](docs/clion-settings-toolchain.png "Clion Settings Toolchains")

# CLion project adjustments

1. Open the project in CLion (ignore CMake errors reported)
2. Write _CMakeLists.txt_ as here [CMakeLists.txt](CMakeLists.txt)
3. Use [toolchain file](toolchain-iar-9-arm.cmake) from this project. 
Ensure that  IAR toolchain root location is correct. 
4. Use [CMake presets file](CMakePresets.json) from this project
5. Add your code to `main()` and `cppMain` functions
6. Right-click _CMakeLists.txt_ in the project tree and click _Load CMake Project_
7. Open *File | Settings | Build, Execution, Deployment | CMake* dialog and enable `Default ` profile

# Debug

1. Open _Run Configurations_
    1. Drop existing one(s)
    2. Create _OpenOCD Download & Run_
    3. Click “Assist”, find your board, or closest to your config
    4. Click “Copy to Project & Use” \
        ![Run Configuration Settings](docs/run-config.png "Run Configuration Settings")
    5. Open OpenOCD config file and add to the very end \
2. (Optional) Enable semihosting via [.gdbinit](.gdbinit)
3. Set breakpoint to the very beginning of main()
4. Click debug button
5. Wait a bit
6. Debugger works
7. Enjoy!
