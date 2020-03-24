
#include <EEPROM.h>

int okunacakAdres, okunanVeri,okunacakAdres2, okunanVeri2;
int eepromBellek;
int check=0;
int i=0,j=0;
int pot_value;
int pot2_value;
int vl=0;





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
  EEPROM.write(1,90);
}

 
void loop()
{
  
   
  
    pot_value=analogRead(A0);
    pot_value =map(pot_value,0,1023,0,255);
  
    pot2_value=analogRead(A1);
    pot2_value =map( pot2_value,0,1023,0,255);

  
   if(digitalRead(2)==1 && check==0)
     {
      if(pot_value != EEPROM.read(i))
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
     
      if(pot2_value != EEPROM.read(j))
      {
        
      j=vl+100;
      EEPROM.write(j,pot2_value);
      okunacakAdres2=j;
      okunanVeri2 = EEPROM.read(okunacakAdres2); 
       
      Serial.print("EEPROMun ");
      Serial.print(okunacakAdres2);
      Serial.print(" Adresindeki Deger= ");
      Serial.print(okunanVeri2);
      Serial.println();
      vl++;
        
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
