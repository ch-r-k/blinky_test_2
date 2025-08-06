#include "device_manager.hpp"
#include "device/software_timer/software_timer.hpp"
#include "hardware_rp2040/interrupt_dispatcher/nvic_types.hpp"

using hardware_layer::IntVectorNumber;

DeviceManager::DeviceManager(HardwareManager& hardware_manager)
    : userIndication(hardware_manager.getLedPin()),
      softwareTimer(hardware_manager.getTimer())
{
    hardware_manager.getIntDispatcher().registerIntCallback(
        &softwareTimer, IntVectorNumber::TIMER_IRQ_0);
}

IUserIndication& DeviceManager::getUserIndication() { return userIndication; }

ISoftwareTimer& DeviceManager::getSoftwareTimer() { return softwareTimer; }
