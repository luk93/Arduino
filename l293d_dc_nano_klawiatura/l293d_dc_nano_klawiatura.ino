#define pwn1 3
#define inp11 4
#define inp12 5 
#define photoPin 0

float predkosc_tmp = 0, predkosc_avg = 0, obwod_kola = 0.7536, odleglosc = 0;
String odebraneDane = "";
int licznik = 0, pomiar = 0, val = 0, avg= 0, pomiar_odleglosc=0, i=0;

int pwn1_wartosc = 100;

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
  else if(pomiar==1)
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

    if(odebraneDane == "silnik 1 lewo")
    {
      analogWrite(pwn1, pwn1_wartosc);
      digitalWrite(inp11, LOW); //Silnik nr 1 - lewo
      digitalWrite(inp12, HIGH);
      Serial.println("silnik 1 lewo");
    }
    if (odebraneDane == "silnik 1 prawo")
    {
      analogWrite(pwn1, pwn1_wartosc);
      digitalWrite(inp11, HIGH); //Silnik nr 1 - prawo
      digitalWrite(inp12, LOW);
      Serial.println("silnik 1 prawo");
    }

    if (odebraneDane == "silnik 1 stop")
    {
      analogWrite(pwn1, pwn1_wartosc);
      digitalWrite(inp11, LOW); //Silnik nr 1 - stop
      digitalWrite(inp12, LOW);
      Serial.println("silnik 1 stop");
    }
    if (odebraneDane == "silnik 1 predkosc 100")
    {
      pwn1_wartosc = 255;
      analogWrite(pwn1, pwn1_wartosc);
      Serial.println("Silnik 1 predkosc 100 procent ");
    }
    if (odebraneDane == "silnik 1 predkosc 50")
    {
      pwn1_wartosc = 128;
      analogWrite(pwn1, pwn1_wartosc);
      Serial.println("Silnik 1 predkosc 50 procent ");
    }
    if (odebraneDane == "silnik 1 predkosc 20")
    {
      pwn1_wartosc = 51;
      analogWrite(pwn1, pwn1_wartosc);
      Serial.println("Silnik 1 predkosc 20 procent ");
    }
    if (odebraneDane == "silnik 1 predkosc 30")
    {
      pwn1_wartosc = 76;
      analogWrite(pwn1, pwn1_wartosc);
      Serial.println("Silnik 1 predkosc 30 procent ");
    }
    if (odebraneDane == "silnik 1 predkosc 40")
    {
      pwn1_wartosc = 102;
      analogWrite(pwn1, pwn1_wartosc);
      Serial.println("Silnik 1 predkosc 40 procent ");
    }
    if(odebraneDane == "pomiar start")
    {
      pomiar_odleglosc = 1;
    }
    if(odebraneDane == "pomiar stop")
    {
      pomiar_odleglosc = 2;
    }
     
  }
}
ISR(TIMER1_COMPA_vect)         
{
 Serial.print(" Obroty na sekunde: ");
 Serial.print(licznik);
 Serial.print(" Predkosc : ");
 predkosc_tmp = obwod_kola*licznik;
 Serial.print(predkosc_tmp);
 Serial.print(" m/s ");
 Serial.println();
 predkosc_avg += predkosc_tmp;
 if(avg==4)   ///usrednianie co 5 s
 {
  predkosc_avg = predkosc_avg/5;
  Serial.print("Predkosc srednia: ");
  Serial.print(predkosc_avg);
  Serial.print(" m/s ");
  Serial.println();
  predkosc_avg=0;
  avg=-1;
 }
 if(pomiar_odleglosc==1)
 {
  if(i==0)
  {
    Serial.println("Pomiar odlegosci: START ");
    i=1;
  }  
  odleglosc = odleglosc + predkosc_tmp;
 }
 if(pomiar_odleglosc==2)
 {
  Serial.println(" Odleglosc: ");
  Serial.print(odleglosc);
  Serial.print(" m ");
  odleglosc=0;
  pomiar_odleglosc = 0;
  i=0;
 }
 licznik=0; 
 avg++;
}

