#include <Arduino.h>

#include "Clock/ClockProvider.h"
#include "Renderer/Renderer.h"
#include "LedWallEncoder/LedWallEncoder.h"
#include "WallDriver/LEDWallDriver.h"

const uint8_t OE = GPIO_NUM_15;
const uint8_t LA = GPIO_NUM_17;
const uint8_t SDI = GPIO_NUM_25;
const uint8_t CLK = GPIO_NUM_26;

static uint8_t buffer[256] = { 0 };
static uint8_t image[16][16] = { 0 };

void ImagePrint(const uint8_t image[][16]);

void setup() {
  Serial.begin(115200);
  Serial.println("Clock is booting up!");
  CP_init(7200);
  Serial.println("Renderer init");

  pinMode(OE, OUTPUT);
  pinMode(LA, OUTPUT);
  pinMode(SDI, OUTPUT);
  pinMode(CLK, OUTPUT);
  digitalWrite(OE, LOW);
  digitalWrite(SDI, HIGH);

  RD_init();
  LWC_init();
}

static int x = 0;
static int y = 0;

void loop() 
{
  Serial.println(CP_getHourAsString());
  RD_run();

  LWC_Encode(buffer, image);
  // memset(buffer, 0, sizeof(buffer));
  // buffer[x + y * 16] = 0xff;

  WD_BufferOutput(buffer);

  delay(100);

  image[x][y] = 0;
  x++;
  if (x >= 16) {
    x = 0;
    y++;
  }
  if (y >= 16) {
    y = 0;
    x = 0;
  }
  image[x][y] = 0xff;

//  ImagePrint(image);
}

void ImagePrint(const uint8_t image[][16]) {
  Serial.println("+----------------------------------+");
  for (int y = 0;y < 16;y++) {
    Serial.print("| ");
    for (int x = 0;x < 16;x++) {
      Serial.print(image[x][y] > 0 ? "XX" : "  ");
    }
    Serial.println(" |");
  }
  Serial.println("+----------------------------------+");
}