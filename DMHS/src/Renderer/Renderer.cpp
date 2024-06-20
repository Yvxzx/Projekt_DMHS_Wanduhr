#include <Arduino.h>

#include <stdint.h>

int array[4][4] = {
    {1, 2, 3, 4},
    {21, 22, 23, 24},
    {31, 32, 33, 34},
    {41, 42, 43, 44}
    
};
int i = 0;
int x = 0;
int y = 0;

void RD_init() {

}

void RD_run() {
    while (x < 4)
    {
        while (y < 4)
        {
            Serial.println(array[x][y]);
            y++;
        }
        y = 0;
        x++;
    }
}