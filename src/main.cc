#include "stm32l0xx_hal.h"
#include "gpio_init.h"

#define LED_PIN                                GPIO_PIN_5
#define LED_GPIO_PORT                          GPIOA
#define LED_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOA_CLK_ENABLE()

GPIO_InitTypeDef led;
gpioInit _led(led, LED_PIN, LED_GPIO_PORT, GPIO_MODE_OUTPUT_PP);

int main(void)
{
    HAL_Init();
    LED_GPIO_CLK_ENABLE();  // Ensure GPIO clock is enabled

    while (1)
    {
        _led.togglePin();
        HAL_Delay(1000);
    }
}

void SysTick_Handler(void)
{
    HAL_IncTick();
}
