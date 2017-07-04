#define d1 2
#define d2 3
 
String odebraneDane = ""; //Pusty ciąg odebranych danych
 
void setup() {
  Serial.begin(9600); //Uruchomienie komunikacji
  pinMode(d1, OUTPUT); //Konfiguracja wyjść
  pinMode(d2, OUTPUT);
  
  digitalWrite(d1, LOW); //Wyłączamy diody
  digitalWrite(d2, LOW);
}
 
void loop() {
  if(Serial.available() > 0) { //Czy Arduino odebrano dane
    //Jeśli tak, to odczytujemy je do znaku końca linii i zapisz w zmiennej odebraneDane
    odebraneDane = Serial.readStringUntil('\n'); 
    
    if (odebraneDane == "1") { //Jeśli odebrano słowo "zielona"
      digitalWrite(d1, HIGH); //To włączamy diodę zieloną
      delay(1000);
      digitalWrite(d1, LOW); 
    }
    
    if (odebraneDane == "2") { //Jeśli odebrano słowo "czerwona"
      digitalWrite(d2, HIGH); //To włączamy diodę czerwoną
      delay(1000);
      digitalWrite(d2, LOW); 
    }
  }
}
