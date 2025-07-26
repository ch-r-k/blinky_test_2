#include "user_indication.hpp"

UserIndication::UserIndication(IOutputPin& initOutputPin)
{
    setOutputPin(initOutputPin);
}

void UserIndication::set() { outputPin->set(); }

void UserIndication::reset() { outputPin->reset(); }

void UserIndication::setOutputPin(IOutputPin& initOutputPin)
{
    this->outputPin = &initOutputPin;
}