#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c expander i/o class header

hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip

// LCD geometry
const int LCD_ROWS = 2;
const int LCD_COLS = 16;

void setup()
{
	// initialize LCD with number of columns and rows: 
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.setCursor(0,0);
  lcd.print("Jednak dziala!");
  lcd.setCursor(0,1);
  lcd.print("Grigori ma farta :D");
}

void loop()
{
  
}
