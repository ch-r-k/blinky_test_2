#include "hardware_manager.hpp"


HardwareManager::HardwareManager()
{
    // Hal init
    //HAL_Init();

    // GPIO Ports Clock Enable
    //__HAL_RCC_GPIOA_CLK_ENABLE();
}

HardwareManager::~HardwareManager() {}

OutputPin& HardwareManager::getLedPin() { return ledPin; }