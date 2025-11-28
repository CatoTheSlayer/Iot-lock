#include <ESP32Servo.h>

static const int servoPin = 22;

Servo servo1;

void setup() {
  Serial.begin(9600);

  // Attach servo to pin
  servo1.attach(servoPin);
} 

void loop() {
  //90 er låst
  //0 er åben
      servo1.write(90);
      delay(1050);
      servo1.write(0);
      delay(250);
}
