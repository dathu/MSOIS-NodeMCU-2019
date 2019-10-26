#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int pos=0;
//LiquidCrystal_I2C lcd(0x3F,16,2);
LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  lcd.begin();

  lcd.print("Hello World!");


}


void loop()
{
for(pos=0; pos<2; pos++)  
  {
//lcd.scrollDisplayLeft();    //scrolls display left by two positions
lcd.scrollDisplayRight();    //scrolls display Right by two positions
  } 
delay(1000);
}
