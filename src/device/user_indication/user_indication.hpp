#ifndef USER_INDICATION_HPP
#define USER_INDICATION_HPP

#include "i_user_indication.hpp"
#include "hardware_abstraction/gpio_pin/i_gpio_pin.hpp"

class UserIndication : public IUserIndication
{
   private:
    IGpioPin* outputPin = nullptr;

   public:
    UserIndication(IGpioPin& initOutputPin);
    ~UserIndication() = default;

    void set() override;
    void reset() override;
    void setOutputPin(IGpioPin& initOutputPin);
};

#endif  // USER_INDICATION_HPP