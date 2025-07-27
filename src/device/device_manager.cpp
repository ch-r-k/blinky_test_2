#include "device_manager.hpp"

DeviceManager::DeviceManager(HardwareManager& hardware_manager)
    : userIndication(hardware_manager.getLedPin())
{
}

device_layer::UserIndication& DeviceManager::getUserIndication()
{
    return userIndication;
}