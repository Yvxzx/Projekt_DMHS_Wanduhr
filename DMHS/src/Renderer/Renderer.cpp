#include <Arduino.h>

int array[4][4] = {
    {1, 2, 3, 4},
    {21, 22, 23, 24},
    {31, 32, 33, 34},
    {41, 42, 43, 44}
};
int i = 0;

void RD_init() {
    Serial.begin(115200);
    
    while (i<10) {

        Serial.println(array[2][3]);
        delay(1000);
        i++;
    }
}
