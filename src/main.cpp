////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2019 Sebastien Lallement. All rights reserved.
//
// This work is licensed under the terms of the MIT license that can be found in 
// the LICENSE file.
//
////////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include <sstream>
#include <string>

#include <BuiltInLED.h>
#include <OLEDDisplay.h>
#include <WifiBoard.h>

using namespace std;

struct Context
{
    BuiltInLED builtInLed;
    OLEDDisplay oled;
    WifiBoard wifi;
};
unique_ptr<Context> pC;

void setup()
{
    // Initialize terminal log:
    Serial.begin(115200);
    Serial.println("Starting session");

    pC.reset(new Context());

    if(!pC->oled.isValid())
        pC->builtInLed.sendSOS();

    delay(500);

    auto wifiState = pC->wifi.getState();
    pC->oled.clear();
    pC->oled.println(wifiState.ssid.c_str());
    pC->oled.println(wifiState.localIp.c_str());
    pC->oled.display();
}

void loop() {}