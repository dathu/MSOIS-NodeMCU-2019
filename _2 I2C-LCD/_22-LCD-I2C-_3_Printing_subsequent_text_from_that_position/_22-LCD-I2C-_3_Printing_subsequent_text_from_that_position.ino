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
lcd.home(); //Positions the cursor in the upper-left of the LCD. 
              //That is, use that location in outputting subsequent text to the display. 
              //To also clear the display, use the clear() function instead.
  lcd.print("kkk");
}
