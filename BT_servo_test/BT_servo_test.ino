#include <SoftwareSerial.h>
#include <Servo.h>
#define bt_tx 10
#define bt_rx 11
#define servoPin 6


SoftwareSerial bt = SoftwareSerial(bt_rx, bt_tx);
Servo servo;

char command;
String string;
boolean servo_angle = 0;
byte bits;
 
void setup() {
  pinMode(bt_rx, INPUT);
  pinMode(bt_tx, OUTPUT);
  servo.attach(servoPin);
  Serial.begin(9600); 
  bt.begin(9600);
}
 
void loop() 
{
  listenForData();
}
void listenForData()
{
// listen for the data
  if (bt.available() > 0 ) 
  {
    string = "";
  }
  while (bt.available() > 0)
  {
    command = ((byte)bt.read());
    if (command == ":")
    {
      break;   
    }
    else
    {
      string += command;
    }
    delay(1);
  }
  if(string == "ZERO")
  {
    servo.write(0);
    delay(10);
  }
  if(string == "MAX")
  {
    servo.write(180);
    delay(10);
  }
  if ((string.toInt()>=0)&&(string.toInt()<=180))
  {
      servo.write(string.toInt());
  }
}


