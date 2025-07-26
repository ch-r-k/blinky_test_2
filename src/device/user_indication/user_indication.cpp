#include "user_indication.hpp"

UserIndication::UserIndication(IGpioPin& initOutputPin)
{
    setOutputPin(initOutputPin);
}

void UserIndication::set() { outputPin->set(); }

void UserIndication::reset() { outputPin->reset(); }

void UserIndication::setOutputPin(IGpioPin& initOutputPin)
{
    this->outputPin = &initOutputPin;
}