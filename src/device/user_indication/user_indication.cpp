#include "user_indication.hpp"
#include "hardware_abstraction/gpio_pin/i_gpio_pin.hpp"

UserIndication::UserIndication(IGpioPin& init_output_pin)
{
    setOutputPin(init_output_pin);
}

void UserIndication::set() { outputPin->set(); }

void UserIndication::reset() { outputPin->reset(); }

void UserIndication::setOutputPin(IGpioPin& init_output_pin)
{
    this->outputPin = &init_output_pin;
}