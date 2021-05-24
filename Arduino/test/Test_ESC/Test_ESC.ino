#include <Servo.h>

int servoPin = 3;

Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  //analogWrite(3, 255);
  servo.write(0);
  delay(2000);
  servo.write(00);
  delay(2000);
  servo.write(0);
  delay(1000);
}
