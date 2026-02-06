# IoT-Based Multi-Parameter Safety Device for Mining Environments
An IoT-based multi-parameter mining safety monitoring system using Arduino.

## Overview
Mining environments are inherently hazardous due to the presence of toxic gases, oxygen deficiency, extreme temperatures, and sudden health emergencies. Continuous monitoring of environmental and physiological parameters is essential to ensure miner safety. 

This project presents an IoT-based multi-parameter safety device that integrates multiple sensors with an Arduino microcontroller to monitor critical safety parameters in real time and trigger alerts when unsafe conditions are detected.



## Problem Statement
Underground mining environments pose significant safety risks due to gas leakage, low oxygen levels, high temperature, and lack of real-time health monitoring systems. Existing methods often rely on periodic manual checks rather than continuous monitoring.



## Proposed Solution
The proposed system continuously monitors environmental and physiological parameters using integrated sensors. The collected data is processed by an Arduino microcontroller, and if any parameter exceeds predefined safety thresholds, an alert is triggered to warn miners immediately.



## Features
- Oxygen level monitoring
- Harmful gas detection
- Temperature and humidity monitoring
- Heart rate monitoring
- Real-time LCD display
- Automatic buzzer alert system



## Components Used
- Arduino Uno
- MQ Gas Sensor
- Oxygen Sensor
- DHT11 Temperature & Humidity Sensor
- Pulse Sensor
- LCD Display
- Buzzer
- Power Supply Unit



## Working Principle
1. Sensors continuously collect environmental and physiological data.
2. Arduino processes the sensor inputs.
3. Threshold values are compared with real-time readings.
4. If unsafe levels are detected, the buzzer is activated.
5. All parameters are displayed on the LCD screen.



## Block Diagram
![Block Diagram](block%20diagram.jpeg)






## My Contribution
- Integrated sensors with Arduino microcontroller
- Developed threshold-based alert logic
- Performed system testing and calibration
- Assisted in documentation and system design



## Future Improvements
- Integration with cloud-based monitoring systems
- GSM module for remote alert notifications
- Data logging and analytics dashboard
- AI-based predictive hazard analysis



## Conclusion
This project demonstrates a cost-effective and scalable safety monitoring solution for mining environments. By integrating multiple sensing parameters and real-time alert mechanisms, the system enhances operational safety and reduces risk in hazardous underground conditions.

