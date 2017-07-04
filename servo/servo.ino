#include <Servo.h>
#define d1 7
#define pot 5
#define serv 8
Servo servo;

int odczyt_pot;
byte kat_serv;

void setup()
{
  pinMode(d1, OUTPUT);
  Serial.begin(9600);
  servo.attach(serv);
}

void loop()
{
  odczyt_pot = analogRead(pot);
  kat_serv = map(odczyt_pot, 0, 1023, 0, 180);
  servo.write(kat_serv);
  Serial.println(odczyt_pot);
  delay(20);
  if(odczyt_pot==0){
  digitalWrite(d1, HIGH);
  Serial.print("dioda");}
  else digitalWrite(d1, LOW);
  }

