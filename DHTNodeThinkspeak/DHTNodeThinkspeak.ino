#include <DHT.h>  
 #include <ESP8266WiFi.h>  
 #include <WiFiClient.h>  
 #include <ThingSpeak.h> 
 #include <Adafruit_Sensor.h> 
 #define DHTPIN 14  //D5
 #define DHTTYPE DHT11   
 DHT dht(DHTPIN, DHTTYPE);  
 const char* ssid = "dilse";  
 const char* password = "12340987";  
 WiFiClient client;  
 unsigned long myChannelNumber = 856304;  
 const char * myWriteAPIKey = "JYKNNHKU61OK0EP8";  
 uint8_t temperature, humidity;  
 void setup()  
 {  
  Serial.begin(9600);  
  dht.begin();  
  delay(10);  
  // Connect to WiFi network  
  Serial.println();  
  Serial.println();  
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED)  
  {  
   delay(500);  
   Serial.print(".");  
  }  
  Serial.println("");  
  Serial.println("WiFi connected");  
  // Print the IP address  
  Serial.println(WiFi.localIP());  
  ThingSpeak.begin(client);  
 }  
 void loop()   
 {  
  static boolean data_state = false;  
  temperature = dht.readTemperature();  
  humidity = dht.readHumidity();  
  Serial.print("Temperature Value is :");  
  Serial.print(temperature);  
  Serial.println("C");  
  Serial.print("Humidity Value is :");  
  Serial.print(humidity);  
  Serial.println("%");  
  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different  
  // pieces of information in a channel. Here, we write to field 1.  
  if( data_state )  
  {  
   ThingSpeak.writeField(myChannelNumber, 1, temperature, myWriteAPIKey);  
   data_state = false;  
  }  
  else  
  {  
   ThingSpeak.writeField(myChannelNumber, 2, humidity, myWriteAPIKey);  
   data_state = true;  
  }  
  delay(3000); // ThingSpeak will only accept updates every 15 seconds.  
 }  

//http://embeddedlaboratory.blogspot.in/2016/10/posting-dht11-values-to-thingspeak.html
 
