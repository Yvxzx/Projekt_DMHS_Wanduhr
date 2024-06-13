#include <Arduino.h>

#include "LedWallEncoder.h"

static const uint8_t TranslationTable[16][16] = {
    {0xE8,0xE7,0xD8,0xD7,0xA8,0xA7,0x98,0x97,0x68,0x67,0x58,0x57,0x28,0x27,0x18,0x17}, 
    {0xE9,0xE6,0xD9,0xD6,0xA9,0xA6,0x99,0x96,0x69,0x66,0x59,0x56,0x29,0x26,0x19,0x16}, 
    {0xEA,0xE5,0xDA,0xD5,0xAA,0xA5,0x9A,0x95,0x6A,0x65,0x5A,0x55,0x2A,0x25,0x1A,0x15}, 
    {0xEB,0xE4,0xDB,0xD4,0xAB,0xA4,0x9B,0x94,0x6B,0x64,0x5B,0x54,0x2B,0x24,0x1B,0x14}, 
    {0xEC,0xE3,0xDC,0xD3,0xAC,0xA3,0x9C,0x93,0x6C,0x63,0x5C,0x53,0x2C,0x23,0x1C,0x13}, 
    {0xED,0xE2,0xDD,0xD2,0xAD,0xA2,0x9D,0x92,0x6D,0x62,0x5D,0x52,0x2D,0x22,0x1D,0x12}, 
    {0xEE,0xE1,0xDE,0xD1,0xAE,0xA1,0x9E,0x91,0x6E,0x61,0x5E,0x51,0x2E,0x21,0x1E,0x11}, 
    {0xEF,0xE0,0xDF,0xD0,0xAF,0xA0,0x9F,0x90,0x6F,0x60,0x5F,0x50,0x2F,0x20,0x1F,0x10}, 
    {0xF8,0xF7,0xC8,0xC7,0xB8,0xB7,0x88,0x87,0x78,0x77,0x48,0x47,0x38,0x37,0x08,0x07}, 
    {0xF9,0xF6,0xC9,0xC6,0xB9,0xB6,0x89,0x86,0x79,0x76,0x49,0x46,0x39,0x36,0x09,0x06}, 
    {0xFA,0xF5,0xCA,0xC5,0xBA,0xB5,0x8A,0x85,0x7A,0x75,0x4A,0x45,0x3A,0x35,0x0A,0x05}, 
    {0xFB,0xF4,0xCB,0xC4,0xBB,0xB4,0x8B,0x84,0x7B,0x74,0x4B,0x44,0x3B,0x34,0x0B,0x04}, 
    {0xFC,0xF3,0xCC,0xC3,0xBC,0xB3,0x8C,0x83,0x7C,0x73,0x4C,0x43,0x3C,0x33,0x0C,0x03}, 
    {0xFD,0xF2,0xCD,0xC2,0xBD,0xB2,0x8D,0x82,0x7D,0x72,0x4D,0x42,0x3D,0x32,0x0D,0x02}, 
    {0xFE,0xF1,0xCE,0xC1,0xBE,0xB1,0x8E,0x81,0x7E,0x71,0x4E,0x41,0x3E,0x31,0x0E,0x01}, 
    {0xFF,0xF0,0xCF,0xC0,0xBF,0xB0,0x8F,0x80,0x7F,0x70,0x4F,0x40,0x3F,0x30,0x0F,0x00}, 
};

void LWC_init() {

}

void LWC_Encode(uint8_t buffer[], const uint8_t image[][16]) {
    for (int x = 0;x < 16;x++) {
        for (int y = 0;y < 16;y++) {
//            const uint8_t pixelpos = TranslationTable[x][y];
            const uint8_t pixelpos = y * 16 + x;

            // buffer[pixelpos] = (image[0][0] > 0) ? 0xff : 0x00;
            if (image[x][y] > 0) {
                buffer[pixelpos] = 0xff;
            }
            else {
                buffer[pixelpos] = 0x00;
            }
        }
    }
}
