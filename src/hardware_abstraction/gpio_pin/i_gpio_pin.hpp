#ifndef I_GPIO_PIN_HPP
#define I_GPIO_PIN_HPP

class IGpioPin
{
   public:
    virtual void set() = 0;
    virtual void reset() = 0;

    virtual bool get() = 0;
};

#endif  // I_GPIO_PIN_HPP