////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2019 Sebastien Lallement. All rights reserved.
//
// This work is licensed under the terms of the MIT license that can be found in 
// the LICENSE file.
//
////////////////////////////////////////////////////////////////////////////////
#include "OLEDDisplay.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <exception>

using namespace std;

namespace
{
constexpr auto g_resetDisplayPin = -1;  // shared with board
}

OLEDDisplay::OLEDDisplay()
    : m_pDisplay(new Adafruit_SSD1306(g_resetDisplayPin))
{
    if (m_pDisplay->begin())
    {
        // Display Adafruit logo:
        m_pDisplay->display();
    }
    else
    {
        Serial.println("Could not initialize OLED Display");
        m_pDisplay.reset();
    }
    m_pDisplay->setTextColor(WHITE);
    m_pDisplay->setTextWrap(false);
    m_pDisplay->setTextSize(1u);
}

OLEDDisplay::~OLEDDisplay() = default;

void OLEDDisplay::clear()
{
    m_pDisplay->clearDisplay();
    m_pDisplay->setCursor(0, 0);
}

void OLEDDisplay::println(const char* line)
{
    m_pDisplay->println(line);
}

void OLEDDisplay::display()
{
    m_pDisplay->display();
}

bool OLEDDisplay::isValid() const { return !!m_pDisplay; }
