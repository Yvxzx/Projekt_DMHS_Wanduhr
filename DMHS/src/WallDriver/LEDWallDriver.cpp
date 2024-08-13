#include <Arduino.h>


// Sets GPIO(General Purpous Input Output) Ports as easily readable abreviations.
const uint8_t OE = GPIO_NUM_15;
const uint8_t LA = GPIO_NUM_17;
const uint8_t SDI = GPIO_NUM_25;
const uint8_t CLK = GPIO_NUM_26;

static void PixelPush(uint8_t value);

void WD_init() {}

/**
 * \brief Cycles through buffer array, extracts every value and runs Pixelpush per value
 * 
 * \param buffer reads the buffer array one by one and pushes them one by one
 */
void WD_BufferOutput(const uint8_t) {
  digitalWrite(LA, LOW);

  for (int i = 0;i < 256;i++) {
    uint8_t pixel = buffer[i];
    PixelPush(pixel);
  }

  delay(1);
  digitalWrite(LA, HIGH);
}

/**
 * \brief Uses digitalWrite (Arduino.h's Funktion) to input signals into Display
 * 
 * \param[in] value buffer values either on or off.
 */
static void PixelPush(uint8_t value) {
                // one-line if statment.
  digitalWrite(SDI, value > 0 ? HIGH : LOW);
  delayMicroseconds(1);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(1);
  digitalWrite(CLK, LOW);
}