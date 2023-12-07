#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "Arduino_JSON.h"
#include "global.h"
#include "get_ip.h"


bool get_ip()
{
  bool ip_status=false;
  Serial.println("inside get_ip");
  if (WiFi.status() == WL_CONNECTED)
  {
    const String ip_endpoint = "https://ipapi.co/ip/"; // It will return the public IP
    HTTPClient http;
    http.begin(ip_endpoint);
    // To capture the response of the HTTP resonse code,
    // if the value is less than 0, then there is an error in the
    int httpCode = http.GET();

    if (httpCode > 0)
    {
        // Check for the returning code
      String payload = http.getString();
      public_ip_addr = payload;
      Serial.println("The obtained IP address is ");
      Serial.println(public_ip_addr);
      Serial.println("get_ip function executed");
      return ip_status=true;
    }             
    else
    {
      Serial.println("Error on HTTP request");
      Serial.println("get_ip function not executed correctly");
      return ip_status=false;
    }
    http.end(); // Free the resource
  }
  else
  {
      Serial.println("WIFI is not connected");
      Serial.println("get_ip function not executed correctly");
      return ip_status=false;
  }
  
}

bool get_offset()
{
  bool offset_status=false;
  if (WiFi.status() == WL_CONNECTED)
  {
    const String offset_endpoint = "https://worldtimeapi.org/api/ip/"; // It will return json data
    HTTPClient http;
    http.begin(offset_endpoint + public_ip_addr);
    // To capture the response of the HTTP resonse code,
    // if the value is less than 0, then there is an error in the
    int httpCode = http.GET();

    if (httpCode > 0)
    {
    // Check for the returning code
    String payload = http.getString();
    JSONVar time_object=JSON.parse(payload);
    RAW_OFFSET=time_object["raw_offset"];
    DST_OFFSET=time_object["dst_offset"];
    Serial.println("get_offset executed");
    return offset_status=true;
    }
    else
    {
    Serial.println("Error on HTTP request");
    Serial.println("get_offset not executed correctly");
    return offset_status=false;
    }
    http.end(); // Free the resource
  }
  else
  {
    Serial.println("WiFi is not connected");
    Serial.println("get_offset not executed correctly");
    return offset_status=false;
  }
}