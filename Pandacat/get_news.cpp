#include <Arduino.h>
#include <WiFi.h>
#include "global.h"
#include "get_weather.h"
#include <HTTPClient.h>
#include "Arduino_JSON.h"

String NEWS_API_LINK="https://newsapi.org/v2/top-headlines?country=in&apiKey=";
String NEWS_API_KEY="403c9055d57840958faca2d2857b5dcc";


bool get_news()
{
  Serial.println("inside get news");
  bool news_status;
  int news_size;
  String temp;
  if (WiFi.status() == WL_CONNECTED)
    {
        String news_endpoint ="https://newsapi.org/v2/top-headlines?country=in&apiKey=" +NEWS_API_KEY; // It will return json data
        HTTPClient http;
        Serial.println(news_endpoint);
        http.begin(news_endpoint);
        // To capture the response of the HTTP resonse code,
        // if the value is less than 0, then there is an error in the
        int httpCode = http.GET();

        if (httpCode > 0)
        {
            // Check for the returning code
            String payload = http.getString();
            JSONVar news_object=JSON.parse(payload);
            news_size=news_object["totalResults"];
            Serial.println(news_size);
            JSONVar article_object=news_object["articles"];
            for(int i=0;i<28;i++)
            {
              JSONVar article =article_object[i];
              String news_title=article["title"];
              String news_descp=article["description"];
              Serial.println(news_title);
              Serial.println(news_descp);
              Serial.println("*****");
            }
          Serial.println("get_news executed");
          return news_status=true;
        }
        else
        {
            Serial.println("Error on HTTP request");
            Serial.println("get_news not executed correctly");
            return news_status=false;
        }
        http.end(); // Free the resource
    }
    else
    {
        Serial.println("WiFi is not connected");
        Serial.println("get_news not executed correctly");
        return news_status=false;
    }
}
