//============================================================================
// Blinky example
//============================================================================

#ifndef BLINKY_HPP_
#define BLINKY_HPP_

#include <cstdint>
#include "device/software_timer/icb_software_timer.hpp"
namespace device_layer
{
class IUserIndication;
class ISoftwareTimer;
}  // namespace device_layer

using device_layer::ISoftwareTimer;
using device_layer::IUserIndication;

namespace app
{
class Blinky : public IcbSoftwareTimer
{
   private:
    enum class State
    {
        LED_OFF = 0,
        LED_ON = 1
    };

    enum class MessageStatus
    {
        PENDING = 0,
        TRIGGER
    };

    IUserIndication* iUserIndication;
    ISoftwareTimer* iSoftwareTimer;
    State state;
    std::uint64_t last_time{0};
    volatile MessageStatus timeout_message{MessageStatus::PENDING};
    static constexpr std::uint32_t TIMEOUT_US{500'000};

    void notify() override;

   public:
    Blinky(IUserIndication& user_indication, ISoftwareTimer& software_timer);
    void run();
};

}  // namespace app

#endif  // BLINKY_HPP_
