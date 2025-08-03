//============================================================================
// QP/C++ Real-Time Embedded Framework
//============================================================================
//! @date Last updated on: 2022-08-25
//! @version Last updated Zephyr 3.1.99 and @ref qpcpp_7_1_0
//!
//! @file
//! @brief Blinky example
//!
#include "blinky.hpp"
#include "device/user_indication/i_user_indication.hpp"
#include "device/software_timer/i_software_timer.hpp"

// unnamed namespace for local definitions with internal linkage
namespace
{
// Q_DEFINE_THIS_FILE

}  // unnamed namespace

namespace app
{
//............................................................................
Blinky::Blinky(IUserIndication& user_indication, ISoftwareTimer& software_timer)
{
    iUserIndication = &user_indication;
    iSoftwareTimer = &software_timer;
    state = State::LED_OFF;
    last_time = 0;
}

void Blinky::run()
{
    for (;;)
    {
        if (iSoftwareTimer->get() - last_time > 1000000)
        {
            if (state == State::LED_OFF)
            {
                state = State::LED_ON;
                iUserIndication->reset();
            }
            else
            {
                state = State::LED_OFF;
                iUserIndication->set();
            }

            last_time = iSoftwareTimer->get();
        }
    }
}

}  // namespace app
