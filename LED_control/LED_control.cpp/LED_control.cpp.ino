#include <NinjaIoT.h>
#include "entry.h"

NinjaIoT iot;

void setup() {
  Serial.begin(115200);
  delay(1000);
  iot.connect(wifiuser, pass, uid);   //link: https://iot.roboninja.in/
}

void loop() {
  iot.ReadAll();   // Read all values from the cloud

  // Control LED D1 according to server value (ON/OFF)
  iot.SyncOut("D6");
  iot.SyncPWM("D7");
  delay(50);  // wait 50 milliseconds
}