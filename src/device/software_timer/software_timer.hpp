#ifndef SOFTWARE_TIMER_HPP
#define SOFTWARE_TIMER_HPP

#include <bits/c++config.h>
#include <cstdint>
#include "i_software_timer.hpp"
#include "icb_software_timer.hpp"
#include "hardware_abstraction/interrupt_dispatcher/icb_interrupt_disp.hpp"

namespace hardware_layer
{
class ITimer;
}

namespace device_layer
{
using hardware_layer::IcbIntDispatcher;
using hardware_layer::ITimer;

class SoftwareTimer : public ISoftwareTimer, public IcbIntDispatcher
{
   public:
    explicit SoftwareTimer(ITimer& timer);
    ~SoftwareTimer() = default;

    std::uint64_t get() const override;
    void setAlarm(std::uint32_t alarm_value) override;
    void setIcbSoftwareTimer(IcbSoftwareTimer& software_timer) override;

   private:
    // members
    ITimer* i_timer;
    IcbSoftwareTimer* icb_software_timer{nullptr};

    // methods:
    void notifyInterruptService(void) override;
};
}  // namespace device_layer

#endif