#ifndef HARDWARE_MANAGER_HPP
#define HARDWARE_MANAGER_HPP

#include "hardware_x86/gpio_pin/gpio_pin.hpp"
#include "hardware_x86/timer/timer.hpp"

using hardware_layer::GpioPin;
using hardware_layer::IGpioPin;
using hardware_layer::ITimer;
using hardware_layer::Timer;

class HardwareManager
{
   private:
    GpioPin ledPin;
    Timer timer;

   public:
    HardwareManager();
    ~HardwareManager() = default;
    void run();
    IGpioPin& getLedPin();
    ITimer& getTimer();
};

#endif  // HARDWARE_MANAGER_HPP