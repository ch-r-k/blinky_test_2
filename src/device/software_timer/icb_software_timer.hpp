#ifndef ICB_SOFTWARE_TIMER
#define ICB_SOFTWARE_TIMER

class IcbSoftwareTimer
{
   public:
    ~IcbSoftwareTimer() = default;
    virtual void notify() = 0;
};

#endif