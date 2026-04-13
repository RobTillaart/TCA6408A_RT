#pragma once
//
//    FILE: TCA6408A.h
//  AUTHOR: Rob Tillaart
//    DATE: 2026-04-13
// VERSION: 0.1.0
// PURPOSE: Arduino library for
//     URL: https://github.com/RobTillaart/TCA6408A
//


#include "Arduino.h"
#include "Wire.h"


#define TCA6408A_LIB_VERSION         (F("0.1.0"))

//  ERROR CODES
//  values <> 0 are errors.
constexpr int TCA6408A_OK            = 0;
constexpr int TCA6408A_REQUEST_ERROR = -11;


class TCA6408A
{
public:
  TCA6408A(uint8_t address = 0x20, TwoWire *wire = &Wire);

  bool     begin();
  bool     isConnected();
  uint8_t  getAddress();


  //  1 = input 0 = output
  void     setPinMode8(uint8_t mask);
  uint8_t  getPinMode8();

  //  1 = inverted, 0 = not.
  void     setPolarity8(uint8_t mask);
  uint8_t  getPolarity8();

  //  core IO
  void     digitalWrite8(uint8_t mask);
  uint8_t  digitalRead8();
  void     digitalWrite1(uint8_t pin, uint8_t value);  //  HIGH LOW
  uint8_t  digitalRead1(uint8_t pin);

  //       DEBUG
  int      getLastError();


private:
  //  TODO clean up...
  uint8_t  _address = 0;
  TwoWire* _wire = NULL;

  uint8_t _IOMask = 0;

  int     _error = 0;

  int     writeRegister(uint8_t reg, uint8_t value);
  uint8_t readRegister(uint8_t reg);
};


//  -- END OF FILE --





