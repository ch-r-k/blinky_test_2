#ifndef OUTPUT_PIN_HPP
#define OUTPUT_PIN_HPP

#include <stdint.h>
#include "i_output_pin.hpp"

#include "hardware/gpio.h"

class OutputPin : public IOutputPin
{
   public:
    enum class Port : uint8_t
    {
        NONE = 0
    };

    enum class Mode : uint8_t
    {
        GPIO_OUT = 1u,
        GPIO_IN = 0u
    };

    enum class Pull : uint8_t
    {
        NONE = 0,
        UP = 1,
        DOWN = 2
    };

    enum class Speed : uint8_t
    {
        NONE = 0
    };

    enum class Function : uint8_t
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
    uint8_t pin;
    Mode mode;
    Pull pull;
    Speed speed;
    Function function;

   public:
    OutputPin();
    ~OutputPin();
    void configure(Port initPort, uint8_t initPin, Mode initMode, Pull initPull,
                   Speed initSpeed, Function initFunction);
    void set() override;
    void reset() override;
};

#endif  // OUTPUT_PIN_HPP