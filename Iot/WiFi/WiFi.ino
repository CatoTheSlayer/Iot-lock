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
}

void loop(){
  wifi_setup();
}

bool wifi_setup(const char *ssid, const char *username, const char *password)
{
    WiFiEnterprise.end();
    if (WiFiEnterprise.begin(ssid, username, password))
    {
        Serial.println("WiFi connected");
        Serial.println(WiFiEnterprise.localIP());
        return true;
    }
    else
    {
        Serial.println("WiFi connection failed");
        Serial.println(WiFiEnterprise.status());
        return false;
    }
} 