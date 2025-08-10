#include "timer.hpp"

namespace hardware_layer
{
Timer::Timer() : start_time(std::chrono::steady_clock::now()) {}

std::uint64_t Timer::get()
{
    // auto now = std::chrono::steady_clock::now();
    // auto elapsed = now - start_time;
    // return std::chrono::duration_cast<std::chrono::microseconds>(elapsed)
    //     .count();

    return 0;
}

void Timer::setAlarm([[maybe_unused]] std::uint32_t alarm_value)
{
    notifyInterruptAcknowledge();
}

void Timer::clearInterrupt() {}

void Timer::setCallback(IcbTimer& timer) { icb_timer = &timer; }

void Timer::notifyInterruptAcknowledge() { icb_timer->notify(); }

}  // namespace hardware_layer
