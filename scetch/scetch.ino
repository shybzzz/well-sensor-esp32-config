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


void setup() {
  Serial.begin(115200);
  Serial.println("Starting Well Sensor Configuration");
  initLed();
  if (initSPIFSS()) {
    initWifi();
    initMqtt();
    initSensor();
    
    saveWifiConfigToSPIFFS(WIFI_SSID, WIFI_PWD);
    saveMqttConfigToSPIFFS(MQTT_SERVER, MQTT_PORT, MQTT_USER, MQTT_PWD, MQTT_DEVICE);
    saveSensorConfigToSPIFFS(SENSOR_TYPE);
      
  }
}

void loop() {
  dance(100);
}
