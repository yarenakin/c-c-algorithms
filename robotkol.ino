
#include <EEPROM.h>

int eepromBellek;

class pots
{
  public:
    int pot_value;
    int son_potVal;
    int pin;
    int okunacakAdres, okunanVeri;
    int check = 0;
    int check1=0;
    int i = 0;
    int vl = 0;
    int sayac;

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
      //Serial.println(pot_value);
    }

    void ayar()
    {

      analogReading();

      if (digitalRead(2) == 1 && check == 0 && check1==0)
      {

        if (pin == 14) sayac = 0;
        if (pin == 15) sayac = 100;
        if (pin == 16) sayac = 200;
        if (pin == 17) sayac = 300;


        if (son_potVal != EEPROM.read(i))
        {
          i = vl + sayac;
          EEPROM.write(i, son_potVal);
          okunacakAdres = i;
          okunanVeri = EEPROM.read(okunacakAdres );

          Serial.print("EEPROMun ");
          Serial.print(okunacakAdres);
          Serial.print(" Adresindeki Deger= ");
          Serial.print(okunanVeri);
          Serial.println();
          vl++;
        }


        check++;
        
        if(i>=eepromBellek && check1==0)
        {
          Serial.println("Adres Kapasitesi Doldu");
          check1=1;
        }

      }

      else if (digitalRead(2) == 0)
      {
        check = 0;
      }
    }


};



pots pot1(14);
pots pot2(15);
pots pot3(16);
pots pot4(17);

void setup()
{

  Serial.begin(9600);
  eeprom_reset();
  EEPROM.write(0, 90);
  EEPROM.write(1, 90);
}


void loop()
{
  pot1.ayar();
  pot2.ayar();
  pot3.ayar();
  pot4.ayar();
}


void eeprom_reset()
{
  eepromBellek = EEPROM.length();

  for (int i = 0 ; i < eepromBellek ; i++)
  {
    EEPROM.write(i, '\0');
  }
}
