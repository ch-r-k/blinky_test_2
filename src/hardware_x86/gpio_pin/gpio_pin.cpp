#include "gpio_pin.hpp"
#include <stdio.h>
#include <cstdint>
#include "common.hpp"

namespace hardware_layer
{
GpioPin::GpioPin(Port init_port, uint8_t init_pin, Mode init_mode,
                 Pull init_pull, Speed init_speed, Function init_function)
{
    configure(init_port, init_pin, init_mode, init_pull, init_speed,
              init_function);
}

void GpioPin::configure(Port init_port, uint8_t init_pin, Mode init_mode,
                        Pull init_pull, Speed init_speed,
                        Function init_function)
{
    UNUSED(init_port);
    UNUSED(init_speed);

    pin = init_pin;
    mode = init_mode;
    pull = init_pull;
    function = init_function;

    printf("gpio configure \n");
}

void GpioPin::set() { printf("gpio set \n"); }

void GpioPin::reset() { printf("gpio reset \n"); }

bool GpioPin::get()
{
    printf("gpio get \n");
    return false;
}

}  // namespace hardware_layer