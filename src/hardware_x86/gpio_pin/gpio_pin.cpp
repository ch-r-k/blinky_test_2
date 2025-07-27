#include "gpio_pin.hpp"
#include <stdio.h>
#include <cstdint>
#include "common.hpp"

namespace hardware_layer
{
GpioPin::GpioPin(Port initPort, uint8_t initPin, Mode initMode, Pull initPull,
                 Speed initSpeed, Function initFunction)
{
    configure(initPort, initPin, initMode, initPull, initSpeed, initFunction);
}

void GpioPin::configure(Port initPort, uint8_t initPin, Mode initMode,
                        Pull initPull, Speed initSpeed, Function initFunction)
{
    UNUSED(initPort);
    UNUSED(initSpeed);

    pin = initPin;
    mode = initMode;
    pull = initPull;
    function = initFunction;

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