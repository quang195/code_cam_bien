#include <ESP8266WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIGEER D5
#define ECHO D6

LiquidCrystal_I2C lcd(0x27, 16, 2);
byte heart[8] = {   
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b01110,
}; 
void hc_sr04();
void setup()
{
  Serial.begin(9600);
  pinMode(TRIGEER,OUTPUT);
  pinMode(ECHO, INPUT);
  lcd.init();                
  lcd.backlight();        
  lcd.home();               
  lcd.display(); 
  lcd.createChar(0, heart); 
}
void hc_sr04(){
  long duration;
  unsigned int distance;          
 digitalWrite(TRIGEER, LOW);
 delayMicroseconds(2);
 digitalWrite(TRIGEER, HIGH);
 delayMicroseconds(10);

 digitalWrite(TRIGEER, LOW);
 duration = pulseIn(ECHO, HIGH);
 distance = duration/2/29.412;  

  lcd.clear(); 
  lcd.setCursor(0,0); 
  lcd.print("distance: "); 
  lcd.print(distance);
  lcd.print(" Cm");
  
 
  lcd.setCursor(0,1);
  lcd.write(byte(0));
   delay(200);  
  lcd.setCursor(1,1);
  lcd.write(byte(0));
   delay(200);
  lcd.setCursor(2,1);
  lcd.write(byte(0));
  Serial.print(distance);
  Serial.printf("Cm");
  }
void loop()
{
 hc_sr04();
 delay(500);
}
