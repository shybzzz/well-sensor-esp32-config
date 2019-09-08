#ifndef __INIT_SPIFFS__
#define __INIT_SPIFFS__

#define MAX_FILE_BUFF_SIZE 1024u

char fileBuff[MAX_FILE_BUFF_SIZE] = {0};

bool readFile(const char* fileName) {
  bool res = false;
  memset(fileBuff, '\0', MAX_FILE_BUFF_SIZE);
  
  if (SPIFFS.begin()){
    res = SPIFFS.exists(fileName);
    Serial.print(fileName);
    Serial.println(res?" - exists":" - does not exist");    
  } else {
    Serial.println("Failed to mount FS...");
  }

  return res;
}

bool saveJson(const char* fileName, JsonObject& json) {
  bool res = false;

  if(SPIFFS.exists(fileName)){
    if(!SPIFFS.remove(fileName)) {
      Serial.print("Failed Removing ");
      Serial.println(fileName);
      return res;
    }
  }
  
  File f = SPIFFS.open(fileName, FILE_WRITE);
  if (f) {
    serializeJson(json, f);    
    f.close();
    res = true;
  } else {
    Serial.print("Failed writing ");
    Serial.println(fileName);
  }
  
  return res;
}

bool initSPIFSS() {
  bool res = false;

  if(SPIFFS.begin()) {
    res = true;
    Serial.println("File System is mounted");
  } else {
    Serial.println("Failed to Mount File System. Formatting...");
    SPIFFS.format();
    delay(1000);
    ESP.restart();
  }

  return res;
}


#endif
