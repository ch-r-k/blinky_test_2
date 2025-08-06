#include "application_manager.hpp"
#include "hardware_manager/hardware_manager_rp2040.hpp"

ApplicationManager::ApplicationManager(DeviceManager& device_manager)
    : blinky(device_manager.getUserIndication(),
             device_manager.getSoftwareTimer())
{
    device_manager.getSoftwareTimer().setIcbSoftwareTimer(blinky);
}

ApplicationManager::~ApplicationManager() {}

void ApplicationManager::start() { blinky.run(); }