////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2019 Sebastien Lallement. All rights reserved.
//
// This work is licensed under the terms of the MIT license that can be found in 
// the LICENSE file.
//
////////////////////////////////////////////////////////////////////////////////
#include "BuiltInLED.h"

#include <Arduino.h>

BuiltInLED::BuiltInLED()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
}

void BuiltInLED::sendSOS()
{
    constexpr auto shortSignal = 200u;
    constexpr auto longSignal = 500u;
    constexpr auto signalInterval = 250u;
    constexpr auto wordInterval = 5u * signalInterval;
    while(true)
    {
        for(uint8_t i = 0u; i < 3u; i++)
        {
            digitalWrite(LED_BUILTIN, HIGH);
            delay(shortSignal);
            digitalWrite(LED_BUILTIN, LOW);
            delay(signalInterval);
        }

        delay(signalInterval);

        for(uint8_t i = 0u; i < 3u; i++)
        {
            digitalWrite(LED_BUILTIN, HIGH);
            delay(longSignal);
            digitalWrite(LED_BUILTIN, LOW);
            delay(signalInterval);
        }

        delay(signalInterval);

        for(uint8_t i = 0u; i < 3u; i++)
        {
            digitalWrite(LED_BUILTIN, HIGH);
            delay(shortSignal);
            digitalWrite(LED_BUILTIN, LOW);
            delay(signalInterval);
        }
        delay(wordInterval);
    }
}
