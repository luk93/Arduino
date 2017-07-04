#define pwn1 3
#define inp11 4
#define inp12 5 
#define photoPin 0

float obwod_kola = 0.7536;
int val = 0;
String odebraneDane = "";
int pwn1_wartosc = 100;
int licznik = 0;
int pomiar = 0;

void setup()
{
  Serial.begin(9600);       //Uruchomienie komunikacji przez UART
  //timer
  noInterrupts();           //uniemozliw przerwania
  TCCR1A = 0;               
  TCCR1B = 0;
  TCNT1  = 0;               // wartosc wstepna = 0
  OCR1A = 62500;            // wartosc do porownania (zeby wyszla 1s)
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS12);    // 256 preskaler 
  TIMSK1 |= (1 << OCIE1A);  // umozliw przerwania timera
  interrupts();             // umozliw przerwania
  
  pinMode(pwn1, OUTPUT);    //Sygnał PWM silnika nr 1
  pinMode(inp11, OUTPUT);   //Sygnały sterujące kierunkiem obrotów silnika nr 1
  pinMode(inp12, OUTPUT);
  
  pinMode(photoPin, INPUT); 
  
  digitalWrite(inp11, LOW); //Silnik nr 1 - stop
  digitalWrite(inp12, LOW);
}

void loop()
{
  silniki();
  pomiar_predkosc();
    
}

int pomiar_fotorezystor()
{
  val = analogRead(photoPin);
  delay(1);
  return val;
}
void pomiar_predkosc()
{
  if(pomiar==0)
  {
    if(pomiar_fotorezystor()>960)
    {
      pomiar=1;
    }
  }  
  if(pomiar==1)
  {
    if(pomiar_fotorezystor()<960)
    {
      licznik+=1;
      pomiar=0;
    }
  }
}
void silniki()
{
  if (Serial.available() > 0)
  { //Czy Arduino odebrano dane
    //Jeśli tak, to odczytujemy je do znaku końca linii i zapisz w zmiennej odebraneDane
    odebraneDane = Serial.readStringUntil('\n');

    switch(odebraneDane)
    {
      case "silnik":
      analogWrite(pwn1, pwn1_wartosc);
      digitalWrite(inp11, LOW); //Silnik nr 1 - lewo
      digitalWrite(inp12, HIGH);
      Serial.println("silnik 1 lewo");
      break;

  }
}
}
ISR(TIMER1_COMPA_vect)         
{
 Serial.print(" Obroty na sekunde: ");
 Serial.print(licznik);
 Serial.print(" Predkosc : ");
 Serial.print(obwod_kola*licznik);
 Serial.print(" m/s ");
 Serial.println();
 licznik=0; 
}

