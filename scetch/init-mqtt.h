#ifndef __INIT_MQTT__
#define __INIT_MQTT__

const char *mqttFileName = "/mqttConfig.json";
bool saveMqttConfigToSPIFFS(const char* server, int port, const char* user, const char* pwd, const char* device) {
  
  bool res = false;  

  DynamicJsonBuffer jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();

  json[MQTT_CONFIG_SERVER] = server;
  json[MQTT_CONFIG_PORT] = port;
  json[MQTT_CONFIG_USER] = user;
  json[MQTT_CONFIG_PWD] = pwd;
  json[MQTT_CONFIG_DEVICE_ID] = device;

  if (saveJson(mqttFileName, json)) {
    res = true;
    Serial.println("Mqtt configs are saved.");  
  }
  return res;
}

void initMqtt() {
  readFile(mqttFileName);  
}

#endif
