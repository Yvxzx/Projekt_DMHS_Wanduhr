// adding Arduino library for nesessary 
#include <Arduino.h>

// linking header (xxx.h)) files to main
#include "Clock/ClockProvider.h"
#include "Renderer/Renderer.h"
#include "LedWallEncoder/LedWallEncoder.h"
#include "WallDriver/LEDWallDriver.h"
#include "Glyphs/PrintGlyph.h"


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
static char ab;

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

  RD_init();
  LWC_init();
}


// loop that runns indefinetly 
void loop() 
{
  // outputs, Minutes and Hours as single chars
  Serial.println(NumForHour1());
  Serial.println(NumForHour2());
  Serial.println(NumForMinute1());
  Serial.println(NumForMinute2());
  
  // RD_run();

  LWC_Encode(buffer, image);
  // memset(buffer, 0, sizeof(buffer));
  // buffer[x + y * 16] = 0xff;

  WD_BufferOutput(buffer);

  delay(1000);

  PrintGlyph(image);
  


  ImagePrint(image);
/*
  // Glyphs
  const uint8_t Glyph0[7][4] = 
  {
    {0x00,0xff,0xff,0x00},
    {0xff,0x00,0x00,0xff},
    {0xff,0x00,0x00,0xff},
    {0xff,0x00,0x00,0xff},
    {0xff,0x00,0x00,0xff},
    {0xff,0x00,0x00,0xff},
    {0x00,0xff,0xff,0x00}
};
  const uint8_t Glyph9[7][4] = 
  {
    {0x00,0xff,0xff,0x00},
    {0xff,0x00,0x00,0xff},
    {0xff,0x00,0x00,0xff},
    {0x00,0xff,0xff,0xff},
    {0x00,0x00,0x00,0xff},
    {0x00,0x00,0x00,0xff},
    {0x00,0xff,0xff,0x00}
};

  const uint8_t Glyph6[7][4] = 
  {
    {0x00,0xff,0xff,0x00},
    {0xff,0x00,0x00,0xff},
    {0xff,0x00,0x00,0x00},
    {0xff,0xff,0xff,0x00},
    {0xff,0x00,0x00,0xff},
    {0xff,0x00,0x00,0xff},
    {0x00,0xff,0xff,0x00}
};
  const uint8_t GlyphSmiley1[7][5] = 
  {
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0xff,0x00,0xff,0x00},
    {0x00,0xff,0x00,0xff,0x00},
    {0x00,0x00,0x00,0x00,0x00},
    {0xff,0x00,0x00,0x00,0x00},
    {0xff,0xff,0xff,0xff,0xff},
    {0x00,0x00,0x00,0x00,0x00}
};
  const uint8_t GlyphSmiley2[7][5] = 
  {
    {0x00,0x00,0x00,0x00,0x00},
    {0x00,0xff,0x00,0x00,0x00},
    {0x00,0xff,0x00,0xff,0xff},
    {0x00,0x00,0x00,0x00,0x00},
    {0xff,0x00,0x00,0x00,0x00},
    {0xff,0xff,0xff,0xff,0xff},
    {0x00,0x00,0x00,0x00,0x00}
};
  const uint8_t GlyphH[7][5] = 
  {
    {0xff,0x00,0x00,0x00,0x00},
    {0xff,0x00,0x00,0x00,0x00},
    {0xff,0x00,0x00,0x00,0x00},
    {0xff,0xff,0xff,0x00,0x00},
    {0xff,0x00,0x00,0xff,0x00},
    {0xff,0x00,0x00,0xff,0x00},
    {0xff,0x00,0x00,0xff,0x00}
};
  const uint8_t Glyph7[7][4] = 
  {
    {0xff,0xff,0x00,0x00},
    {0x00,0x00,0xff,0x00},
    {0x00,0x00,0xff,0x00},
    {0x00,0x00,0xff,0x00},
    {0x00,0x00,0xff,0x00},
    {0x00,0x00,0xff,0x00},
    {0x00,0x00,0xff,0x00}
};

  // stores values from glyphs into Image
  // LWC_Encode( buffer, image);
  image[y][x] = 0;
  for (int x = 0;x < 7; x++)
  {
    for (int y = 0;y < 4; y++)
    {
      image[y][x] = Glyph6[x][y];
    }
  }
  
  image[y][x] = 0;
  for (int x = 0;x < 7; x++)
  {
    for (int y = 0;y < 4; y++)
    {
      image[y+7][x+8] = Glyph0[x][y];
    }
  }

  image[y][x] = 0;
  for (int x = 0;x < 7; x++)
  {
    for (int y = 0;y < 4; y++)
    {
      image[y+12][x+8] = Glyph7[x][y];
    }
  }

  image[y][x] = 0;
  for (int x = 0;x < 7; x++)
  {
    for (int y = 0;y < 4; y++)
    {
      image[y+10][x] = GlyphH[x][y];
    }
  }

  image[x][y] = 0;
  for (int x = 0;x < 7; x++)
  {
    for (int y = 0;y < 4; y++)
    {
      image[y+5][x] = Glyph9[x][y];
    }
  }

  if (smiliIf == 0) 
  {
    image[x][y] = 0;
    for (int x = 0;x < 7; x++)
    {
      for (int y = 0;y < 5; y++)
      {
        image[y+1][x+8] = GlyphSmiley1[x][y];
      }
    }
    smiliIf++;
  } else 
  {
    image[x][y] = 0;
    for (int x = 0;x < 7; x++)
    {
      for (int y = 0;y < 5; y++)
      {
        image[y+1][x+8] = GlyphSmiley2[x][y];
      }
    }    
    smiliIf = 0;
  }
*/
}

