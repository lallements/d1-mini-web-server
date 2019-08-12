////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2019 Sebastien Lallement. All rights reserved.
//
// This work is licensed under the terms of the MIT license that can be found in 
// the LICENSE file.
//
////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <chrono>

class BuiltInLED
{
public:
    BuiltInLED();

    void sendSOS();
};