#include "gpio_init.h"
#include "stm32l0xx_hal.h"

gpioInit::gpioInit(GPIO_InitTypeDef gpioStruct, uint32_t _pin, GPIO_TypeDef* _port, uint32_t _mode,
                   uint32_t _pull, uint32_t _speed)
    : pin(_pin), mode(_mode), pull(_pull), speed(_speed), port(_port) {

    gpioStruct.Pin = pin;
    gpioStruct.Mode = mode;
    gpioStruct.Pull = pull;
    gpioStruct.Speed = speed;
    gpioInitStruct = gpioStruct;
    HAL_GPIO_Init(port, &gpioInitStruct);  // Initialize GPIO with port as a pointer
}

void gpioInit::writePin(GPIO_PinState _pinstate) {
    HAL_GPIO_WritePin(port, pin, _pinstate);  // Use port as a pointer
}

void gpioInit::togglePin() {
    HAL_GPIO_TogglePin(port, pin);  // Use port as a pointer
}
