# SoilMate

## Description

SoilMate is an ESP8266-based IoT project that monitors soil moisture, temperature, and humidity through the Blynk app. It also lets users remotely turn a water pump on or off. Automatic watering based on soil moisture is not implemented in the current code.

## Features

- Monitors soil moisture, temperature, and humidity.
- Displays sensor readings in the Blynk app over Wi-Fi.
- Allows remote ON/OFF control of a water pump.

## Materials

- ESP8266 development board (NodeMCU-style)
- Soil moisture sensor with analog output
- DHT11 temperature and humidity sensor
- Relay module compatible with 3.3 V control signals
- DC water pump and suitable external power supply
- Jumper wires and water tubing

## Usage

Open the Blynk app to view soil moisture (V0), temperature (V2), and humidity (V3). Use the switch on V1 to turn the pump on or off.
Setup/Instructions

1. Install the Arduino IDE, ESP8266 board support, and the Blynk and DHT libraries.
2. Connect the components using the circuit diagram below. Power the pump with its own appropriately rated supply, not an ESP8266 pin.
3. Copy secrets.example.h to secrets.h and enter your own Blynk token and Wi-Fi credentials. Do not upload secrets.h to GitHub.
4. Configure Blynk datastreams V0–V3, including a switch widget for V1.
5. Open SoilMate.ino, select your ESP8266 board and port, and upload the code.

## Circuit Diagram

_to be update_
