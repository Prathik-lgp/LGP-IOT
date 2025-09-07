#include <NinjaIoT.h>
#include <ESP8266WiFi.h>
#include "entry2.h"


NinjaIoT iot;

int SoilMoisture = 0;

void setup() {
  Serial.begin(115200);

  WiFi.begin(wifiuser, pass);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
  iot.connect(wifiuser, pass, uid);   //link: https://iot.roboninja.in/
 
}

void loop() {

  iot.ReadAll();

  if (WiFi.status() != WL_CONNECTED){
    Serial.print("Wifi disconnected. Reconnecting...");
    WiFi.begin(wifiuser, pass);
    unsigned long start = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - start < 10000){
      delay(500);
      Serial.print(".");
    }
    if (WiFi.status() == WL_CONNECTED){
      Serial.println("Reconnected");
      iot.connect(wifiuser, pass, uid);
    }
    else{
      Serial.println("Reconnection failed");
    }
  }

  SoilMoisture = analogRead(A0); // Read the analog value from A0 pin
  iot.WriteVar("SoilMoisture", SoilMoisture); // Send the value to the cloud
  
  int read = iot.SyncVar("SoilMoisture").toInt();
  if (read > 500){
    digitalWrite(5, HIGH);
    digitalWrite(2, LOW);
    delay(100);
  }
  if (read <= 500) {
    digitalWrite(5, LOW);
    digitalWrite(2, HIGH);
    delay(100);
  }
  
  delay(1500); // Wait for 1.5 seconds before sending the next value
}