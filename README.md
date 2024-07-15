# ESP32 IoT Home Control System with Qt GUI

![Header](./Assets/header.png)

This project features an IoT home control system utilizing the ESP32 microcontroller and a Qt-based graphical user interface (GUI). The system allows remote monitoring and control of various home devices, ensuring convenience and efficiency.

## Features

- **Real-time Sensor Monitoring:** Continuously read and display data from temperature, humidity, and carbon sensors.
- **Device Control:** Control home devices such as air conditioners, lights, fans, and garage doors through the Qt GUI.
- **DFPlayer Mini Integration:** Manage audio playback with play, pause, next, and previous track functionalities.
- **WiFi Connectivity:** Seamless connection to a home WiFi network for remote control and monitoring.
- **CAN Bus Communication:** Interface with a CAN bus for receiving and transmitting messages, applicable to automotive and home automation scenarios.
- **Slider Controls:** Adjust settings such as air conditioner temperature with interactive sliders.

## Components

- **ESP32 Devkit v1:** Microcontroller for handling sensor data, device control, and communication.
- **Qt GUI:** User-friendly interface for interacting with the home control system.
- **DFPlayer Mini:** Audio playback module controlled via the ESP32.
- **Various Sensors:** For measuring temperature, humidity, and carbon levels.
- **CAN Bus Module:** For communication with other CAN-enabled devices.

## How to Use

### Setup the ESP32:
- Connect sensors and devices to the ESP32 as per the provided schematics.
- Flash the ESP32 with the Arduino code available in this repository.

### Configure the Qt GUI:
- Open the Qt project in Qt Creator.
- Ensure the GUI is set up to communicate with the ESP32 over the specified serial port.

### Connect and Control:
- Power on the ESP32 and ensure it connects to your WiFi network.
- Run the Qt GUI application on your PC.
- Use the GUI to monitor sensor data and control home devices.

## Repository Contents

- **Arduino Code:** Contains the code to be flashed onto the ESP32.
- **Qt Project:** Includes all necessary files to set up and run the Qt GUI.
- **Schematics:** Wiring diagrams for connecting sensors and devices to the ESP32.
- **Images:** Icons and images used in the GUI.

## Contributions

Contributions are welcome! Feel free to open issues or submit pull requests for improvements and bug fixes.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
