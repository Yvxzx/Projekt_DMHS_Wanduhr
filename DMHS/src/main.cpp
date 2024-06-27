// adding Arduino library for nesessary 
#include <Arduino.h>

// linking header (xxx.h)) files to main
#include "Clock/ClockProvider.h"
#include "Renderer/Renderer.h"
#include "LedWallEncoder/LedWallEncoder.h"
#include "WallDriver/LEDWallDriver.h"

// Sets GPIO(General Purpous Input Output) Ports to Easily readable Abreviations.
const uint8_t OE = GPIO_NUM_15;
const uint8_t LA = GPIO_NUM_17;
const uint8_t SDI = GPIO_NUM_25;
const uint8_t CLK = GPIO_NUM_26;

//declares static variables
static uint8_t buffer[256] = { 0 };
static uint8_t image[16][16] = { 0 };
static int j = 0;
static int i = 0;
static int x = 0;
static int y = 0;

void ImagePrint(const uint8_t image[][16]);

/**
 * \brief the first process that runs
 * 
 * 
*/
void setup() {
  Serial.begin(115200); // Bits per seconds (Uploadspeed)
  Serial.println("Clock is booting up!");
  CP_init(7200); // Time offset in seconds
  Serial.println("Renderer init");

  // Prepares GPIO's for further instructions
  pinMode(OE, OUTPUT);
  pinMode(LA, OUTPUT);
  pinMode(SDI, OUTPUT);
  pinMode(CLK, OUTPUT);
  digitalWrite(OE, LOW);
  digitalWrite(SDI, HIGH);

  RD_init();
  LWC_init();
}


// Loop that runns indefinetly 
void loop() 
{
  // Outputs, Minutes and Hours
  Serial.println(CP_getHourAsString());
  Serial.println(CP_getMinuteAsString());
  
  //RD_run();

  LWC_Encode(buffer, image);
  // memset(buffer, 0, sizeof(buffer));
  // buffer[x + y * 16] = 0xff;

  WD_BufferOutput(buffer);

  delay(100);

  // bitmap on IMS Image
  const uint8_t IMSTimage[7][16] = {
    {0xff,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0xff,0xff},
    {0xff,0x00,0xff,0xff,0x00,0xff,0xff,0x00,0xff,0x00,0x00,0x00},
    {0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,0xff,0x00,0x00,0x00},
    {0xff,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0xff,0x00},
    {0xff,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0xff},
    {0xff,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0xff},
    {0xff,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0xff,0xff,0xff,0x00},
  };

  // stores values from IMSTimage into Image
  //LWC_Encode( buffer, image);
  image[y][x] = 0;
  for (int x = 0;x < 15; x++)
  {
    for (int y = 0;y < 15; y++)
    {
      image[y][x] = IMSTimage[x][y];
    }
  }
ImagePrint(image);
}

/**
 * \brief Draws preview of led display for moblie modifications.
 * 
 * \param image Uses image to print in serial monitor
 */

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

/*
if(i <= 15)
{

  for (int a = 0; a < 16; a++)
  {
    for (int b = 0; b < 16; b++)
    {
      image[a][b] = 0;
    }
    
  }
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
  image[4][10] = 0xff;
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

  // h
  image[10][0] = 0xff;
  image[10][1] = 0xff;
  image[10][2] = 0xff;
  image[10][3] = 0xff;
  image[10][4] = 0xff;
  image[10][5] = 0xff;
  image[10][6] = 0xff;
  image[11][3] = 0xff;
  image[12][4] = 0xff;
  image[12][5] = 0xff;
  image[12][6] = 0xff;

  // Zahl 5
  image[7][9] = 0xff;
  image[8][9] = 0xff;
  image[9][9] = 0xff;  
  image[10][9] = 0xff;
  image[7][10] = 0xff;  
  image[7][11] = 0xff;  
  image[8][11] = 0xff;  
  image[9][11] = 0xff;  
  image[10][12] = 0xff; 
  image[10][13] = 0xff; 
  image[10][14] = 0xff; 
  image[9][15] = 0xff;
  image[8][15] = 0xff;
  image[7][14] = 0xff;

  // Zahl 8
  image[13][9] = 0xff;
  image[14][9] = 0xff;
  image[15][10] = 0xff;
  image[15][11] = 0xff;
  image[15][13] = 0xff;
  image[15][14] = 0xff;
  image[14][15] = 0xff;
  image[13][15] = 0xff;
  image[12][14] = 0xff;
  image[12][13] = 0xff;
  image[13][12] = 0xff;
  image[14][12] = 0xff;
  image[12][10] = 0xff;
  image[12][11] = 0xff;

  i++;

}else
{
  for (int a = 0; a < 16; a++)
  {
    for (int b = 0; b < 16; b++)
    {
      image[a][b] = 0;
    }
    
  }
  // Buchstabe E
  image[1][2] = 0xff;
  image[1][3] = 0xff;
  image[1][4] = 0xff;
  image[1][5] = 0xff;
  image[1][6] = 0xff;
  image[1][7] = 0xff;
  image[1][8] = 0xff;
  image[1][9] = 0xff;
  image[1][10] = 0xff;
  image[1][11] = 0xff;
  image[1][12] = 0xff;
  image[1][13] = 0xff;

  image[2][2] = 0xff;
  image[2][3] = 0xff;
  image[2][4] = 0xff;
  image[2][5] = 0xff;
  image[2][6] = 0xff;
  image[2][7] = 0xff;
  image[2][8] = 0xff;
  image[2][9] = 0xff;
  image[2][10] = 0xff;
  image[2][11] = 0xff;
  image[2][12] = 0xff;
  image[2][13] = 0xff;

  image[3][2] = 0xff;
  image[4][2] = 0xff;
  image[5][2] = 0xff;
  image[3][3] = 0xff;
  image[4][3] = 0xff;
  image[5][3] = 0xff;

  image[3][7] = 0xff;
  image[4][7] = 0xff;
  image[5][7] = 0xff;
  image[3][8] = 0xff;
  image[4][8] = 0xff;
  image[5][8] = 0xff;

  image[3][12] = 0xff;
  image[4][12] = 0xff;
  image[5][12] = 0xff;
  image[3][13] = 0xff;
  image[4][13] = 0xff;
  image[5][13] = 0xff;


  // Zahl 11

  image[8][10] = 0xff;
  image[9][9] = 0xff;
  image[9][10] = 0xff;
  image[9][11] = 0xff;
  image[9][12] = 0xff;
  image[9][13] = 0xff;

  image[11][10] = 0xff;
  image[12][9] = 0xff;
  image[12][10] = 0xff;
  image[12][11] = 0xff;
  image[12][12] = 0xff;
  image[12][13] = 0xff;
  i = 0;

  //delay(5000);
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
 */