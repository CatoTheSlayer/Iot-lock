#include <WiFiEnterprise.h>
#include <WiFi.h>
#include <esp_eap_client.h>
#define RETRY_LIMIT  20
const char* ssid = "LMH WiFi";
const char* username = "lmh23ihch";
const char* password = "Cato0422";

void setup()
{
  Serial.begin(115200);
  if (WiFiEnterprise.begin(ssid, username, password, true)) {
    Serial.println("Connected successfully!");
    Serial.print("IP Address: ");
    Serial.println(WiFiEnterprise.localIP());
  } else {
    Serial.println("Connection failed!");
  }
}

void loop(){
  
}

