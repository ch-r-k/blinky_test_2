#include "hardware_manager_x86.hpp"

HardwareManager::HardwareManager()
    : ledPin(GpioPin::Port::NONE, 25, GpioPin::Mode::GPIO_OUT,
             GpioPin::Pull::DOWN, GpioPin::Speed::NONE, GpioPin::Function::SIO)
{
}

IGpioPin& HardwareManager::getLedPin() { return ledPin; }

ITimer& HardwareManager::getTimer() { return timer; }
