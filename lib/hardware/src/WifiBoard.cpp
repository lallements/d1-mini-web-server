////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2019 Sebastien Lallement. All rights reserved.
//
// This work is licensed under the terms of the MIT license that can be found in 
// the LICENSE file.
//
////////////////////////////////////////////////////////////////////////////////
#include "WifiBoard.h"

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <WiFiManager.h>

namespace
{
constexpr uint16_t g_serverPort = 80u;
constexpr auto g_timeoutSeconds = 10u;
}  // namespace

WifiBoard::WifiBoard()
    : m_pServer(new WiFiServer(g_serverPort))
{
    WiFiManager manager;
    manager.setConnectTimeout(g_timeoutSeconds);
    if (!manager.autoConnect("D1 Mini"))
    {
        Serial.println(
            "Failed to connect, resetting parameters and restarting chip.");
        manager.resetSettings();
        ESP.restart();
    }

    m_pServer->begin();
}

WifiBoard::~WifiBoard() { m_pServer->close(); }

WifiBoard::State WifiBoard::getState() const
{
    WifiBoard::State state;
    state.ssid = WiFi.SSID().c_str();
    state.localIp = WiFi.localIP().toString().c_str();
    return state;
}
