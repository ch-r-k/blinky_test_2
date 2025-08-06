#ifndef USER_INDICATION_HPP
#define USER_INDICATION_HPP

#include "i_user_indication.hpp"

namespace hardware_layer
{
class IGpioPin;
}

namespace device_layer
{
class UserIndication : public IUserIndication
{
   private:
    hardware_layer::IGpioPin* outputPin = nullptr;

   public:
    UserIndication(hardware_layer::IGpioPin& init_output_pin);
    ~UserIndication() = default;

    void set() override;
    void reset() override;
    void setOutputPin(hardware_layer::IGpioPin& init_output_pin);
};
}  // namespace device_layer

#endif  // USER_INDICATION_HPP