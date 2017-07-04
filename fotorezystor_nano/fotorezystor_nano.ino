int photoPin = 0;
int val = 0;
 
void setup()
{
  pinMode(photoPin, INPUT); 
  Serial.begin(9600);
}
 
void loop()
{
  val = analogRead(photoPin)/128;
  Serial.println(val);
  delay(30);
}
