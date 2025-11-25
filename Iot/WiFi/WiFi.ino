#include <WiFiEnterprise.h>
#include <WiFi.h>
#include <esp_eap_client.h>
#include <HTTPClient.h>
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
     int rtl = RETRY_LIMIT;
     float t = 2;
     float g = 2;
    delay(500);
    
    //Open a connection to the server
      HTTPClient http;
      http.begin("https://lmh-hx2-hold1.dk/lmh23ihch/upload.php");
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    //format your POST request.
      int httpResponseCode = http.POST("user=" + String(t) + "id=" + String(g));

      if (httpResponseCode >0){
          //check for a return code - This is more for debugging.
        String response = http.getString();
        Serial.println(httpResponseCode);
        Serial.println(response);
      }
      else{
        Serial.print("Error on sending post");
        Serial.println(httpResponseCode);
      }
    //closde the HTTP request.
      http.end();
  
    //Monitor values in console for debugging.
      Serial.println("User = " + String(t));
      Serial.println("id = " + String(g));
    
    
   //wait 2 minutes for next reading
    delay(120000);
    
}

