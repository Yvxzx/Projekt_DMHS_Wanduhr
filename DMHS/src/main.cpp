// adding Arduino library for nesessary 
#include <Arduino.h>

// linking header (xxx.h)) files to main
#include "Clock/ClockProvider.h"
#include "LedWallEncoder/LedWallEncoder.h"
#include "WallDriver/LEDWallDriver.h"
#include "Glyphs/Glyph.h"


// sets GPIO(General Purpous Input Output) Ports to Easily readable Abreviations.
const uint8_t OE = GPIO_NUM_15;
const uint8_t LA = GPIO_NUM_17;
const uint8_t SDI = GPIO_NUM_25;
const uint8_t CLK = GPIO_NUM_26;

// declares static variables
static uint8_t buffer[256] = { 0 };
static uint8_t image[16][16] = { 0 };
static int j = 0;
static int i = 0;
//static char ab;

/**
 * \brief the first process that runs 
*/
void setup() {
  Serial.begin(115200); // Bits per seconds (Uploadspeed)
  Serial.println("Clock is booting up!");
  CP_init(7200); // Time offset in seconds
  Serial.println("Renderer init");

  // prepares GPIO's for further instructions
  pinMode(OE, OUTPUT);
  pinMode(LA, OUTPUT);
  pinMode(SDI, OUTPUT);
  pinMode(CLK, OUTPUT);
  digitalWrite(OE, LOW);
  digitalWrite(SDI, HIGH);

}


// loop that runns indefinetly 
void loop() 
{
  // outputs, Minutes and Hours as single chars
  Serial.println(CP_GetTimePos1());
  Serial.println(CP_GetTimePos2());
  Serial.println(CP_GetTimePos3());
  Serial.println(CP_GetTimePos4());
  
  // RD_run();

  LWC_Encode(buffer, image);
  // memset(buffer, 0, sizeof(buffer));
  // buffer[x + y * 16] = 0xff;

  WD_BufferOutput(buffer);

  delay(1000);

  WriteGlyph(image, Glyph_0);

  ImagePrint(image);
}

