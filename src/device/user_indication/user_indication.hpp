#ifndef USER_INDICATION_HPP
#define USER_INDICATION_HPP

#include "i_user_indication.hpp"

class IGpioPin;
class UserIndication : public IUserIndication
{
   private:
    IGpioPin* outputPin = nullptr;

   public:
    UserIndication(IGpioPin& init_output_pin);
    ~UserIndication() = default;

    void set() override;
    void reset() override;
    void setOutputPin(IGpioPin& init_output_pin);
};

#endif  // USER_INDICATION_HPP