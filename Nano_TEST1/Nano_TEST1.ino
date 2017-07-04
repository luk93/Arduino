#define led1 2
#define led2 3

String odebraneDane = "";

void setup() { 
  Serial.begin(9600); //Uruchomienie komunikacji
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);   
  
  digitalWrite(led1, LOW); 
  digitalWrite(led2, HIGH);
  Serial.print("DUPA");
 
} 
 
void loop()  
{ 
 
}

