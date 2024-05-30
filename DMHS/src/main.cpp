#include <Arduino.h>

#include "Clock/ClockProvider.h"

void setup() {
  Serial.begin(115200);

  CP_init(7200);
}

void loop() {
  Serial.println(CP_getHourAsString());
  delay(1000);
}

