//
//    FILE: TCA6408A.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2026-04-13
// VERSION: 0.1.0
// PURPOSE: Arduino library for TCA6408A
//     URL: https://github.com/RobTillaart/TCA6408A



#include "TCA6408A.h"

constexpr uint8_t TCA6408A_REG_INPUT    = 0x00;
constexpr uint8_t TCA6408A_REG_OUTPUT   = 0x01;
constexpr uint8_t TCA6408A_REG_POLARITY = 0x02;
constexpr uint8_t TCA6408A_REG_CONFIG   = 0x03;


TCA6408A::TCA6408A(uint8_t address, TwoWire *wire)
{
  _address = address;
  _wire = wire;
  _error = TCA6408A_OK;
}


bool TCA6408A::begin()
{
  //  reset variables
  _error = TCA6408A_OK;

  if (! isConnected())
  {
    return false;
  }
  return true;
}


bool TCA6408A::isConnected()
{
  _wire->beginTransmission(_address);
  return (_wire->endTransmission() == 0);
}


uint8_t TCA6408A::getAddress()
{
  return _address;
}


/////////////////////////////////////////////
//
//  PINMODE
//
void TCA6408A::setPinMode8(uint8_t mask)
{
  writeRegister(TCA6408A_REG_CONFIG, mask);
  _IOMask = mask;
  //  TODO error propagation
}

uint8_t TCA6408A::getPinMode8()
{
  // return _IOMask; ???
  uint8_t mask = readRegister(TCA6408A_REG_CONFIG);
  return mask;
}


/////////////////////////////////////////////
//
//  POLARITY
//
void TCA6408A::setPolarity8(uint8_t mask)
{
  writeRegister(TCA6408A_REG_POLARITY, mask);
  //  TODO error propagation
}

uint8_t TCA6408A::getPolarity8()
{
  uint8_t mask = readRegister(TCA6408A_REG_POLARITY);
  return mask;
}


/////////////////////////////////////////////
//
//  READ-WRITE
//
void TCA6408A::digitalWrite8(uint8_t mask)
{
  writeRegister(TCA6408A_REG_OUTPUT, mask);
  //  TODO error propagation
}


uint8_t TCA6408A::digitalRead8()
{
  uint8_t mask = readRegister(TCA6408A_REG_INPUT) & _IOMask;
  return mask;
}


/////////////////////////////////////////////
//
//  DEBUG
//
int TCA6408A::getLastError()
{
  int e = _error;
  _error = TCA6408A_OK;
  return e;
}


///////////////////////////////////////////////
//
//  PRIVATE
//
int TCA6408A::writeRegister(uint8_t reg, uint8_t value)
{
  Wire.beginTransmission(_address);
  Wire.write(reg);
  Wire.write(value);
  int n = Wire.endTransmission();
  if (n != 0)
  {
    _error = n;
  }
  return n;
}


uint8_t TCA6408A::readRegister(uint8_t reg)
{
  Wire.beginTransmission(_address);
  Wire.write(reg);
  Wire.endTransmission(false);
  int n = Wire.requestFrom(_address, (uint8_t)1);
  if (n != 1)
  {
    _error = TCA6408A_REQUEST_ERROR;
    return 0xFF;
  }
  return Wire.read();
}


//  -- END OF FILE --

