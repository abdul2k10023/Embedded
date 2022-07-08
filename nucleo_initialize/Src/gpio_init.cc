/*
 * gpio_init.cc
 *
 *  Created on: Jun 2, 2022
 *      Author: abdul haseeb
 */

#include "gpio_init.h"
#include "stm32l0xx_hal_gpio.h"


gpioInit::gpioInit(GPIO_InitTypeDef *gpioStruct, uint32_t *_pin,uint32_t *_mode)
: pin(_pin),mode(_mode),pull(_pull),speed(_speed),port(_port)
{



	gpioStruct->Pin=pin;
	gpioStruct->Mode=mode;
	gpioStruct->Pull=pull;
	gpioStruct->Speed=speed;

	gpioInitStruct = gpioStruct;

	HAL_GPIO_Init(port,gpioInitStruct);
}

void gpioInit::writePin(GPIO_PinState _pinstate){

	HAL_GPIO_WritePin(port,pin,_pinstate);
}

void gpioInit::togglePin(){

	HAL_GPIO_TogglePin(port,pin);

}
