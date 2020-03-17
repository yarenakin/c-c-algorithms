
#include <EEPROM.h>

int okunacakAdres, okunanVeri;
int eepromBellek;
int check=0;
int i=0;
int pot_value;



void setup() 
{
  
  pinMode(2,INPUT);
  
  Serial.begin(9600);
 
  eepromBellek = EEPROM.length();

  for (int i = 0 ; i < eepromBellek ; i++)
  {
   EEPROM.write(i, '\0');
  }
  
  EEPROM.write(0,90);
}

 
void loop()
{
    pot_value=analogRead(A0);
    pot_value =map( pot_value,0,1023,0,255);

  
   if(digitalRead(2)==1 && check==0)
     {
      
      if(  pot_value != EEPROM.read(i))
      {
        
      i++;
      EEPROM.write(i,pot_value);
      okunacakAdres=i;
      okunanVeri = EEPROM.read(okunacakAdres ); 
       
      Serial.print("EEPROMun ");
      Serial.print(okunacakAdres);
      Serial.print(" Adresindeki Deger= ");
      Serial.print(okunanVeri);
      Serial.println();
    
      }
     
     check++;
     
     if(i==eepromBellek)
    {
      Serial.println("ADRES KAPASITESI DOLDU");
      i=0;
    }
     
     }
  
    else if(digitalRead(2)==0) 
    {
      check=0;
    }
  
  
}
