#include <Arduino.h>
#include <WiFi.h>
#include "global.h"
#include "get_weather.h"
#include <HTTPClient.h>
#include "Arduino_JSON.h"


String LOC_API_KEY="04bfef32a637b84b77fda449b00ea8e0";
String WEATHER_API_KEY="72f6c969b4ea4282b22205445230212";


bool get_lat_long_info()
{
  Serial.println("inside lat_long function");
  bool lat_long_status=false;
  while(1)
  {
    if(WiFi.status()==WL_CONNECTED)
    {
      break;
    }
  }
  if (WiFi.status() == WL_CONNECTED)
    {
        String loc_endpoint = "http://api.ipstack.com/"+ public_ip_addr +"?"+"access_key="+LOC_API_KEY; // It will return json data
        HTTPClient http;
        Serial.println(loc_endpoint);
        http.begin(loc_endpoint);
        // To capture the response of the HTTP resonse code,
        // if the value is less than 0, then there is an error in the
        int httpCode = http.GET();

        if (httpCode > 0)
        {
            // Check for the returning code
            String payload = http.getString();
            JSONVar loc_object=JSON.parse(payload);
            LATITUDE=loc_object["latitude"];
            LONGITUDE=loc_object["longitude"];
            Serial.println(LATITUDE);
            Serial.println(LONGITUDE);
            Serial.println("get_lat_long function executed");
            return lat_long_status=true;
        }
        else
        {
            Serial.println("Error on HTTP request");
            Serial.println("get_lat_long function not executed correctly");
            return lat_long_status=false;
        }
        http.end(); // Free the resource
    }
    else
    {
        Serial.println("WiFi is not connected");
        Serial.println("get_lat_long function not executed correctly");
        return lat_long_status=false;
    }
}

bool get_weatherinfo()
{
  bool weather_status=false;
  get_lat_long_info();
  Serial.println("Inside get_weather function");
  if (WiFi.status() == WL_CONNECTED)
    {
        String weather_endpoint = "http://api.weatherapi.com/v1/current.json?key="+WEATHER_API_KEY+"&q="+LATITUDE+","+LONGITUDE+"&aqi=yes"; // It will return json data
        HTTPClient http;
        Serial.println(weather_endpoint);
        http.begin(weather_endpoint);
        // To capture the response of the HTTP resonse code,
        // if the value is less than 0, then there is an error in the
        int httpCode = http.GET();

        if (httpCode > 0)
        {
            // Check for the returning code
            String payload = http.getString();
            JSONVar weather_object=JSON.parse(payload);
            TEMP_C=weather_object["current"]["temp_c"];
            TEMP_F=weather_object["current"]["temp_f"];
            WIND_MPH=weather_object["current"]["wind_mph"];
            WIND_KPH=weather_object["current"]["wind_kph"];
            HUMIDITY=weather_object["current"]["humidity"];
            IS_DAY=weather_object["current"]["is_day"];
            FEELSLIKE_C=weather_object["current"]["feelslike_c"];
            FEELSLIKE_F=weather_object["current"]["feelslike_f"];
            PRECIP_MM=weather_object["current"]["precip_mm"];
            auto WEATHER_ICON=weather_object["current"]["condition"]["icon"];
            Serial.println(TEMP_C);
            Serial.println(TEMP_F);
            Serial.println(WIND_MPH);
            Serial.println(WIND_KPH);
            Serial.println(HUMIDITY);
            Serial.println(IS_DAY);
            Serial.println(FEELSLIKE_C);
            Serial.println(FEELSLIKE_F);
            Serial.println(WEATHER_ICON);
            Serial.println("get_weather_info function executed");
            return weather_status=true;
        }
        else
        {
            Serial.println("Error on HTTP request");
            Serial.println("get_weather_info function executed");
            return weather_status=false;
        }
        http.end(); // Free the resource
    }
    else
    {
        Serial.println("WiFi is not connected");
        Serial.println("get_weather_info function executed");
        return weather_status=false;
    }
}