

#include "stm32l0xx_hal_gpio.h"
#include "stdint.h"

class gpioInit {

public:
	gpioInit();
	gpioInit(GPIO_InitTypeDef *gpioStruct, uint32_t *_pin,uint32_t *_mode,
			uint32_t *_pull,uint32_t *_speed);
	void writePin(GPIO_PinState _pinstate);
	void togglePin();


private:


	uint32_t *pin;
	uint32_t *mode;
	uint32_t *pull;
	uint32_t *speed;
	GPIO_TypeDef *port;
	GPIO_InitTypeDef *gpioInitStruct;



};
