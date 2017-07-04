void setup() { 
  pinMode(6, OUTPUT); //Sygnał PWM silnika nr 1
  pinMode(7, OUTPUT); //Sygnały sterujące kierunkiem obrotów silnika nr 1
  pinMode(8, OUTPUT);
  
  digitalWrite(7, LOW); //Silnik nr 1 - obroty w lewo
  digitalWrite(8, HIGH);
} 
 
void loop()  { 
  for (int i = 0; i <= 255; i++) {
      analogWrite(6, i); //Spokojne rozpędzanie silnika
      delay(25);
  }
}
