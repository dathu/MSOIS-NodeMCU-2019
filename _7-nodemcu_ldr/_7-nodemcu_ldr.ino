int ldr=A0; 
int ldrvalue;
int led = 4;
void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}


void loop()
{
ldrvalue=analogRead(ldr);
Serial.println(ldrvalue);
if (ldrvalue<400) 
{
digitalWrite(led, HIGH);
} 
else 
{
digitalWrite(led, LOW);
}
delay(1000);

}
