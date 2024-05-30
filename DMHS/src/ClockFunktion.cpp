#include <Arduino.h>
#include <ESP32Time.h>


ESP32Time rtc(3600);  

void setup() {

}

void loop() {

String time1 = rtc.getTime("%H:%M");
int i = 0;

    while (i = 1)
    {
        String time2 = rtc.getTime("%H:%M");

        if(time1 =! time2)
        {
            rtc.getTime("%H:%M");
            i++;

            delay(1000);
            
        }
    }
}
