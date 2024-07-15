#include <WiFi.h>
#include <WiFiClient.h>
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

#define DEBUG 0

HardwareSerial mySerial(1); // Use hardware serial 1
// Create the Player object
DFRobotDFPlayerMini myDFPlayer;

// Define pin numbers using macros
#define TEMP_SENSOR_PIN 34
#define HUMIDITY_SENSOR_PIN 35
#define CARBON_SENSOR_PIN 32
#define DOORBILL_PIN 21
#define GATE_PIN 19
#define AIR_CONDITIONER_PIN 33
#define BRIGHTNESS_PIN 25
#define FAN_PIN 26
#define GARAGE_PIN 27

// WiFi credentials
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

// Server details
#define SERVER_ADDRESS "192.168.1.10"
#define SERVER_PORT 8080

WiFiClient client;

// Previous sensor values
float old_temperature = 0;
float old_humidity = 0;
float old_carbon = 0;

int old_doorBill = 0;
int old_gate = 0;

unsigned int vol = 15;

void setup() {
    Serial.begin(115200);
    mySerial.begin(9600, SERIAL_8N1, 16, 17); // RX, TX

    if (!myDFPlayer.begin(mySerial))
    {
      Serial.println(F("Unable to begin:"));
      Serial.println(F("1. Please recheck the connection!"));
      Serial.println(F("2. Please insert the SD card!"));
      while (true);
    }

    myDFPlayer.volume(vol); // Set volume value. From 0 to 30
    // myDFPlayer.play(1);    // Start playing the first track

    // Set pin modes
    pinMode(AIR_CONDITIONER_PIN, OUTPUT);
    pinMode(BRIGHTNESS_PIN, OUTPUT);
    pinMode(FAN_PIN, OUTPUT);
    pinMode(GARAGE_PIN, OUTPUT);

    pinMode(DOORBILL_PIN, INPUT);
    pinMode(GATE_PIN, INPUT);
    delay(1000);

    // Connect to WiFi
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500); // Reduced delay for faster connection attempts
        Serial.println("Connecting to WiFi...");
    }

    Serial.println("Connected to WiFi");
}

void loop() {
    if (!client.connected()) {
        Serial.println("Attempting to connect to server...");
        if (client.connect(SERVER_ADDRESS, SERVER_PORT)) {
            Serial.println("Connected to server");
        } else {
            Serial.println("Connection to server failed");
            delay(5000); // Wait 5 seconds before trying to reconnect
            return;
        }
    }

    // Check if there is incoming data from the server
    while (client.available()) {
        String command = client.readStringUntil('#');
        Serial.println("Received command from server: " + command);
        processCommand(command); // Process the received command
    }

    // Read sensor data
    float temperature = analogRead(TEMP_SENSOR_PIN);
    float humidity = analogRead(HUMIDITY_SENSOR_PIN);
    float carbon = analogRead(CARBON_SENSOR_PIN);

    int doorBill = digitalRead(DOORBILL_PIN);
    int gate = digitalRead(GATE_PIN);

    // Convert sensor readings to appropriate values
    temperature = map(temperature, 0, 4095, 0, 50); // Example mapping to 0-50 range
    humidity = map(humidity, 0, 4095, 0, 100); // Example mapping to 0-100 range
    carbon = map(carbon, 0, 4095, 0, 100); // Example mapping to 0-100 range

    // Send data only if there is a change
    if ((temperature != old_temperature) || (humidity != old_humidity) || (carbon != old_carbon) || (doorBill != old_doorBill) || (gate != old_gate)) {
        sendValues(temperature, 1, humidity, 2, carbon, 3, doorBill, 4, gate, 5);
    }

    // Update old values
    old_temperature = temperature;
    old_humidity = humidity;
    old_carbon = carbon;
    old_doorBill = doorBill;
    old_gate = gate;

    delay(100); // Send data every 0.5 seconds
}

// Function to send sensor values to the server
void sendValues(float value1, int id1, float value2, int id2, float value3, int id3, int value4, int id4, int value5, int id5) {
    char message[128];
    snprintf(message, sizeof(message), "$%d,%.2f#$%d,%.2f#$%d,%.2f#$%d,%d#$%d,%d#", id1, value1, id2, value2, id3, value3, id4, value4, id5, value5);
    client.print(message);
}

// Function to process incoming commands
void processCommand(const String &command) {
    // Expecting commands in the format "$id,value"
    int id = command.substring(1, command.indexOf(',')).toInt();
    float value = command.substring(command.indexOf(',') + 1).toFloat();

    switch (id) {
        case 6:
            analogWrite(AIR_CONDITIONER_PIN, map(value, 0, 100, 0, 255));
            Serial.println("Set Air Conditioner to: " + String(value));
            break;
        case 7:
            analogWrite(BRIGHTNESS_PIN, map(value, 0, 100, 0, 255));
            Serial.println("Set Brightness to: " + String(value));
            break;
        case 8:
            analogWrite(FAN_PIN, map(value, 0, 100, 0, 255));
            Serial.println("Set Fan to: " + String(value));
            break;
        case 9:
            digitalWrite(GARAGE_PIN, value);
            Serial.println("Set Garage to: " + String(value));
            break;
        case 10:
            if (value == 1) {
                myDFPlayer.start();
                Serial.println("DFPlayer: Play");
            } else {
                myDFPlayer.pause();
                Serial.println("DFPlayer: Pause");
            }
            break;
        case 11:
            if (value == 1) {
                myDFPlayer.next();
                Serial.println("DFPlayer: Next Track");
            } else {
                myDFPlayer.previous();
                Serial.println("DFPlayer: Previous Track");
            }
            break;
        case 12:
            vol += value;
            constrain(vol,0,30);
            myDFPlayer.volume(vol);
            Serial.println("DFPlayer: Set Volume to " + String(value));
            break;
        default:
            Serial.println("Unknown command ID: " + String(id));
            break;
    }
}
