#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int pos=0;
LiquidCrystal_I2C lcd(0x3F,16,2);

void setup()
{
  lcd.begin();

}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.autoscroll();
  lcd.print("ABC");
  delay(2000);
}
//This function takes a string of text and scrolls it from right to left in increments of the character count of the string.
//For example, if you have a string of text that is 3 characters long, it will shift the text 3 spaces to the left with each step
