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

class WiFiServer;

class WifiBoard
{
public:
    WifiBoard();
    ~WifiBoard();

    struct State
    {
        std::string ssid;
        std::string localIp;
    };
    State getState() const;

private:
    std::unique_ptr<WiFiServer> m_pServer;
};
