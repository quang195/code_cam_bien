#include <ESP8266WiFi.h>
#include "DHT.h"

#define DHTTYPE DHT11
#define dht_dpin D2
DHT dht(dht_dpin, DHTTYPE);

void setup()
{
    Serial.begin(9600);
    dht.begin();
}
void loop(){
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
 Serial.print("nhietdo:");
 Serial.println(t);
 Serial.print("doam:");
 Serial.println(h);
 delay(500);
                
}
