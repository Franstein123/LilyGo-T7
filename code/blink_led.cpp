/*
*
* This is my first project to make my LilyGo T7 blink it's led.
* Started on 22.5.2023 after setting up SSH-connection to my linux laptop.
* First I should download needed expansions for lilygo and see it's manual...
* 
* After good battling with incompatable drivers and port forwarding here we are
* Now I only need to code something and build it on my ESP32... 26.5.2023
*
*
*
* Made by Frans Härkönen
*
*/

#include <stdio.h>
#include <stdint.h>
#include <Arduino.h>
#include <WiFi.h>

uint8_t luku;

void setup(){
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    Serial.println("Setup done");
}

void loop() {
    Serial.println("scan start");

    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }
    Serial.println("");

    // Wait a bit before scanning again
    delay(5000);
}

