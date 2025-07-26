#ifndef HARDWARE_MANAGER_HPP
#define HARDWARE_MANAGER_HPP

#include "hardware/gpio_pin/gpio_pin.hpp"

class HardwareManager
{
   private:
    GpioPin ledPin;

   public:
    HardwareManager();
    ~HardwareManager() = default;
    void run();
    GpioPin& getLedPin();
};

#endif  // HARDWARE_MANAGER_HPP