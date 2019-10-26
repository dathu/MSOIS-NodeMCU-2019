int pir=13; //GPIO 13 (D7)
int pirvalue;
void setup()
{
Serial.begin(9600);
}


void loop()
{
pirvalue=digitalRead(pir);
if (pirvalue==1)
{
  Serial.println("Object detected");
}
else
{
  Serial.println("Object is not detected");
}
delay(1000);
}
  
