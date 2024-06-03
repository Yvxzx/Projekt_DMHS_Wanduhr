#include "ClockProvider.h"

#include <Arduino.h>
#include <ESP32Time.h>

static ESP32Time rtc;  
/**
 * \brief   Initializes the clock access module
 * 
 * \param[in]   offset  [s] Number of seconds the timezone is away from UTC
 */
void CP_init(int offset) 
{
    rtc.offset = offset;
}

/**
 * \brief   Formats the current hour as string
 * 
 * \return  String with the current hour as string formatted number
 */
String CP_getHourAsString()
{
    // Serial.println(rtc.getTime("%d.%m.%Y %H:%M:%S"));
    return rtc.getTime("%d.%m.%Y %H:%M:%S");
} 

/*static void CP_loop() {

    String time1 = rtc.getTime("%H:%M");
    int i = 0;

    while (i > 0)
    {
        String time2 = rtc.getTime("%H:%M");

        if(time1 != time2)
        {
            String hour = rtc.getTime("%H");
            String minute = rtc.getTime("%M");

            i++;
            delay(1000);
        }
    }
}
*/