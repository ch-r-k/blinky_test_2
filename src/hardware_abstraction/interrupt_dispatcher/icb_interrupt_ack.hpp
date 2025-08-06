#ifndef ICB_INTERRUPT_ACK
#define ICB_INTERRUPT_ACK

namespace hardware_layer
{
class IcbIntAcknowledge
{
   public:
    virtual void notifyInterruptAcknowledge(void) = 0;
};

}  // namespace hardware_layer

#endif