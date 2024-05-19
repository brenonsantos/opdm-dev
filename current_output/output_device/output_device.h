#ifndef OUTPUT_DEVICE_H
#define OUTPUT_DEVICE_H


#include "pdm_defs.h"


class OutputDevice {
public:
    typedef bool (*OutputControlCallback)(const OutputDevice* output);

    struct OutputDevicePwmConfig_st
    {
        uint16_t frequency;
        uint16_t dutyCycle;
        uint16_t softStart;
    };

    struct OutputDeviceConfig_st {
        uint16_t currentMaxContinuousLimit;
        uint16_t currentInrushLimit;
        uint16_t inrushTime;
        
        uint8_t fuseAutoRetryEnabled;
        uint8_t fuseRetries;
        uint16_t fuseRetryTime;

        uint8_t pwmEnable;
        OutputDevicePwmConfig_st pwmConfig;
        OutputControlCallback userControlCallback;
    };

    struct OutputHardwareCapabilities_st {
        uint8_t hasPWM:1;
        uint8_t hasTemperatureSensor:1;
        uint8_t hasVoltageSensor:1;
        uint8_t hasCurrentSensor:1;
        uint8_t reserved:4;

        uint16_t currentMaximum;
        uint16_t voltageMaximum;
        uint16_t temperatureMaximum;
        uint16_t voltageMinimum;
    };

    OutputDeviceConfig_st config;
    OutputHardwareCapabilities_st capabilities;

    virtual ~OutputDevice() = default;

    virtual void setConfig(const OutputDeviceConfig_st& config) = 0;
    virtual OutputDeviceConfig_st getConfig() const = 0;

    virtual void Activate() = 0;
    virtual void Deactivate() = 0;
    virtual uint8_t isActive() const = 0;

    virtual void setCurrentLimit(uint16_t limit) = 0;
    virtual uint16_t getCurrentLimit() const = 0;

    virtual OutputHardwareCapabilities_st getCapabilities() const = 0;

    virtual uint16_t getCurrentReading() const = 0;
    virtual uint16_t getVoltageReading() const = 0;
    virtual int16_t getTemperatureReading() const = 0;

    virtual uint8_t hasPWMSupport() const = 0;
    virtual void enablePWM() = 0;
    virtual void disablePWM() = 0;
    virtual void setPWMConfig(const OutputDevicePwmConfig_st& config) = 0;

    virtual void Process() = 0;

protected:
    struct OutputDynamic_st {
        uint16_t current;  
        uint16_t voltage;
        int16_t temperature;
        uint8_t fuseTripCount;
        uint8_t isFuseTripped;
    };
        OutputDynamic_st dynamic;
        OutputDevicePwmConfig_st pwmConfig;

}; 

#endif // OUTPUT_DEVICE_H