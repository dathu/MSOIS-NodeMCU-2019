#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int pos=0;
LiquidCrystal_I2C lcd(0x3F,16,2);

void setup()
{
  lcd.begin();

  lcd.print("Hello World!");


}


void loop()
{
  lcd.display();
  delay(500);
  lcd.noDisplay();
  delay(500);
}
