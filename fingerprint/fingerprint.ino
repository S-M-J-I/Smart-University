#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include "Fingerprint.h"
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>


#define WIFI_SSID "<<SECRET>>"
#define WIFI_PASSWORD "<<SECRET>>"
#define ROOT_URL "<<SECRET>>"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("Wi-FI...");
  WiFi.hostname("ESP-host");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.print("Connected to: ");
  Serial.println(WiFi.localIP());

// fingerprint sensor begin and find/setup
fingerprint:
  fps.begin(57600);
  if (fps.verifyPassword()) {
    Serial.println("Active");
  } else {
    Serial.println("Inactive sensor");
    goto fingerprint;
  }

  WiFi.setAutoReconnect(true);
  WiFi.persistent(true);
}

void loop() {
  // put your main code here, to run repeatedly:

  /*
  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;
    
    // Your Domain name with URL path or IP address with path
    http.begin("");
    
    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    
    // Prepare your HTTP POST request data
    String httpRequestData = "?key=value";
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    
    // You can comment the httpRequestData variable above
    // then, use the httpRequestData variable below (for testing purposes without the BME280 sensor)
    //String httpRequestData = "api_key=tPmAT5Ab3j7F9&sensor=BME280&location=Office&value1=24.75&value2=49.54&value3=1005.14";
 // Send HTTP POST request
    int httpResponseCode = http.POST(httpRequestData);
     
    // If you need an HTTP request with a content type: text/plain
    //http.addHeader("Content-Type", "text/plain");
    //int httpResponseCode = http.POST("Hello, World!");
    
    // If you need an HTTP request with a content type: application/json, use the following:
    //http.addHeader("Content-Type", "application/json");
    //int httpResponseCode = http.POST("{\"value1\":\"19\",\"value2\":\"67\",\"value3\":\"78\"}");
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
else {
    Serial.println("WiFi Disconnected");
  }
  */


  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    StaticJsonBuffer<200> jsonBuffer;

    http.begin("http://10.10.226.169/microlab/api/request.php");
    int httpCode = http.GET();
    Serial.println(httpCode);
    Serial.println(http.getString());

    if (httpCode > 0) {
      Serial.println("I got something");
      JsonObject& json_parsed = jsonBuffer.parseObject(http.getString());
      http.end();
      int request = json_parsed["request"];
      Serial.println(json_parsed["request"] == 1);

      if (json_parsed["request"] == 1) {
        int id = getFingerprintID();
        int course = json_parsed["course"];
        String composed = "http://10.10.226.169/microlab/api/updateAttendance.php?";
        http.begin(composed);
        http.addHeader("Content-Type", "application/x-www-form-urlencoded");
        String content = "";
        content += "student_id=";
        content += +id;
        content += "&course=";
        content += course;
        // Serial.println(content);         
        httpCode = http.POST(content);
        Serial.println(http.getString());
        if (httpCode > 0) {
          Serial.println("Sent to file");
        } else {
          Serial.println("Error sending");
        }
      }

      if (json_parsed["request"] == 2) {      
        int id = atoi(json_parsed["id"]);
        while (!getFingerprintEnroll(id));
        if (enrollingFingerprintID > -1) {
          Serial.println("Successfully registered student");
          http.begin("http://10.10.226.169/microlab/functions/destroy_session.php");
          httpCode = http.GET();
          if(httpCode > 0) {
            Serial.println("Enrolled to fingeprint db");
          } else {
            Serial.println("Error in fingerprint enrollment");
          }         
        } else {
          Serial.println("Error with fingerprint scanner");
        }
      }
    } else {
      Serial.println("Initial response error");
    }

    http.end();
  }

  delay(3000);

  // int id = getFingerprintID();

  // if (WiFi.status() == WL_CONNECTED) {
  //   HTTPClient http;

  //   http.begin("http://192.168.0.246/microlab/api/post-from-esp.php");
  //   int httpCode = http.GET();
  //   Serial.println(httpCode);

  //   StaticJsonBuffer<200> jsonBuffer;
  //   JsonObject& json_parsed = jsonBuffer.parseObject(http.getString());

  //   http.end();

  //   if (httpCode > 0) {
  //     String name = json_parsed["name"];
  //     Serial.println(name);
  //   }
  //   else {
  //     Serial.println("Error");
  //   }

  // }
}

