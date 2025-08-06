#ifndef HARDWARE_MANAGER_HPP
#define HARDWARE_MANAGER_HPP

#include "hardware_abstraction/timer/i_timer.hpp"
#include "hardware_rp2040/gpio_pin/gpio_pin.hpp"
#include "hardware_rp2040/timer/timer.hpp"
#include "hardware_rp2040/interrupt_dispatcher/interrupt_dispatcher.hpp"

using hardware_layer::GpioPin;
using hardware_layer::IGpioPin;
using hardware_layer::IntDispatcher;
using hardware_layer::ITimer;
using hardware_layer::Timer;

class HardwareManager
{
   private:
    GpioPin ledPin;
    Timer timer;
    IntDispatcher intDispatcher;

   public:
    HardwareManager();
    ~HardwareManager() = default;
    void run();
    IGpioPin& getLedPin();
    ITimer& getTimer();
    IntDispatcher& getIntDispatcher();
};

#endif  // HARDWARE_MANAGER_HPP