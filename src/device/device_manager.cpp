#include "device_manager.hpp"
#include "user_indication.hpp"

DeviceManager::DeviceManager(HardwareManager& hardwareManager)
    : userIndication(hardwareManager.getLedPin())
{
}

UserIndication& DeviceManager::getUserIndication() { return userIndication; }