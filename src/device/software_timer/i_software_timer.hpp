#ifndef I_SOFTWARE_TIMER_HPP
#define I_SOFTWARE_TIMER_HPP

#include <cstdint>
namespace device_layer
{
class ISoftwareTimer
{
   public:
    ~ISoftwareTimer() = default;

    virtual std::uint64_t get() const = 0;
    virtual void setAlarm(std::uint64_t alarm_value) = 0;
};
}  // namespace device_layer

#endif