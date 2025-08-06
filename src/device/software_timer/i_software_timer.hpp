#ifndef I_SOFTWARE_TIMER_HPP
#define I_SOFTWARE_TIMER_HPP

#include <cstdint>
#include "icb_software_timer.hpp"
namespace device_layer
{
class ISoftwareTimer
{
   public:
    ~ISoftwareTimer() = default;

    virtual std::uint64_t get() const = 0;
    virtual void setAlarm(std::uint32_t alarm_value) = 0;
    virtual void setIcbSoftwareTimer(IcbSoftwareTimer& software_timer) = 0;
};
}  // namespace device_layer

#endif