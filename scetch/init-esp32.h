#ifndef __INIT_ESP32__
#define __INIT_ESP32__

const char* espConfigFile = "/espConfig.json";

bool saveEspConfigsToSPIFFS(uint32_t delayTime) {

    bool res = false;

    DynamicJsonDocument jsonBuffer{MAX_STR_LEN};
    JsonObject json = jsonBuffer.to<JsonObject>();

    json[MEASUREMENT_DELAY] = delayTime;

    res = saveJson(espConfigFile,json);

    if (res) {
      Serial.println("ESP32 configs are saved.");  
    }

    return res;
}

void initEsp32()
{
  readFile(espConfigFile);
}
#endif
