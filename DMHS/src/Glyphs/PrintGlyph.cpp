#include <stdint.h>
#include <Arduino.h>

const int posX = 0;
const int posY = 5;

typedef struct sGlyph {
  uint8_t width;
  uint8_t height;
  char glyphName;
  uint8_t glyph[];
}tGlyph;

// 0
static const tGlyph Glyph0 = {
  .width = 4,
  .height = 7,
  .glyph = {
    0x00,0xff,0xff,0x00,
    0xff,0x00,0x00,0xff,
    0xff,0x00,0x00,0xff,
    0xff,0x00,0x00,0xff,
    0xff,0x00,0x00,0xff,
    0xff,0x00,0x00,0xff,
    0x00,0xff,0xff,0x00   
  }
};
// 1
static const tGlyph Glyph1 = {
  .width = 4,
  .height = 7,
  .glyphName = '1',
  .glyph = {
    0x00,0x00,0xff,0x00,
    0x00,0xff,0xff,0x00,
    0x00,0x00,0xff,0x00,
    0x00,0x00,0xff,0x00,
    0x00,0x00,0xff,0x00,
    0x00,0x00,0xff,0x00,
    0x00,0x00,0xff,0x00
  }
};
// 2
static const tGlyph Glyph2 = {
  .width = 4,
  .height = 7,
  .glyphName = '2',
  .glyph = {
    0x00,0xff,0xff,0x00,
    0xff,0x00,0x00,0xff,
    0x00,0x00,0x00,0xff,
    0x00,0xff,0xff,0x00,
    0xff,0x00,0x00,0x00,
    0xff,0x00,0x00,0x00,
    0xff,0xff,0xff,0xff
  }
};
// 3
static const tGlyph Glyph3 = {
  .width = 4,
  .height = 7,
  .glyphName = '3',
  .glyph = {
    0x00,0xff,0xff,0x00,
    0x00,0x00,0x00,0xff,
    0x00,0x00,0x00,0xff,
    0x00,0xff,0xff,0xff,
    0x00,0x00,0x00,0xff,
    0x00,0x00,0x00,0xff,
    0x00,0xff,0xff,0x00
  }
};
// 4
static const tGlyph Glyph4 = {
  .width = 4,
  .height = 7,
  .glyphName = '4',
  .glyph = {
    0xff,0x00,0x00,0xff,
    0xff,0x00,0x00,0xff,
    0xff,0x00,0x00,0xff,
    0x00,0xff,0xff,0xff,
    0x00,0x00,0x00,0xff,
    0x00,0x00,0x00,0xff,
    0x00,0x00,0x00,0xff
  }
};
// 5
static const tGlyph Glyph5 = {
  .width = 4,
  .height = 7,
  .glyphName = '5',
  .glyph = {
    0xff,0xff,0xff,0xff,
    0xff,0x00,0x00,0x00,
    0xff,0xff,0xff,0x00,
    0x00,0x00,0x00,0xff,
    0x00,0x00,0x00,0xff,
    0xff,0x00,0x00,0xff,
    0x00,0xff,0xff,0x00
  }
};
// 6
static const tGlyph Glyph6 = {
  .width = 4,
  .height = 7,
  .glyphName = '6',
  .glyph = {
    0x00,0xff,0xff,0x00,
    0xff,0x00,0x00,0xff,
    0xff,0x00,0x00,0x00,
    0xff,0xff,0xff,0x00,
    0xff,0x00,0x00,0xff,
    0xff,0x00,0x00,0xff,
    0x00,0xff,0xff,0x00
  }
};
// 7
static const tGlyph Glyph7 = {
  .width = 4,
  .height = 7,
  .glyphName = '7',
  .glyph = {
    0xff,0xff,0x00,0x00,
    0x00,0x00,0xff,0x00,
    0x00,0x00,0xff,0x00,
    0x00,0x00,0xff,0x00,
    0x00,0x00,0xff,0x00,
    0x00,0x00,0xff,0x00,
    0x00,0x00,0xff,0x00
  }
};
// 8
static const tGlyph Glyph8 = {
  .width = 4,
  .height = 7,
  .glyphName = '8',
  .glyph = {
    0x00,0xff,0xff,0x00,
    0xff,0x00,0x00,0xff,
    0xff,0x00,0x00,0xff,
    0x00,0xff,0xff,0x00,
    0xff,0x00,0x00,0xff,
    0xff,0x00,0x00,0xff,
    0x00,0xff,0xff,0x00
  }
};
// 9
static const tGlyph Glyph9 = {
  .width = 4,
  .height = 7,
  .glyphName = '9',
  .glyph = {
    0x00,0xff,0xff,0x00,
    0xff,0x00,0x00,0xff,
    0xff,0x00,0x00,0xff,
    0x00,0xff,0xff,0xff,
    0x00,0x00,0x00,0xff,
    0x00,0x00,0x00,0xff,
    0x00,0xff,0xff,0x00
  }
};
// h
static const tGlyph GlyphH = {
  .width = 4,
  .height = 7,
  .glyphName = 'H',
  .glyph = {
    0xff,0x00,0x00,0x00,
    0xff,0x00,0x00,0x00,
    0xff,0x00,0x00,0x00,
    0xff,0xff,0xff,0x00,
    0xff,0x00,0x00,0xff,
    0xff,0x00,0x00,0xff,
    0xff,0x00,0x00,0xff
  }
};
// S1
static const tGlyph GlyphS1 = {
  .width = 5,
  .height = 7,
  .glyphName = 'S',
  .glyph = {
    0x00,0x00,0x00,0x00,0x00,
    0x00,0xff,0x00,0xff,0x00,
    0x00,0xff,0x00,0xff,0x00,
    0x00,0x00,0x00,0x00,0x00,
    0xff,0x00,0x00,0x00,0x00,
    0xff,0xff,0xff,0xff,0xff,
    0x00,0x00,0x00,0x00,0x00
  }
};
// S2
static const tGlyph GlyphS2 = {
  .width = 5,
  .height = 7,
  .glyphName = 's',
  .glyph = {
    0x00,0x00,0x00,0x00,0x00,
    0x00,0xff,0x00,0x00,0x00,
    0x00,0xff,0x00,0xff,0xff,
    0x00,0x00,0x00,0x00,0x00,
    0xff,0x00,0x00,0x00,0x00,
    0xff,0xff,0xff,0xff,0xff,
    0x00,0x00,0x00,0x00,0x00
  }
};

void PG_init() { }

void PrintGlyph(uint8_t image[][16], int posY, int posX)
{
  int i = 0;
  for (int x = 0;x < Glyph2.height; x++)
  {
    for (int y = 0;y < Glyph2.width; y++)
    {
      image[y + posY][x + posX] = Glyph2.glyph[i];
      i++;
    }
  }
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