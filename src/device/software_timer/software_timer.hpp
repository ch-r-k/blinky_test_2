#ifndef SOFTWARE_TIMER_HPP
#define SOFTWARE_TIMER_HPP

#include <bits/c++config.h>
#include <cstdint>
#include "device/software_timer/i_software_timer.hpp"

namespace hardware_layer
{
class ITimer;
}
namespace device_layer
{
using hardware_layer::ITimer;

class SoftwareTimer : public ISoftwareTimer
{
   public:
    explicit SoftwareTimer(ITimer& timer);
    ~SoftwareTimer() = default;

    std::uint64_t get() const override;
    void setAlarm(std::uint64_t alarm_value) override;

   private:
    ITimer* i_timer;
};
}  // namespace device_layer

#endif