#include <stdint.h>
#include <stdbool.h>
#include "RS232_helper.h"
#include "stm32h7xx_hal.h"
void RS232_putc(int a)
{
    extern UART_HandleTypeDef huart1;
    uint8_t *pChar = (uint8_t*)&a;
    //uint32_t x = 0U;

    HAL_UART_Transmit_IT(
        &huart1,
        pChar,
        sizeof(uint8_t)
    );
    do{
        if(huart1.gState == HAL_UART_STATE_READY)
        {
            break;
        }
    }while (true);
}