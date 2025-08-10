#ifndef TIMER_HPP
#define TIMER_HPP

#include <cstdint>
#include <chrono>
#include "hardware_abstraction/interrupt_dispatcher/icb_interrupt_ack.hpp"
#include "hardware_abstraction/timer/i_timer.hpp"
#include "hardware_abstraction/timer/icb_timer.hpp"

namespace hardware_layer
{
class Timer : public ITimer, public IcbIntAcknowledge
{
   public:
    explicit Timer();
    ~Timer() = default;

    std::uint64_t get() override;
    void setAlarm(std::uint32_t alarm_value) override;
    void setCallback(IcbTimer& timer) override;

   private:
    std::chrono::steady_clock::time_point start_time;
    IcbTimer* icb_timer{nullptr};
    void clearInterrupt();
    void notifyInterruptAcknowledge() override;
};

}  // namespace hardware_layer

#endif