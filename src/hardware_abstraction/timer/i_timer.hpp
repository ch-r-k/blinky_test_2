#ifndef I_TIMER_HPP
#define I_TIMER_HPP

#include <cstdint>
#include "icb_timer.hpp"
namespace hardware_layer
{
class ITimer
{
   public:
    ~ITimer() = default;
    virtual std::uint64_t get() = 0;
    virtual void setAlarm(std::uint32_t alarm_value) = 0;
    virtual void setCallback(IcbTimer& icb_timer) = 0;
};
}  // namespace hardware_layer

#endif