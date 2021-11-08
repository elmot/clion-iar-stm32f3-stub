#include <main.h>
#include <cstdio>

extern "C" void cppMain(void);

/**
  @brief         In-place 32 bit reversal function.
  @param[in,out] pSrc        points to in-place buffer of unknown 32-bit data type
  @param[in]     bitRevLen   bit reversal table length
  @param[in]     pBitRevTab  points to bit reversal table
  @return        none
*/
extern "C" void arm_bitreversal_32(
    uint32_t *pSrc,
    uint16_t bitRevLen,
uint16_t *pBitRevTab);

void cppMain() {
    HAL_Delay(500);
    HAL_GPIO_TogglePin(LD3_GPIO_Port,LD3_Pin);
    printf("arm_bitreversal_32 function address: 0x%08x",&arm_bitreversal_32);
}
