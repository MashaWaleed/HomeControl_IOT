#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "nvs_flash.h"
#include "tcpip_adapter.h"
#include "protocol_examples_common.h"

#include "DFRobotDFPlayerMini.h"

// Define WiFi credentials and server details
#define WIFI_SSID ""
#define WIFI_PASSWORD ""
#define SERVER_ADDRESS "192.168.1.10"
#define SERVER_PORT 8080

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

// Previous sensor values
float old_temperature = 0;
float old_humidity = 0;
float old_carbon = 0;
int old_doorBill = 0;
int old_gate = 0;

unsigned int vol = 15;

// WiFi client
static esp_netif_t *wifi_netif;
static esp_event_handler_instance_t wifi_event_handler_instance;

// FreeRTOS task function declarations
void task_sensor_data(void *pvParameters);
void task_wifi_client(void *pvParameters);

void app_main()
{
    // Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // Initialize WiFi
    ESP_ERROR_CHECK(example_connect());
    ESP_LOGI(TAG, "Connected to WiFi");

    // Initialize DFPlayer Mini
    DFRobotDFPlayerMini myDFPlayer;
    HardwareSerial mySerial(1); // Use hardware serial 1
    mySerial.begin(9600, SERIAL_8N1, 16, 17); // RX, TX

    if (!myDFPlayer.begin(mySerial)) {
        ESP_LOGE(TAG, "Unable to begin DFPlayer Mini");
        while (true);
    }

    myDFPlayer.volume(vol); // Set volume value. From 0 to 30

    // Create tasks
    xTaskCreate(task_sensor_data, "sensor_data_task", 4096, NULL, 5, NULL);
    xTaskCreate(task_wifi_client, "wifi_client_task", 4096, NULL, 5, NULL);
}

void task_sensor_data(void *pvParameters)
{
    while (1) {
        // Read sensor data
        float temperature = adc1_get_raw(TEMP_SENSOR_PIN);
        float humidity = adc1_get_raw(HUMIDITY_SENSOR_PIN);
        float carbon = adc1_get_raw(CARBON_SENSOR_PIN);

        int doorBill = gpio_get_level(DOORBILL_PIN);
        int gate = gpio_get_level(GATE_PIN);

        // Convert sensor readings to appropriate values
        temperature = (temperature / 4095.0) * 50.0; // Example mapping to 0-50 range
        humidity = (humidity / 4095.0) * 100.0; // Example mapping to 0-100 range
        carbon = (carbon / 4095.0) * 100.0; // Example mapping to 0-100 range

        // Send data only if there is a change
        if ((temperature != old_temperature) || (humidity != old_humidity) || (carbon != old_carbon) || (doorBill != old_doorBill) || (gate != old_gate)) {
            // Send data to server (implement sendValues function)
            // sendValues(temperature, 1, humidity, 2, carbon, 3, doorBill, 4, gate, 5);
            old_temperature = temperature;
            old_humidity = humidity;
            old_carbon = carbon;
            old_doorBill = doorBill;
            old_gate = gate;
        }

        vTaskDelay(pdMS_TO_TICKS(500)); // Send data every 0.5 seconds
    }
}

void task_wifi_client(void *pvParameters)
{
    while (1) {
        // Implement WiFi client code (connecting to server, receiving commands)
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay example
    }
}
