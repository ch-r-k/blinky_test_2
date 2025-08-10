#ifndef ICB_TIMER_HPP
#define ICB_TIMER_HPP

#include <cstdint>
namespace hardware_layer
{
class IcbTimer
{
   public:
    ~IcbTimer() = default;
    virtual void notify() = 0;
};
}  // namespace hardware_layer

#endif