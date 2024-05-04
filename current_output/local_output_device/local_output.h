// CurrentOutput.h (Header file)

#ifndef LOCAL_OUTPUT_H
#define LOCAL_OUTPUT_H

#include "hbl_defs.h";
#include "output_device.h";

class LocalCurrentOutput : public OutputDevice {
private:

    gpio_pin_config_st pinConfig; 
    uint8_t active;

public:
    LocalCurrentOutput(); // Constructor

    void Activate() override;
    void Deactivate() override;
    uint8_t isActive() const override;

    // Methods for configuration, measurements, etc. as per your OutputDevice interface    
    // ...
};


#endif // LOCAL_OUTPUT_H