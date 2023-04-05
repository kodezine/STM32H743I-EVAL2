#include <stdbool.h>
#include <stdint.h>

#include "demo.h"
#include "main.h"
#include "usart.h"
#include "stm32h7xx_hal.h"

extern UART_HandleTypeDef huart1;

static volatile uint8_t RxBuffer[64];
static const uint8_t dot = '.';

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (&huart1 == huart)
    {
        HAL_GPIO_TogglePin(LED1_RGB_GPIO_Port, LED1_RGB_Pin);
    }
}
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
}

__NO_RETURN void app_main(void)
{
    HAL_SetTickFreq(HAL_TICK_FREQ_1KHZ);
    HAL_UART_Transmit_IT(&huart1, &dot, 1);
    do
    {
        //HAL_UARTEx_ReceiveToIdle_IT(&huart1, (uint8_t *)RxBuffer, 1);
        HAL_UART_Transmit_IT(&huart1, &dot, 1);
        HAL_GPIO_TogglePin(LED3_RGB_GPIO_Port, LED3_RGB_Pin); /* Toggle pin after some delay */
        HAL_Delay(20);                              /* busy wait delay */
    } while (true);
}
