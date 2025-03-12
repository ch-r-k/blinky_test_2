#include "output_pin.hpp"
#include <stdint.h>
#include "common.hpp"

OutputPin::OutputPin() {}

OutputPin::~OutputPin() {}

void OutputPin::configure(Port initPort, uint8_t initPin, Mode initMode,
                          Pull initPull, Speed initSpeed, Function initFunction)
{
    UNUSED(initPort);
    UNUSED(initSpeed);

    pin = initPin;
    mode = initMode;
    pull = initPull;
    function = initFunction;

    gpio_set_dir(static_cast<uint8_t>(pin), static_cast<uint8_t>(initMode));

    switch (initPull)
    {
        case Pull::NONE:
            gpio_set_pulls(static_cast<uint8_t>(initPin), false, false);
            break;
        case Pull::UP:
            gpio_set_pulls(static_cast<uint8_t>(initPin), true, false);
            break;

        case Pull::DOWN:
            gpio_set_pulls(static_cast<uint8_t>(initPin), false, true);
            break;
    }

    gpio_set_function(static_cast<uint8_t>(initPin),
                      static_cast<gpio_function_t>(initFunction));
}

void OutputPin::set() { gpio_put(static_cast<uint8_t>(pin), 1); }

void OutputPin::reset() { gpio_put(static_cast<uint8_t>(pin), 0); }