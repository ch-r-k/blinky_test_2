#ifndef APPLICATION_MANAGER_HPP
#define APPLICATION_MANAGER_HPP

#include "blinky/blinky.hpp"
#include "device/device_manager.hpp"

class ApplicationManager
{
   private:
    app::Blinky blinky;

   public:
    ApplicationManager(DeviceManager& device_manager);
    ~ApplicationManager();

    void start();
};

#endif  // APPLICATION_MANAGER_HPP
