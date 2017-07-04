#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_SR.h>
#include <LiquidCrystal_SR2W.h>
#include <LiquidCrystal_SR3W.h>

#include <time.h>

#define gaz       2
#define enkoder   5
#define ImpNaObr  1
#define CentNaObr 113
struct GLOBAL_FLAGS {
  uint8_t timer : 1;


} gFlags;

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

unsigned long czas = 0;
uint32_t v;
uint16_t odleglosc = 0, metry = 0;
uint8_t moc = 0;
void setup() {
  // put your setup code here, to run once:
  TCCR1B |= (1 << CS12) | (1 << CS11) | (1 << CS10);
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Shell  ECO");
  lcd.setCursor(4, 1);
  lcd.print("MARATHON");
  pinMode(gaz, INPUT);
  pinMode(enkoder, INPUT);
  delay(1000);
}

void loop() {

  if  (millis() >= czas)
  {
    lcd.clear();
    czas = millis() + 1000;
    gFlags.timer = 0;
    v = TCNT1;
    TCNT1 = 0;
    v *= 10;            //mnozymy razy dziesiec, ilosc obrotow z dziesietna czescia
    v /= ImpNaObr;      //z impulsow na obroty, wynik / 10
    lcd.setCursor(0, 0);
    lcd.print("obr : ");
    lcd.print(v / 10);
    lcd.print(".");
    lcd.print(v % 10);
    if (digitalRead(gaz))
    {
      if (moc == 0) moc = 26;
      else if (moc <= 250) moc += 5;

    }
    else moc = 0;
    analogWrite(3, moc);
    lcd.setCursor(0, 1);
    lcd.print((moc * 100) / 255);
  }
}
