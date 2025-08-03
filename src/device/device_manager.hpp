#ifndef DEVICE_MANAGER_HPP
#define DEVICE_MANAGER_HPP

#include "hardware_abstraction/i_hardware_manager.hpp"
#include "device/software_timer/software_timer.hpp"
#include "device/user_indication/i_user_indication.hpp"
#include "device/user_indication/user_indication.hpp"
#include "device/software_timer/i_software_timer.hpp"

using device_layer::ISoftwareTimer;
using device_layer::IUserIndication;

class DeviceManager
{
   private:
    device_layer::UserIndication userIndication;
    device_layer::SoftwareTimer softwareTimer;

   public:
    DeviceManager(HardwareManager& hardware_manager);
    ~DeviceManager() = default;
    IUserIndication& getUserIndication();
    ISoftwareTimer& getSoftwareTimer();
};

#endif  // DEVICE_MANAGER_HPP