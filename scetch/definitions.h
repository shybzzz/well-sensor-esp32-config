#ifndef __DEFINITIONS__
#define __DEFINITIONS__

#define MAX_STR_LEN                                 64u

// WIFI Config Keys
#define WIFI_CONFIG_SSID                            ("ssid")
#define WIFI_CONFIG_PWD                             ("wifiPwd")

// MQTT Config Keys
#define MQTT_CONFIG_SERVER                          ("server")
#define MQTT_CONFIG_PORT                            ("port")
#define MQTT_CONFIG_USER                            ("user")
#define MQTT_CONFIG_PWD                             ("mqttPwd")
#define MQTT_CONFIG_DEVICE_ID                       ("deviceId")

// Sensor Config Keys
#define SENSOR_CONFIG_TYPE                          ("sensorType")

// Sensor Types
#define SENSOR_SIMULATED                            0u
#define SENSOR_ANALOG_TEST                          1u
#define SENSOR_DS18B20                              2u
#define SENSOR_GUT800                               3u
#define SENSOR_INA250A2PW                           4u

#endif
