
void setup()
{
  
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  
  int pot=analogRead(A0);
 int sonuc=(pot)/100;
  Serial.print(pot);
  Serial.print("****");
  Serial.println(sonuc*25);
  analogWrite(10,sonuc*25);
  

 
}
