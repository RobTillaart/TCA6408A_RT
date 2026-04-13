//
//    FILE: TCA6408A_demo2.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: test basic behaviour and performance
//     URL: https://github.com/RobTillaart/TCA6408A


#include "TCA6408A.h"


TCA6408A tca(0x40);


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(__FILE__);
  Serial.print("TCA6408A_LIB_VERSION: ");
  Serial.println(TCA6408A_LIB_VERSION);
  Serial.println();

  Wire.begin();
  Wire.setClock(400000);

  if (tca.begin() == false)
  {
    Serial.println("No TCA found.");
    while (1);
  }

  //  Set all as inputs, 0xFF
  tca.setPinMode8(0xFF);

  //  Invert INPUT polarity so pressing button == 1
  tca.setPolarity8(0xFF);

  Serial.print(millis());
  Serial.println(": config done..");
}


void loop(void)
{
  Serial.print("INPUT: ");
  for (int pin = 7; pin > -1; pin--)
  {
    Serial.print(tca.digitalRead1(pin));
  }
  Serial.println();

  delay(2000);
}


//  -- END OF FILE --
