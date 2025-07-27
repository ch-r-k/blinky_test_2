#ifndef HARDWARE_MANAGER_HPP
#define HARDWARE_MANAGER_HPP

#include "hardware_rp2040/gpio_pin/gpio_pin.hpp"

class HardwareManager
{
   private:
    hardware_layer::GpioPin ledPin;

   public:
    HardwareManager();
    ~HardwareManager() = default;
    void run();
    hardware_layer::GpioPin& getLedPin();
};

#endif  // HARDWARE_MANAGER_HPP