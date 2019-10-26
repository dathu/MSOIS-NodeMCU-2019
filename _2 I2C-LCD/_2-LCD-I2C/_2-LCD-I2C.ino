#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x3F,16,2); //PCF8754A
LiquidCrystal_I2C lcd(0x27,16,2); //PCF8754

void setup()
{
  lcd.begin();

  lcd.print("Hello World!");//(0,0)(Col,ROW)
  lcd.setCursor(0, 1);//(Col,ROW)
  lcd.print("Coding is cool!");

}


void loop()
{


}
