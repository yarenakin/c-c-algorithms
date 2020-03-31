
#include "robotkol.h"

pots pot1(A0);
pots pot2(A1);
pots pot3(A2);
pots pot4(A3);


void setup()
{
  Serial.begin(9600);
  eeprom_reset();

  EEPROM.write(0, 90);
  EEPROM.write(340, 90);
  EEPROM.write(680, 90);
  EEPROM.write(1020, 90);
}


void loop()
{
  pot1.regulation();
  pot2.regulation();
  pot3.regulation();
  pot4.regulation();

  //pot1.SerialDebug();
  pot2.SerialDebug();
  //pot3.SerialDebug();
  //pot4.SerialDebug();
}


void eeprom_reset()
{
  eepromMem = EEPROM.length();
  for (int i = 0 ; i < eepromMem ; i++) EEPROM.write(i, '\0');
}
