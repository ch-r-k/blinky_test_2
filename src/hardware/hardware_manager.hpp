#ifndef HARDWARE_MANAGER_HPP
#define HARDWARE_MANAGER_HPP

#include "output_pin/output_pin.hpp"

class HardwareManager
{
   private:
    OutputPin ledPin;

   public:
    HardwareManager();
    ~HardwareManager() = default;
    void run();
    OutputPin& getLedPin();
};

#endif  // HARDWARE_MANAGER_HPP