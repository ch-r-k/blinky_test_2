#include "device_manager.hpp"

DeviceManager::DeviceManager(HardwareManager& hardwareManager)
    : userIndication(hardwareManager.getLedPin())
{
}

UserIndication& DeviceManager::getUserIndication() { return userIndication; }