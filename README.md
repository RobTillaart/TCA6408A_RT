
[![Arduino CI](https://github.com/RobTillaart/TCA6408A/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/TCA6408A/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/TCA6408A/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/TCA6408A/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/TCA6408A/actions/workflows/jsoncheck.yml)
[![GitHub issues](https://img.shields.io/github/issues/RobTillaart/TCA6408A.svg)](https://github.com/RobTillaart/TCA6408A/issues)

[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/TCA6408A/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/TCA6408A.svg?maxAge=3600)](https://github.com/RobTillaart/TCA6408A/releases)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/robtillaart/library/TCA6408A.svg)](https://registry.platformio.org/libraries/robtillaart/TCA6408A)


# TCA6408A

Arduino library for TCA6408A I2C 8 bits IO expander.


## Description

**Experimental - Work in progress.**

This library is to use TCA6408A .

The TCA6408A has a RESET pin to reset the device (TODO investigate).

The TCA6408A supports interrupts (TODO investigate).


As always, feedback is welcome.


### Hardware

```
TODO elaborate
```

|  pin  |   name   |  description      |  Notes  |
|:-----:|:--------:|:------------------|:-------:|
|   1   |  SDA/RX  |  I2C data         |  3-5V
|   2   |  SCL/TX  |  I2C clock        |  3-5V
|   3   |  GND     |  Ground           |
|   4   |  VCC     |  Power +5V        |   
|   5   |          |     |   
|   6   |   -      |       |



### Related

- https://github.com/RobTillaart/TCA6408A - 8 bits I2C IO expander
- https://github.com/RobTillaart/PCF8574 - 8 bits I2C IO expander
- https://github.com/RobTillaart/PCF8575 - 16 bits I2C IO expander


### Tested

TODO: Test on Arduino UNO and ESP32


## I2C

### I2C Address


The device has one address pin to set address 0x20 or 0x21.


### I2C multiplexing

Sometimes you need to control more devices than possible with the default
address range the device provides.
This is possible with an I2C multiplexer e.g. TCA9548 which creates up 
to eight channels (think of it as I2C subnets) which can use the complete 
address range of the device. 

Drawback of using a multiplexer is that it takes more administration in 
your code e.g. which device is on which channel. 
This will slow down the access, which must be taken into account when
deciding which devices are on which channel.
Also note that switching between channels will slow down other devices 
too if they are behind the multiplexer.

- https://github.com/RobTillaart/TCA9548


### I2C Performance

|  Clock     |  time (us)  |  Notes  |
|:----------:|:-----------:|:--------|
|   100 KHz  |             |  default 
|   200 KHz  |             |
|   300 KHz  |             |
|   400 KHz  |             |


TODO: create and run performance sketch on hardware.


## Interface

```cpp
#include "TCA6408A.h"
```

### Constructor

- **TCA6408A(uint8_t address, TwoWire \*wire = &Wire)** optional select I2C bus.
- **bool begin()** checks if device is visible on the I2C bus.
- **bool isConnected()** Checks if device address can be found on I2C bus.
- **uint8_t getAddress()** Returns the address configured in constructor (convenience).

### PinMode8

- **void setPinMode8(uint8_t mask)** per bit 1 = input 0 = output.
- **uint8_t getPinMode8()** returns set mask.

### Polarity

- **void setPolarity8(uint8_t mask)** per bit 1 = inverted, 0 = not.
- **uint8_t getPolarity8()** returns set mask.

### Core IO

- **void digitalWrite8(uint8_t mask)** write all pins at once.
- **uint8_t digitalRead8()** read all pins at once.
- **void digitalWrite1(uint8_t pin, uint8_t value)** pin = 0..7, HIGH / LOW
- **uint8_t digitalRead1(uint8_t pin)** pin = 0..7

### Debug

- **int getLastError()** returns last error of low level communication.


## Future

#### Must

- improve documentation
- validate implementation per function.

#### Should

- investigate RESET
- investigate INTERRUPTS
- improve error handling

#### Could

- add examples
- add unit tests ?

#### Wont


## Support

If you appreciate my libraries, you can support the development and maintenance.
Improve the quality of the libraries by providing issues and Pull Requests, or
donate through PayPal or GitHub sponsors.

Thank you,


