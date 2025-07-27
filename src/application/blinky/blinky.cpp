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
#include <common.hpp>

// unnamed namespace for local definitions with internal linkage
namespace
{
// Q_DEFINE_THIS_FILE

}  // unnamed namespace

namespace app
{
//............................................................................
Blinky::Blinky()
{
    // empty
}

void Blinky::run()
{
    for (;;)
    {
        userIndication->reset();
        for (int it = 0; it < 1000000; it++)
        {
            volatile int temp;
            temp++;
        }
        userIndication->set();
        for (int it = 0; it < 1000000; it++)
        {
            volatile int temp;
            temp++;
        }
    }
}

//............................................................................
void Blinky::setUserIndication(
    device_layer::IUserIndication& init_user_indication)
{
    userIndication = &init_user_indication;
}

}  // namespace app
