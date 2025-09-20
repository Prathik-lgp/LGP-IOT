1. C++ Code to monitor soil moisture level in a farm

.h file is imported to main file and variables are used
Creates variable SoilMoisture
Connects to wifi and user id of ninja iot platform
Assigns soil moisture sensor reading to the varibale SoilMoisture
Writes the value of this variable to a variable in cloud called SoilMoisture
If wifi is disconnected (or wifi_status is not WL_connected) then tries to reconnect to wifi using WiFi.begin(ssid,password)
Even after 10 seconds if it does not reconnect then error is sent
If it does reconnect then it is again connected to the uid of ninja iot platform
Reads the value of pin D2 from cloud and updates on led connected to pin D2

.h file used to store wifi credentials in variables
.h file kept in .gitignore


2. html code for farm dashboard

Uses api for iot.roboninja to read and write values from and to cloud
Toggle switch on dashboard controls LED on pin D2
If soil moisture is grater than 800 then alert message is displayed on dashboard with an alarm sound
