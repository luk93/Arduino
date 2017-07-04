#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h> 
#include <time.h>

struct GLOBAL_FLAGS 
{
    uint8_t timer : 1;
} gFlags;

hd44780_I2Cexp lcd; // deklaracja obiektu lcd: autolokacja i konfiguracja chipu i2c

// rozmiary lcd
const int LCD_ROWS = 2;
const int LCD_COLS = 16;
unsigned long ul_time = 0;
int counter = 1;

void setup()
{
  Serial.begin(9600);
  TCCR1B |= (1 << CS12) | (1 << CS11) | (1 << CS10);
  lcd.begin(LCD_COLS, LCD_ROWS);
}

void loop()
{
  if  (millis() >= ul_time)
  {
    if(counter==1)
    {  
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Shell           ");
      lcd.setCursor(0,1);
      lcd.print("Eco-Marathon    ");
      Serial.println("Shell eco");
    }
     if(counter==2)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("     London     ");
      lcd.setCursor(0,1);
      lcd.print("      2017      ");
      Serial.println("london 2017");
    }  
    if(counter==3)
    {  
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("      ELVIC    ");
      lcd.setCursor(0,1);
      lcd.print("      TEAM      ");
      Serial.println("elvic team");
    }  
    if(counter==3)
    {
      counter=1;
    }
    else counter++;
    ul_time = millis() + 5000;
    gFlags.timer = 0;
  }
    
}
