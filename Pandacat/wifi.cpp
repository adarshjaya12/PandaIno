#include <Arduino.h>
#include "secret.h"
#include <WiFi.h>
#include "wifi.h"

void printWifiStatus() 
{
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
}


bool wifisetup() {
    int count=0;
    bool wifi_status=false;

    Serial.begin(115200);
    while (!Serial) { }

    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);

    WiFi.useStaticBuffers(true);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        count++;
        delay(500);
        Serial.print(".");
        if(count==100)
        {
          Serial.println("\nNo wifi found");
          return wifi_status=false;
        }
    }
    printWifiStatus();
    return wifi_status=true;
}