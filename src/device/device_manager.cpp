#include "device_manager.hpp"
#include "device/software_timer/software_timer.hpp"

DeviceManager::DeviceManager(HardwareManager& hardware_manager)
    : userIndication(hardware_manager.getLedPin()),
      softwareTimer(hardware_manager.getTimer())
{
}

IUserIndication& DeviceManager::getUserIndication() { return userIndication; }

ISoftwareTimer& DeviceManager::getSoftwareTimer() { return softwareTimer; }
