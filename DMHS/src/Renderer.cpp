#include <Arduino.h>

int array[4][4] = {
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1}
};

int i = 0;
void RD_init() {
    Serial.begin(115200);
    Serial.println(array[2][3]);
    
    while (i<10) {
        Serial.println(array[2][3]);
        delay(1000);
        i++;
    }
}