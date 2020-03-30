#include <EEPROM.h>

int eepromMem;

class pots
{
  private:

    int adres = 0;
    int readval;
    int check = 0;
    int echeck = 0;
    int vl = 0;
    int count;

  public:
    int pot_value;
    int last_potVal;
    int pin;


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

      if (digitalRead(2) == 1 && check == 0 && echeck == 0)
      {

        if (pin == A0) count = 1;

        else if (pin == A1) count = 340;

        else if (pin == A2) count = 680;

        else if (pin == A3) count = 1020;


        if (last_potVal != EEPROM.read(adres))
        {
          adres = vl + count;
          EEPROM.write(adres, son_potVal);
          readval = EEPROM.read(adres);

          Serial.print("EEPROMun ");
          Serial.print(adres);
          Serial.print(" Adresindeki Deger= ");
          Serial.print(readval);
          Serial.println();
          vl++;
        }

        check++;
      }

      else if (digitalRead(2) == 0) check = 0;


      else if (adres == eepromMem - 1 && echeck == 0)
      {
        Serial.println("ADRES KAPASITESI DOLDU");
        echeck = 1;
      }

    }
};
