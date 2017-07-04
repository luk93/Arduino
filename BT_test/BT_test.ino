#include <SoftwareSerial.h>
#define bt_tx 10
#define bt_rx 11
#define led 6

String stringInput = "";
int intInput = 0;

SoftwareSerial bt = SoftwareSerial(bt_rx, bt_tx);
 
void setup() {
  pinMode(bt_rx, INPUT);
  pinMode(bt_tx, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600); 
  bt.begin(9600);
}
 
void loop() 
{
  // listen for the data
  if (bt.available() > 0 ) 
  {
    stringInput = bt.read(); 
    Serial.println(stringInput);   
  }
  intInput = stringInput.toInt();
  ledBright(intInput);
}
void ledBright(int in)
{
  analogWrite(led, in);
}


