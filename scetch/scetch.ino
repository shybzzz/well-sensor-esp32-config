#include "Arduino.h"
#include "SPIFFS.h"
#include "ArduinoJson.h"

#include "definitions.h"
#include "configuration.h"

#include "init-led.h"
#include "init-spiffs.h"
#include "init-wifi.h"
#include "init-mqtt.h"
#include "init-sensor.h"
#include "init-esp32.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Starting Well Sensor Configuration");
  initLed();
  if (initSPIFSS()) {
    initWifi();
    initMqtt();
    initSensor();
    initEsp32();
    
    saveWifiConfigToSPIFFS(WIFI_SSID, WIFI_PWD);
    saveMqttConfigToSPIFFS(MQTT_SERVER, MQTT_PORT, MQTT_USER, MQTT_PWD, MQTT_DEVICE);
    saveSensorConfigToSPIFFS(SENSOR_TYPE);
    saveEspConfigsToSPIFFS(DELAY_TIME);
      
  }
}

void loop() {
  dance(100);
}
