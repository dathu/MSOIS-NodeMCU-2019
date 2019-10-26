#define BLYNK_PRINT Serial    
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

// You should get Auth Token in the Blynk App.

char auth[] = "gMEoPtIA4Eclgd17a5SxfZp-DbNLVuab";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "dilse";
char pass[] = "12340987";

#define DHTPIN 4          // What digital pin we're connected to D2

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;

#define relay 14  //digital pin D5


void sendSensor()
{
   // Reading Temperature and Humidity value // 
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
 
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
  
 // Taking actions
// Temperature (t) is greater than the condition , Turn ON FAN (Relay) 

if(t> 27)
{
 digitalWrite(relay,LOW);
}
if(t <= 27)
{
 digitalWrite(relay,HIGH);
}
 
}

void setup()
{
  Serial.begin(9600); // See the connection status in Serial Monitor
  Blynk.begin(auth, ssid, pass);

  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
  pinMode(relay,OUTPUT);
}

void loop()
{
  Blynk.run(); // Initiates Blynk
  timer.run(); // Initiates SimpleTimer
}
