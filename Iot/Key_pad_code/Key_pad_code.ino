#include <ESP32Servo.h>

static const int servoPin = 13;

Servo servo1;

void setup() {
  Serial.begin(9600);

  // Attach servo to pin
  servo1.attach(servoPin);
} 

void loop() {

  // Drej fra 0° til 90°
  for(int pos = 0; pos <= 90; pos+=3) {
    servo1.write(pos);
    Serial.println(pos);
    delay(20);
  }

  delay(500); // lille pause

  // Drej fra 90° tilbage til 0°
  for(int pos =90; pos >= 0; pos-=3) {
    servo1.write(pos);
    Serial.println(pos);
    delay(20);
  }

  delay(500);
}
