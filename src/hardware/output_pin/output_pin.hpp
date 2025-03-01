#ifndef OUTPUT_PIN_HPP
#define OUTPUT_PIN_HPP

#include <stdint.h>
#include "i_output_pin.hpp"

class OutputPin : public IOutputPin
{
   public:
    enum class Port : uint8_t
    {
  
    };

    enum class Pin : uint16_t
    {
       
    };

    enum class Mode : uint8_t
    {
   
    };

    enum class Pull : uint8_t
    {
       
    };

    enum class Speed : uint8_t
    {
    
    };

   private:
    Port port;
    Pin pin;
    Mode mode;
    Pull pull;
    Speed speed;

   public:
    OutputPin();
    ~OutputPin();
    void configure(Port initPort, Pin initPin, Mode initMode, Pull initPull,
                   Speed initSpeed);
    void set() override;
    void reset() override;
};

#endif  // OUTPUT_PIN_HPP