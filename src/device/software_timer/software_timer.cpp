#include <cstdint>
#include "software_timer.hpp"
#include "icb_software_timer.hpp"
#include "hardware_abstraction/timer/i_timer.hpp"

namespace device_layer
{
SoftwareTimer::SoftwareTimer(ITimer& timer) { i_timer = &timer; }

std::uint64_t SoftwareTimer::get() const { return i_timer->get(); }

void SoftwareTimer::setAlarm(std::uint32_t alarm_value)
{
    i_timer->setAlarm(alarm_value);
}

void SoftwareTimer::setIcbSoftwareTimer(IcbSoftwareTimer& software_timer)
{
    icb_software_timer = &software_timer;
}

void SoftwareTimer::notify(void) { icb_software_timer->notify(); }

}  // namespace device_layer