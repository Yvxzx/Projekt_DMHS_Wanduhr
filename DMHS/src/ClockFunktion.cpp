#include <Arduino.h>
#include <ESP32Time.h>


ESP32Time rtc(3600);  

void setup() {

}

void loop() {

String zeit1 = rtc.getTime("%H:%M");
int i = 0;

    while (i = 1)
    {
        String zeit2 = rtc.getTime("%H:%M");

        if(zeit1 =! zeit2)
        {
            Serial.print(rtc.getTime("%H:%M"));
            i++;

            delay(1000);
            
        }
    }
}
