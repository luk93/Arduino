#include <Arduino.h>
#include <IRremote.h>
#define pin_ir 4
#define pin_trg 3
IRrecv irrecv(pin_ir);
decode_results results;

 
void setup() 
{
    pinMode(pin_trg, OUTPUT); 
    Serial.begin(9600);
    irrecv.enableIRIn();
}   
void loop() {
 if (irrecv.decode(&results)) {
      switch (results.value) {
         case 0x76044FE2:
         digitalWrite(pin_trg, HIGH);
         break;
 
         case 0x76044FD2:
         digitalWrite(pin_trg, LOW);
         break;
 
         case 0x76044FF2:
         break;
      }irrecv.resume();
   }
   
}
