#pragma once

 #include <stdint.h>
 #include <Arduino.h>

void PG_init();

void PrintGlyph(uint8_t image[][16], int posY, int posX);

void ImagePrint(const uint8_t image[][16]);
