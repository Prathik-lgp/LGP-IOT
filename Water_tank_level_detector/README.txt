Code to assign soil moisture sensor reading to variable in cloud

.h file is imported to main file and variables are used
Creates variable SoilMoisture
Connects to wifi and user id of ninja iot platform
Assigns soil moisture sensor reading to the varibale SoilMoisture
Writes the value of this variable to a variable in cloud called SoilMoisture
If wifi is disconnected (or wifi_status is not WL_connected) then tries to reconnect to wifi using WiFi.begin(ssid,password)
Even after 10 seconds if it does not reconnect then error is sent
If it does reconnect then it is again connected to the uid of ninja iot platform
Reads the value of SoilMoisture from cloud
If it is greater than 500 then water is not detected so water has not reached the maximum level yet
If it is less that 500 then water is detected so water has reached maximum level
When it is below max level green led is on and red led is off
When it reaches max level red led is on and green led is off

D4 is gpio 2 and D1 is gpio 5
.h file used to store wifi credentials in variables
.h file kept in .gitignore