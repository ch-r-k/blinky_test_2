#ifndef I_GPIO_PIN_HPP
#define I_GPIO_PIN_HPP

namespace hardware_layer
{
class IGpioPin
{
   public:
    virtual void set() = 0;
    virtual void reset() = 0;

    virtual bool get() = 0;
};
}  // namespace hardware_layer

#endif  // I_GPIO_PIN_HPP