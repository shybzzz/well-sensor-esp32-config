#ifndef __INIT_WIFI__
#define __INIT_WIFI__

const char *wifiFileName = "/wifiConfig.json";

bool saveWifiConfigToSPIFFS(const char* ssid, const char* pwd) {

  bool res = false;

  DynamicJsonBuffer jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();

  json[WIFI_CONFIG_SSID] = ssid;
  json[WIFI_CONFIG_PWD] = pwd;

  res = saveJson(wifiFileName, json);

  if (res) {
    Serial.println("Wifi Config are saved");
  }
  return res;
}

void initWifi() {
  readFile(wifiFileName);
}


#endif
