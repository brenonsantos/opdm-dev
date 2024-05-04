
#ifndef GPIO_H
#define GPIO_H

#include "hbl_defs.h"

struct gpio_pin_config_st {
    uint8_t pinNumber;
    gpio_port_t port;
    gpio_pin_mode_t mode;
};

typedef enum
{
    INPUT_ANALOG,
    INPUT_FLOAT,
    INPUT_PULLUP,
    INPUT_PULLDOWN,
    OUTPUT_PUSHPULL,
    OUTPUT_OPENDRAIN,
    PIN_TYPE_NUM
} gpio_pin_mode_t;

typedef enum
{
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF,
    PORT_NUM,
    PORT_NULL = 255,
} gpio_port_t;


#endif // GPIO_H