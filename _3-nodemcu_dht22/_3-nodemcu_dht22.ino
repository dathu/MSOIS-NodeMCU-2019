#include "DHT.h"
DHT dht(14,DHT11); //D5 on board numbering system & 14 GPIO numbering system

void setup()
{
  Serial.begin(9600);
}


void loop()
{
Serial.println(" Temperature in c :");
Serial.println((dht.readTemperature( )));
Serial.print("Humidity in");
Serial.println((dht.readHumidity( )));
delay(2000);
}
