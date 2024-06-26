// Copyright by Alex Koessler

// file based on archived yio repo
// https://github.com/YIO-Remote/dock-software/tree/master/lib/config

// Provides configuration service that persisting dock settings.

#ifndef LIBCONFIG_H
#define LIBCONFIG_H

#include <Arduino.h>
#include "blaster_config.h"

#include <Preferences.h>
#include <nvs.h>
#include <nvs_flash.h>

class Config
{
public:
    static Config &getInstance()
    {
        static Config instance; // Guaranteed to be destroyed.
                                // Instantiated on first use.
        return instance;
    }

    // getter and setter for indicator led brightness value
    // int between 0 and 100
    int getLedBrightness();
    void setLedBrightness(int value);

    // getter and setter for eth led brightness value
    // int between 0 and 100
    int getEthBrightness();
    void setEthBrightness(int value);

    // getter and setter for dock friendly name
    String getFriendlyName();
    void setFriendlyName(String value);

    // getter and setter for wifi credentials
    String getWifiSsid();
    void setWifiSsid(String value);

    String getWifiPassword();
    void setWifiPassword(String value);

    String getToken();
    void setToken(String value);

    String getHostName();

    String getSerial();

    const boolean getIRLearning() { return((BLASTER_ENABLE_IR_LEARN == true)?true:false); }

    const String getHWRevision() { return hwrevision; }

    const String getFWVersion() { return fwversion; }

    const String getDeviceModel() { return devicemodel; }

    // reset config to defaults
    void reset();

    // OTA Port currently not announced by original dock
    // int             OTA_port = 80;
    const int API_port = 946;

private:
    explicit Config();
    virtual ~Config() {}

    Preferences m_preferences;

    const int m_defaultLedBrightness = 75;

    const String hwrevision = "0.1";
    const String fwversion = "0.10.0"; //required version higher than 0.3 to allow discovery after update
    const String devicemodel = "KoeBlaster";

};

#endif