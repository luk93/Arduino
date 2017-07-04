#define led 7
#define button 2

void setup() 
{
  pinMode(8, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600); 

}

void loop() {
  if(digitalRead(button) == LOW)
  {
    digitalWrite(8, HIGH);
    Serial.write("1");
  }
  if(digitalRead(button) == HIGH)
  {
    digitalWrite(8, LOW);
    Serial.write("0");
  }

}
