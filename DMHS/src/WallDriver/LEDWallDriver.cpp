#include <Arduino.h>

const uint8_t OE = GPIO_NUM_15;
const uint8_t LA = GPIO_NUM_17;
const uint8_t SDI = GPIO_NUM_25;
const uint8_t CLK = GPIO_NUM_26;

static void PixelPush(uint8_t value);

void WD_init() { 
}

void WD_BufferOutput(const uint8_t *buffer) {
  digitalWrite(LA, LOW);

  for (int i = 0;i < 256;i++) {
    uint8_t pixel = buffer[i];
    PixelPush(pixel);
  }

  delay(1);
  digitalWrite(LA, HIGH);
}

static void PixelPush(uint8_t value) {
    digitalWrite(SDI, value > 0 ? HIGH : LOW);
    delayMicroseconds(1);
    digitalWrite(CLK, HIGH);
    delayMicroseconds(1);
    digitalWrite(CLK, LOW);
}

