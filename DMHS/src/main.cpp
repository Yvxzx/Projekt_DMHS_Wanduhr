#include <Arduino.h>

#include "Clock/ClockProvider.h"

void setup() {
  Serial.begin(115200);

  CP_init(7200);
}

void loop() 
{
  Serial.println(CP_getHourAsString());
  Serial.println(CP_getMinuteAsString());
  delay(60000);
}

