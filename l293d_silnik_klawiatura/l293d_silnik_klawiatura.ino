#define pwn1 6
#define pwn2 3
#define inp11 7
#define inp12 8
#define inp21 4
#define inp22 5
#define przycisk 9
int i=0;
String odebraneDane = "";
int pwn1_wartosc = 100;
int pwn2_wartosc = 100;
void setup() { 
  Serial.begin(9600); //Uruchomienie komunikacji
  pinMode(pwn1, OUTPUT); //Sygnał PWM silnika nr 1
  pinMode(inp11, OUTPUT); //Sygnały sterujące kierunkiem obrotów silnika nr 1
  pinMode(inp12, OUTPUT);
  pinMode(pwn2, OUTPUT); //Sygnał PWM silnika nr 2
  pinMode(inp21, OUTPUT); //Sygnały sterujące kierunkiem obrotów silnika nr 2
  pinMode(inp22, OUTPUT);
  pinMode(przycisk, INPUT_PULLUP);     
  
  digitalWrite(inp11, LOW); //Silnik nr 1 - stop
  digitalWrite(inp12, LOW);
  digitalWrite(inp21, LOW); //Silnik nr 2 - stop
  digitalWrite(inp22, LOW);
} 
 
void loop()  
{ 
 
    if (digitalRead(przycisk)== LOW){ //przycisk bezpieczenstwa
    silniki_stop();
    delay(100);
    }
    else{
    silniki(); //jesli nie wcisniety 
    }
 }

void silniki_stop(){
    analogWrite(pwn2, pwn2_wartosc);
    digitalWrite(inp21, LOW); //Silnik nr 1 - stop
    digitalWrite(inp22, LOW);
    analogWrite(pwn1, pwn1_wartosc); 
    digitalWrite(inp11, LOW); //Silnik nr 1 - stop
    digitalWrite(inp12, LOW);
    Serial.println("STOP");
}

void silniki(){
  if(Serial.available() > 0) {//Czy Arduino odebrano dane
    //Jeśli tak, to odczytujemy je do znaku końca linii i zapisz w zmiennej odebraneDane
    odebraneDane = Serial.readStringUntil('\n'); 
    
    if (odebraneDane == "silnik 1 lewo") { 
    analogWrite(pwn1, pwn1_wartosc);
    digitalWrite(inp11, LOW); //Silnik nr 1 - lewo
    digitalWrite(inp12, HIGH);
    Serial.println("silnik 1 lewo");
    }
    
    if (odebraneDane == "silnik 1 prawo") {
    analogWrite(pwn1, pwn1_wartosc); 
    digitalWrite(inp11, HIGH); //Silnik nr 1 - prawo
    digitalWrite(inp12, LOW);
    Serial.println("silnik 1 prawo");
    }
    
    if (odebraneDane == "silnik 1 stop") {
    analogWrite(pwn1, pwn1_wartosc); 
    digitalWrite(inp11, LOW); //Silnik nr 1 - stop
    digitalWrite(inp12, LOW);
    Serial.println("silnik 1 stop");
    }
    
    if (odebraneDane == "silnik 2 lewo") {
    analogWrite(pwn2, pwn2_wartosc);
    digitalWrite(inp21, LOW); //Silnik nr 1 - lewo
    digitalWrite(inp22, HIGH);
    Serial.println("silnik 2 lewo");
    }
    
    if (odebraneDane == "silnik 2 prawo") { 
    analogWrite(pwn2, pwn2_wartosc);
    digitalWrite(inp21, HIGH); //Silnik nr 1 - prawo
    digitalWrite(inp22, LOW);
    Serial.println("silnik 2 prawo");
    }
    
    if (odebraneDane == "silnik 2 stop") { 
    analogWrite(pwn2, pwn2_wartosc);
    digitalWrite(inp21, LOW); //Silnik nr 1 - stop
    digitalWrite(inp22, LOW);
    Serial.println("silnik 2 stop");
    }
    
    if (odebraneDane == "stop") { 
    silniki_stop();
    }
    
    if (odebraneDane == "silnik 1 predkosc 100") {
    pwn1_wartosc = 255;
    analogWrite(pwn1, pwn1_wartosc);
    Serial.println("Silnik 1 predkosc 100 procent ");

    }

    if (odebraneDane == "silnik 2 predkosc 100") {
    pwn2_wartosc = 255;
    analogWrite(pwn2, pwn1_wartosc);
    Serial.println("Silnik 2 predkosc 100 procent ");

    }
    
    if (odebraneDane == "silnik 1 predkosc 50") {
    pwn1_wartosc = 128;
    analogWrite(pwn1, pwn1_wartosc);
    Serial.println("Silnik 1 predkosc 50 procent ");

    }

    if (odebraneDane == "silnik 2 predkosc 50") {
    pwn2_wartosc = 128;
    analogWrite(pwn2, pwn1_wartosc);
    Serial.println("Silnik 2 predkosc 50 procent ");

    }
    
    
  }
 }

