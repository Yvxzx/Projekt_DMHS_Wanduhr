#include <Arduino.h>

#include "Clock/ClockProvider.h"
#include "Renderer/Renderer.h"

void setup() {
  Serial.begin(115200);

  CP_init(7200);
  RD_init();
}

void loop() 
{
  Serial.println(CP_getHourAsString());
  delay(1000);
}

