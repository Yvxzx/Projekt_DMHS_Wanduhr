#pragma once

 #include <stdint.h>
 #include <Arduino.h>

void PG_init();

void WriteGlyph(uint8_t image[][16]);

void ImagePrint(const uint8_t image[][16]);
