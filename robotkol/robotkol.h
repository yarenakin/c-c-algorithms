#include <EEPROM.h>

int eepromMem;

class pots
{
  private:

    int adres = 0;
    int readval;
    int check = 0;
    int echeck = 0;
    int tcheck = 0;
    int vl = 0;
    int count;
    int go;
    int pot_value;
    int last_potVal;
    int pin;

  public:

    pots(int pinNumber)
    {
      pinMode(pinNumber, INPUT);
      pin = pinNumber;
    }

    void analogReading()
    {
      pot_value = analogRead(pin);
      pot_value = map(pot_value, 0, 1023, 0, 255);
      last_potVal = pot_value;
    }


    void regulation()
    {

      
      analogReading();

      if (pin == A0) count = 1;
      else if (pin == A1)count = 250;
      else if (pin == A2) count = 500;
      else if (pin == A3) count = 750;
     
      if (adres == count + 249) go = 1;

      
      if (digitalRead(2) == 1 && check == 0 && echeck == 0)
      {

        if (last_potVal != EEPROM.read(adres) && go == 0)
        {
          
          digitalWrite(5, HIGH);
          adres = vl + count;
          EEPROM.write(adres, last_potVal);
          vl++;
          
        }

        check++;
        
      }

      else if (digitalRead(2) == 0) check = 0;

      
      if (adres == eepromMem - 1 && echeck == 0)   echeck = 1;
      
    }


    void SerialDebug()
    {
      if (digitalRead(13) == 1 && tcheck == 0)
      {
        for (int j = count; j < adres; j++)
        {
          Serial.print("EEPROMun ");
          Serial.print(j);
          Serial.print(" Adresindeki Deger= ");
          Serial.print(EEPROM.read(j));
          Serial.println();
          Serial.println("NOW");
        }

        tcheck++;
      }

      if (digitalRead(13) == 0) tcheck = 0;

    }


};
