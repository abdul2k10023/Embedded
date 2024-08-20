#ifndef GPIOINIT_H
#define GPIOINIT_H

#include "stm32l0xx_hal.h"
#include "stdint.h"

class gpioInit {

public:
    gpioInit(GPIO_InitTypeDef gpioStruct, uint32_t _pin, GPIO_TypeDef* _port, uint32_t _mode,
             uint32_t _pull = GPIO_NOPULL, uint32_t _speed = GPIO_SPEED_FREQ_LOW);
    void writePin(GPIO_PinState _pinstate);
    void togglePin();

private:
    uint32_t pin;
    uint32_t mode;
    uint32_t pull;
    uint32_t speed;
    GPIO_TypeDef* port;
    GPIO_InitTypeDef gpioInitStruct;
};

#endif // GPIOINIT_H
