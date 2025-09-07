#include <NinjaIoT.h>
#include "entry3.h"

NinjaIoT iot;

void setup()
{
  Serial.begin(115200);
  iot.connect(wifiuser, pass, uid); // link: https://iot.roboninja.in/
}

void loop()
{
  iot.ReadAll(); // Read all values from the cloud

  // Read IR sensor state on D2 and upload it
  iot.SyncIN("D2");

  delay(50); // wait 50 milliseconds
}
