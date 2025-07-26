#include "application_manager.hpp"

ApplicationManager::ApplicationManager(DeviceManager& device_manager)
{
    blinky.setUserIndication(device_manager.getUserIndication());
}

ApplicationManager::~ApplicationManager() {}

void ApplicationManager::start() { blinky.run(); }