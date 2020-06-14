#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include "RTClib.h"
 
LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS1307 RTC;
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
void setup(){
  Wire.begin();
  RTC.begin();
  delay(500);
  RTC.adjust(DateTime(__DATE__,__TIME__));
  delay(1000);
  Serial.begin(115200);
  lcd.init();                
  lcd.backlight();        
  lcd.home();               
  lcd.display();  
  }
  void loop(){
  DateTime now = RTC.now(); 
    lcd.setCursor(4, 1);
    if(now.hour()<=9)
    {
      lcd.print("0");
      lcd.print(now.hour());
    }
    else {
     lcd.print(now.hour()); 
    }
    lcd.print(':');
    if(now.minute()<=9)
    {
      lcd.print("0");
      lcd.print(now.minute());
    }
    else {
     lcd.print(now.minute()); 
    }
    lcd.print(':');
    if(now.second()<=9)
    {
      lcd.print("0");
      lcd.print(now.second());
    }
    else {
     lcd.print(now.second()); 
    }
    lcd.print("   ");

    lcd.setCursor(1, 0);
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    lcd.print(",");
    if(now.day()<=9)
    {
      lcd.print("0");
      lcd.print(now.day());
    }
    else {
     lcd.print(now.day()); 
    }
    lcd.print('/');
    if(now.month()<=9)
    {
      lcd.print("0");
      lcd.print(now.month());
    }
    else {
     lcd.print(now.month()); 
    }
    lcd.print('/');
  
    lcd.print(now.year()); 
   
}


  
