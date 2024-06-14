#include <Arduino.h>

#include "Clock/ClockProvider.h"

void setup() {
  Serial.begin(115200);

  CP_init(7200);
  RD_init();
}

void loop() 
{
  Serial.println(CP_getHourAsString());
  Serial.println(CP_getMinuteAsString());
  delay(60000);
}

/*
// Buchstaben-Jagd IMS-T
int number1 = 2;
int number2 = 3;
int solution = 0;

solution = number1 + number2;

if(solution != 5)
{
  Serial.println("Number 7 at position 6");
}
else
{
  Serial.println("Number 8 at position 6");
}
*/