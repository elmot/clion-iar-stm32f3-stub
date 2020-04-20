#include <c/stdnoreturn.h>

extern "C" {
#include "main.h"
}

template <uintptr_t GpioPort,uint16_t GpioPin> class Pin
{
public:
    void on() {
        HAL_GPIO_WritePin(reinterpret_cast<GPIO_TypeDef *>(GpioPort), GpioPin, GPIO_PIN_SET);
    }
    void off() {
        HAL_GPIO_WritePin(reinterpret_cast<GPIO_TypeDef *>(GpioPort), GpioPin, GPIO_PIN_RESET);
    }
    void toggle() {
        HAL_GPIO_TogglePin(reinterpret_cast<GPIO_TypeDef *>(GpioPort), GpioPin);
    }
};

void cppMain(void)  {
    Pin<(uintptr_t)LD3_GPIO_Port,LD3_Pin> red;
    Pin<(uintptr_t)LD4_GPIO_Port,LD4_Pin> blue;
    Pin<(uintptr_t)LD5_GPIO_Port,LD5_Pin> orange;
    while (true) {
        red.toggle();
        HAL_Delay(350);
        orange.toggle();
        HAL_Delay(350);
        blue.toggle();
        HAL_Delay(350);
    }
}
