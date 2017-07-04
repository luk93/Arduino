#include <IRremote.h>
#define irPin 6
#define d1 4
#define d2 2
#define d3 3
IRrecv irrecv(irPin);
decode_results results;
int d1_status = LOW;
int d2_status = LOW;
int d3_status = LOW;
 
void setup() {
      Serial.begin(9600);
   irrecv.enableIRIn();
    pinMode(d1, OUTPUT);
    pinMode(d2, OUTPUT);
    pinMode(d3, OUTPUT);
}
 
void loop() {
   if (irrecv.decode(&results)) {
 
      switch (results.value) {
         case 0x76044FE2:{
            d1_status = ~d1_status;
            digitalWrite(d1, d1_status);
            Serial.println("1");}
            break;
 
         case 0x76044FD2:{
            d2_status = ~d2_status;
            digitalWrite(d2, d2_status);
            Serial.println("2");}
            break;
 
         case 0x76044FF2:{
            d3_status = ~d3_status;
            digitalWrite(d3, d3_status);
            Serial.println("3");}
            break;
         }
 
   irrecv.resume();
   }
}
