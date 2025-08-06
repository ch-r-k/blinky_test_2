#include "hardware_manager_x86.hpp"

HardwareManager::HardwareManager()
    : ledPin(hardware_layer::GpioPin::Port::NONE, 25,
             hardware_layer::GpioPin::Mode::GPIO_OUT,
             hardware_layer::GpioPin::Pull::DOWN,
             hardware_layer::GpioPin::Speed::NONE,
             hardware_layer::GpioPin::Function::SIO)
{
}

hardware_layer::GpioPin& HardwareManager::getLedPin() { return ledPin; }