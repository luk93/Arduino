#include <SoftwareSerial.h>
#include <Servo.h>
#define bt_tx 10
#define bt_rx 11
#define led 6
#define button 2


SoftwareSerial bt = SoftwareSerial(bt_rx, bt_tx);

byte bits;
 
void setup() {
  pinMode(bt_rx, INPUT);
  pinMode(bt_tx, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600); 
  bt.begin(9600);
}
 
void loop() 
{
  if(digitalRead(button) == LOW)
  {
    digitalWrite(led, HIGH);
    bt.write('9');
  }
  if(digitalRead(button) == HIGH)
  {
    digitalWrite(led, LOW);
    bt.write('0');
  }
}




