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
static int j = 0;

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

  // Zahl 2
  image[0][1] = 0xff;
  image[1][0] = 0xff;
  image[2][0] = 0xff;
  image[3][1] = 0xff;
  image[3][2] = 0xff;
  image[2][3] = 0xff;
  image[1][3] = 0xff;
  image[0][4] = 0xff;
  image[0][5] = 0xff;
  image[0][6] = 0xff;
  image[1][6] = 0xff;
  image[2][6] = 0xff;
  image[3][6] = 0xff;

  // Zahl 3
  image[6][0] = 0xff;
  image[7][0] = 0xff;
  image[8][1] = 0xff;
  image[8][2] = 0xff;
  image[7][3] = 0xff;
  image[6][3] = 0xff;
  image[8][4] = 0xff;
  image[8][5] = 0xff;
  image[7][6] = 0xff;
  image[6][6] = 0xff;

  // Smili
  image[2][9] = 0xff;
  image[2][10] = 0xff;
  image[1][12] = 0xff;
  image[2][13] = 0xff;
  image[3][13] = 0xff;
  image[4][13] = 0xff;
  image[5][12] = 0xff;
  image[4][9] = 0xff;
  if (j == 0){
    j++;
    image[5][10] = 0;
    image[4][10] = 0xff;
    delay(1000);
  }
  else{
    image[4][9] = 0;
    image[5][10] = 0xff;
    delay(1000);
    j = 0;
  }
  



  // x++;
  // if (x >= 16) {
  //   x = 0;
  //   y++;
  // }
  // if (y >= 16) {
  //   y = 0;
  //   x = 0;
  // }
  // image[x][y] = 0xff;

ImagePrint(image);
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
=======
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
