#include<Arduino.h>

int i=0;

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("the value is");
  Serial.println(i);
  i++;
  delay(5000);
}

