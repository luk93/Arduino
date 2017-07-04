#include <Servo.h>
#define SERVO_PIN 0
#define POT_PIN 1
Servo servo;

int odczyt_pot;
int kat_servo;

void setup()
{
  servo.attach(SERVO_PIN);
}

void loop()
{
  odczyt_pot = analogRead(POT_PIN);
  kat_servo = map(odczyt_pot, 0, 1023, 0, 180);
  servo.write(kat_servo);
  delay(20);
}
