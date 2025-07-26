#ifndef GPIO_PIN_HPP
#define GPIO_PIN_HPP

#include <cstdint>
#include "hardware_abstraction/gpio_pin/i_gpio_pin.hpp"

#include "hardware/gpio.h"

class GpioPin : public IGpioPin
{
   public:
    enum class Port : std::uint8_t
    {
        NONE = 0
    };

    enum class Mode : std::uint8_t
    {
        GPIO_OUT = 1u,
        GPIO_IN = 0u
    };

    enum class Pull : std::uint8_t
    {
        NONE = 0,
        UP = 1,
        DOWN = 2
    };

    enum class Speed : std::uint8_t
    {
        NONE = 0
    };

    enum class Function : std::uint8_t
    {
        XIP = 0,
        SPI = 1,
        UART = 2,
        I2C = 3,
        PWM = 4,
        SIO = 5,
        PIO0 = 6,
        PIO1 = 7,
        GPCK = 8,
        USB = 9,
        NONE = 0x1f,
    };

   private:
    Port port;
    std::uint8_t pin;
    Mode mode;
    Pull pull;
    Speed speed;
    Function function;

   public:
    GpioPin(Port initPort, std::uint8_t initPin, Mode initMode, Pull initPull,
            Speed initSpeed, Function initFunction);
    ~GpioPin() = default;
    void configure(Port initPort, uint8_t initPin, Mode initMode, Pull initPull,
                   Speed initSpeed, Function initFunction);
    void set() override;
    void reset() override;
    bool get() override;
};

#endif  // GPIO_PIN_HPP