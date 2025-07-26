//============================================================================
// Blinky example
//============================================================================

#ifndef BLINKY_HPP_
#define BLINKY_HPP_

class IUserIndication;

namespace app
{
class Blinky
{
   private:
    IUserIndication* userIndication = nullptr;

   public:
    Blinky();
    void setUserIndication(IUserIndication& init_user_indication);
    void run();
};

}  // namespace app

#endif  // BLINKY_HPP_
