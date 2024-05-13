#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);
int ledPin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);

  // Serial.begin(115200,  SERIAL_8N1);
  // Serial.end();
  // Serial.begin(115200, SERIAL_8N1);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World!");
  digitalWrite(ledPin, HIGH);
  delay(500);
  
  digitalWrite(ledPin, LOW);
  delay(500);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
