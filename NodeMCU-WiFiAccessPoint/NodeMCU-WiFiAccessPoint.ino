
/* Create a WiFi access point and provide a web server on it. */

#include <ESP8266WiFi.h>
//#include <WiFiClient.h>

#ifndef APSSID
#define APSSID "NodeMCU-MSOIS-AP"
#endif

/* Set these to your desired credentials. */
const char *ssid = APSSID;

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid); //Creating the Soft ACCESS Point
  IPAddress myIP = WiFi.softAPIP(); // Getting IP address of the SOFT-AP
  Serial.print("AP IP address: ");
  Serial.println(myIP);
}

void loop() {

}
