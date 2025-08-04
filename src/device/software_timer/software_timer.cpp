#include <cstdint>
#include "software_timer.hpp"
#include "hardware_abstraction/timer/i_timer.hpp"

namespace device_layer
{
SoftwareTimer::SoftwareTimer(ITimer& timer) { i_timer = &timer; }

std::uint64_t SoftwareTimer::get() const { return i_timer->get(); }

void SoftwareTimer::setAlarm(std::uint64_t alarm_value)
{
    i_timer->setAlarm(alarm_value);
}

}  // namespace device_layer