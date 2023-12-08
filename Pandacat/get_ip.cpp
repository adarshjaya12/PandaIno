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
  while(1)
  {
    if(WiFi.status()== WL_CONNECTED)
    {
      break;
    }
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    const String ip_endpoint = "https://api.ipify.org/"; // It will return the public IP
    HTTPClient http;
    http.begin(ip_endpoint);
    // To capture the response of the HTTP resonse code,
    // if the value is less than 0, then there is an error in the
    int httpCode = http.GET();
    if (httpCode > 0)
    {
      // Check for the returning code
      String response = http.getString();
      public_ip_addr=response;
      Serial.println("The obtained IP address is ");
      Serial.print(public_ip_addr);
      Serial.println("\nget_ip function executed");
      http.end(); // Free the resource
      return ip_status=true;
    }             
    else
    {
      Serial.println("Error on HTTP request");
      Serial.println("get_ip function not executed correctly");
      http.end(); // Free the resource
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
  while(1)
  {
    if(WiFi.status()==WL_CONNECTED)
    {
      break;
    }
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    const String offset_endpoint = "https://worldtimeapi.org/api/ip/"; // It will return json data
    HTTPClient http;
    http.begin(offset_endpoint);
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
    Serial.print("raw_offset ");
    Serial.print (RAW_OFFSET);
    Serial.print(" dst_offset ");
    Serial.print(DST_OFFSET);
    Serial.println("\nget_offset executed");
    http.end(); // Free the resource
    return offset_status=true;
    }
    else
    {
    Serial.println("Error on HTTP request");
    Serial.println("get_offset not executed correctly");
    http.end(); // Free the resource
    return offset_status=false;
    }
  }
  else
  {
    Serial.println("WiFi is not connected");
    Serial.println("get_offset not executed correctly");
    return offset_status=false;
  }
}