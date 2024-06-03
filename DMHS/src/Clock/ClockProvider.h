#pragma once

#include <Arduino.h>

/**
 * \file
 * \brief   Abstracts the clock source away from our application
 */

void CP_init(int offset);

String CP_getHourAsString();
