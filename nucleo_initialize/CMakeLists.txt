cmake_minimum_required(VERSION 3.15.3)

project(nucleo_l073rz_initialize)

enable_language(C ASM)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)


set(STM32CUBEMX_GENERATED_FILES

	Src/main.c
	Src/stm32l0xx_it.c
	Src/stm32l0xx_hal_msp.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_tim.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_tim_ex.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_uart.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_uart_ex.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_i2c.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_i2c_ex.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rcc.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rcc_ex.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_flash_ramfunc.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_flash.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_flash_ex.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_gpio.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_dma.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_pwr.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_pwr_ex.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_cortex.c
	Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_exti.c 
	Src/system_stm32l0xx.c  
	
	startup_stm32l073xx.s)

set(EXECUTABLE ${PROJECT_NAME}.out)

add_executable(${EXECUTABLE} ${STM32CUBEMX_GENERATED_FILES})

target_compile_definitions(${EXECUTABLE} PRIVATE
	-DUSE_HAL_DRIVER
	-DSTM32L073xx
        )

target_include_directories(${EXECUTABLE} PRIVATE
	Inc
	Drivers/STM32L0xx_HAL_Driver/Inc
	Drivers/STM32L0xx_HAL_Driver/Inc/Legacy
	Drivers/CMSIS/Device/ST/STM32L0xx/Include
	Drivers/CMSIS/Include
        )

target_compile_options(${EXECUTABLE} PRIVATE
        -mcpu=cortex-m0plus
        -mthumb
        -mfloat-abi=softfp

        -fdata-sections
        -ffunction-sections

        -Wall

        $<$<CONFIG:Debug>:-Og>
        )

target_link_options(${EXECUTABLE} PRIVATE
        -T${CMAKE_SOURCE_DIR}/STM32L073RZTx_FLASH.ld
        -mcpu=cortex-m0plus
        -mthumb
        -mfloat-abi=softfp
        -specs=nano.specs
        -lc
        -lm
        -lnosys
        -Wl,-Map=${PROJECT_NAME}.map,--cref
        -Wl,--gc-sections
        )

# Print executable size
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND arm-none-eabi-size ${EXECUTABLE})

# Create hex file
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND arm-none-eabi-objcopy -O ihex ${EXECUTABLE} ${PROJECT_NAME}.hex
        COMMAND arm-none-eabi-objcopy -O binary ${EXECUTABLE} ${PROJECT_NAME}.bin)

