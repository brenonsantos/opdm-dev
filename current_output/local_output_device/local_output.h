// CurrentOutput.h (Header file)

#ifndef LOCAL_OUTPUT_H
#define LOCAL_OUTPUT_H

#include "hbl_defs.h";
#include "output_device.h";

class LocalOutput : public OutputDevice {
private:

    gpio_pin_config_st pinConfig; 
    uint8_t active;

public:
    LocalOutput(); // Constructor

    LocalOutput(const gpio_pin_config_st& pinConfig, 
                const OutputDeviceConfig_st& initialConfig,
                const OutputHardwareCapabilities_st& hardwareCaps);

    void Activate() override;
    void Deactivate() override;
    uint8_t isActive() const override;
};


#endif // LOCAL_OUTPUT_H