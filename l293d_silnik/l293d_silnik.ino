#define pwn1 6
#define pwn2 3
#define inp11 7
#define inp12 8
#define inp21 4
#define inp22 5
int i=0;
String odebraneDane = "";
void setup() { 

  pinMode(pwn1, OUTPUT); //Sygnał PWM silnika nr 1
  pinMode(inp11, OUTPUT); //Sygnały sterujące kierunkiem obrotów silnika nr 1
  pinMode(inp12, OUTPUT);
  pinMode(pwn2, OUTPUT); //Sygnał PWM silnika nr 2
  pinMode(inp21, OUTPUT); //Sygnały sterujące kierunkiem obrotów silnika nr 2
  pinMode(inp22, OUTPUT);
  
  digitalWrite(inp11, LOW); //Silnik nr 2 - obroty w lewo
  digitalWrite(inp12, LOW);
  digitalWrite(inp21, LOW); //Silnik nr 2 - obroty w lewo
  digitalWrite(inp22, LOW);
} 
 
void loop()  
{ 
  
}
void silniki(){
  if(Serial.available() > 0) { //Czy Arduino odebrano dane
    //Jeśli tak, to odczytujemy je do znaku końca linii i zapisz w zmiennej odebraneDane
    odebraneDane = Serial.readStringUntil('\n'); 
    
    if (odebraneDane == "1") { //Jeśli odebrano słowo "zielona"

    }
    
    if (odebraneDane == "2") { //Jeśli odebrano słowo "czerwona"

    }
  }
 }

