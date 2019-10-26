void setup()
{
pinMode(0, INPUT); //PIR Sensor
pinMode(2, OUTPUT); // Onboard LED
}


void loop()
{

    if (1 == digitalRead(0))
    {
      for (int count = 0; count < 2; count++) 
      {
        digitalWrite(2,HIGH);
        delay(500);
        digitalWrite(2,LOW);
        delay(500);
      }

    }

}
