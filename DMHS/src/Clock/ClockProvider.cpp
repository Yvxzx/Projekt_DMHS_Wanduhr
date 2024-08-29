#include "ClockProvider.h"

#include <Arduino.h>
#include <ESP32Time.h>
#include <time.h>

static ESP32Time rtc;

/**
 * \brief   Initializes the clock access module
 * 
 * \param[in]   offset  [s] Number of seconds the timezone is away from UTC
 */
void CP_init(int offset) 
{
    // Declares a variable from the library <time.h> (struct tm)
    struct tm build_time;

    // returs a date time string, (__DATE__ " " __TIME__) is going to be replaced by current time / date 
    strptime(__DATE__ " " __TIME__, "%b %d %Y %H:%M:%S", &build_time);
    rtc.setTime(mktime(&build_time) - offset);

    rtc.offset = offset;
}

//
// Zeit in 4 teile aufteilen und als int
//


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

char Num1()
{
    String Hour1 = CP_getHourAsString(); 
    char Hour1char = Hour1.charAt(0);
    return Hour1char.ToInt();
}
char Num2()
{
    String Hour2 = CP_getHourAsString(); 
    return Hour2.charAt(1);
}
char Num3()
{
    String Minute1 = CP_getMinuteAsString(); 
    return Minute1.charAt(0);
}
char Num4()
{
    String Minute2 = CP_getMinuteAsString(); 
    return Minute2.charAt(1);
}