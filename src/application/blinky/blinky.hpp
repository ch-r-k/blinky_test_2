//============================================================================
// Blinky example
//============================================================================

#ifndef BLINKY_HPP_
#define BLINKY_HPP_

namespace device_layer
{
class IUserIndication;
}

namespace app
{
class Blinky
{
   private:
    device_layer::IUserIndication* userIndication = nullptr;

   public:
    Blinky();
    void setUserIndication(device_layer::IUserIndication& init_user_indication);
    void run();
};

}  // namespace app

#endif  // BLINKY_HPP_
