#include "ClockProvider.h"

#include <Arduino.h>
#include <ESP32Time.h>
#include <time.h>

static ESP32Time rtc;

/**git
 * \brief   Initializes the clock access module
 * 
 * \param[in]   offset  [s] Number of seconds the timezone is away from UTC
 */
void CP_init(int offset) 
{
    struct tm build_time;

    strptime(__DATE__ " " __TIME__, "%b %d %Y %H:%M:%S", &build_time);
    rtc.setTime(mktime(&build_time) - offset);

    rtc.offset = offset;
}

/**
 * \brief   Formats the current hour as string
 * 
 * \return  String with the current hour as string formatted number
 */
String CP_getHourAsString()
{
    // Serial.println(rtc.getTime("%H"));
    return rtc.getTime("%H");
} 

/**
 * \brief   Formats the current minute as string
 * 
 * \return  String with the current minute as string formatted number
 */
String CP_getMinuteAsString()
{
    // Serial.println(rtc.getTime("%M"));
    return rtc.getTime("%M");
} 
