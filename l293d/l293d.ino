void setup() { 
  pinMode(6, OUTPUT); //Sygnał PWM silnika nr 1  
  pinMode(7, OUTPUT); //Sygnały sterujące kierunkiem obrotów silnika nr 1
  pinMode(8, OUTPUT);
} 
 
void loop()  {  
  analogWrite(6,255);
  digitalWrite(7, LOW); //Silnik nr 1 - obroty w lewo
  digitalWrite(8, HIGH); 
  delay(3000);

  analogWrite(6,255);
  digitalWrite(7, HIGH); //Silnik nr 1 - obroty w prawo
  digitalWrite(8, LOW); 
  delay(3000);                          
}
