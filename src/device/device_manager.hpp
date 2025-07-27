#ifndef DEVICE_MANAGER_HPP
#define DEVICE_MANAGER_HPP

#include "hardware_rp2040/hardware_manager.hpp"
#include "device/user_indication/user_indication.hpp"

class DeviceManager
{
   private:
    device_layer::UserIndication userIndication;

   public:
    DeviceManager(HardwareManager& hardware_manager);
    ~DeviceManager() = default;
    device_layer::UserIndication& getUserIndication();
};

#endif  // DEVICE_MANAGER_HPP