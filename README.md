# **What is the ESP-CisternMonitor?**
Its a project for the ESP8266 to monitor the water-level in a cistern.\
The **HC-SR-04** ultrasonic-sensor is used to calculate the distance between the
water surface which is then convert to the water-level.\
\
The motion-sensor **HC-SR-501** is used to activate the LCD only if someone enters the room, where the hardware is located. If the motion stops, the display will be turned off after a certain delay.\
\

****

## Software features
This project uses different handler-objects to organize all the implemented features:
- **OTA Update**
- **MQTT-Messages**
- **LCD-Communication**



## Components needed
For the given code, you need the following components:
 - **ESP8266**
 - **HC-SR-04**
 - **HC-SR-501**
 - **LCD-20x4**

Further on you should have an mqtt-broker available to publish the data to any device.  

## How to use
Edit *config.cpp* to match your settings. All values and their use are commented in the file.\
