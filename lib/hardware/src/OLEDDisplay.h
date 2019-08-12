////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2019 Sebastien Lallement. All rights reserved.
//
// This work is licensed under the terms of the MIT license that can be found in 
// the LICENSE file.
//
////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <memory>
#include <string>

class Adafruit_SSD1306;

class OLEDDisplay
{
public:
    OLEDDisplay();
    ~OLEDDisplay();

    void clear();
    void println(const char* line);
    void display();

    bool isValid() const;

private:
    std::unique_ptr<Adafruit_SSD1306> m_pDisplay;
};
