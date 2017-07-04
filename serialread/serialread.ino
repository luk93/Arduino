void setup()
  {
   Serial.begin(9600);
  }
void loop()
  {
   if(Serial.available())
      {
        int liczba=Serial.read();  //odczyt liczby
        Serial.println(liczba);
        char znak=Serial.read();    //odczyt kodu znaku
        Serial.println(znak);
      }
   delay(80);
}
