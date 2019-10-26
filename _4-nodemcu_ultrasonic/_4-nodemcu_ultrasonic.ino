
long ultrason_5() {
   long duration, distance;
   digitalWrite(5,LOW);
   delayMicroseconds(2);
   digitalWrite(5, HIGH);   
   delayMicroseconds(10);
   digitalWrite(5, LOW);
   duration = pulseIn(4, HIGH);
   distance = duration * 340 / (2 * 10000);
   return distance;
}

void setup()
{
  Serial.begin(9600);
pinMode(5, OUTPUT); // Trigger  Digital Pin  D1  (Board num 5)
pinMode(4, INPUT); // Echo Digital Pin  D2  (Board num 4)

}


void loop()
{

    Serial.print("Distance is ");
    Serial.print(ultrason_5());
    Serial.println(" cm");
    delay(1000);

}
