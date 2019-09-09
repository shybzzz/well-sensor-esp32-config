#ifndef __INIT_SENSOR__
#define __INIT_SENSOR__

const char *sensorFileName = "/sensorConfig.json";
void initSensor() {
  readFile(sensorFileName);
}

bool saveSensorConfigToSPIFFS(uint8_t sensorType) {

  bool res = false;

  DynamicJsonDocument jsonBuffer{MAX_STR_LEN};
  JsonObject json = jsonBuffer.to<JsonObject>();

  json[SENSOR_CONFIG_TYPE] = sensorType;
  res = saveJson(sensorFileName, json);

  if (res) {
    Serial.println("Sensor Config are saved");
  }
  return res;
}

#endif
