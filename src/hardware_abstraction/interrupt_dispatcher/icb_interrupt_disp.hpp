#ifndef ICB_INTERRUPT_DISP
#define ICB_INTERRUPT_DISP

namespace hardware_layer
{
class IcbIntDispatcher
{
   public:
    virtual void notifyInterruptService(void) = 0;
};

}  // namespace hardware_layer

#endif