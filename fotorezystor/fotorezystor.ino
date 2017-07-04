int photoPin = 1;
int ledPin = 7;
int val = 0;
int led = 0;
 
void setup()
{
  pinMode(photoPin, INPUT); 
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  val = analogRead(photoPin);
  Serial.print("Odczyt:");
  Serial.println(val);
  Serial.print("Oswietlenie:");
  led = (1024 - val)/4;
  Serial.println(led);
  analogWrite(ledPin, led);
  delay(300);
}
