
#include <EEPROM.h>

int eepromBellek;

class pots
{
  private:

    int adres = 0;
    int okunanVeri;
    int check = 0;
    int echeck = 0;
    int vl = 0;
    int count;

  public:
    int pot_value;
    int son_potVal;
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
      son_potVal = pot_value;
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


        if (son_potVal != EEPROM.read(adres))
        {
          adres = vl + count;
          EEPROM.write(adres, son_potVal);
          okunanVeri = EEPROM.read(adres);

          Serial.print("EEPROMun ");
          Serial.print(adres);
          Serial.print(" Adresindeki Deger= ");
          Serial.print(okunanVeri);
          Serial.println();
          vl++;
        }

        check++;
      }

      else if (digitalRead(2) == 0) check = 0;


      else if (adres == eepromBellek - 1 && echeck == 0)
      {
        Serial.println("ADRES KAPASITESI DOLDU");
        echeck = 1;
      }

    }
};


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
}


void eeprom_reset()
{
  eepromBellek = EEPROM.length();
  for (int i = 0 ; i < eepromBellek ; i++) EEPROM.write(i, '\0');
}
