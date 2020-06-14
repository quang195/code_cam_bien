#include <ESP8266WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int n;
void setup(){
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.home();
  lcd.display();
  }
void loop() {
 int value = analogRead(A0);   
   
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Gas: ");
  lcd.print (value);  
  Serial.println(value); 
 delay(1000);           
}
