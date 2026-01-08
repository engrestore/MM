#include "stm32f411xe.h"
#include "system_stm32f4xx.h"

uint32_t SystemCoreClock = 16000000;
const uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13};
const uint8_t APBPrescTable[8]  = {0, 0, 0, 0, 1, 2, 3, 4};

void SystemInit(void) {}
void SystemCoreClockUpdate(void) {}
