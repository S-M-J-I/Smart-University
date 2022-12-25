#include <FirebaseArduino.h>
#include "Fingerprint.h"
#include <ESP8266WiFi.h>


#define FIREBASE_HOST "microlab-29026-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "rcOjtxVY67Mao3mGTWecI0oWeRSvmiSLGzy0wJEr"

#define WIFI_SSID "Shourav"
#define WIFI_PASSWORD "01920788233"


void setup() {
  // put your setup code here, to run once:

  Serial.println("Wi-FI...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  Serial.print("Connected to: ");
  Serial.println(WiFi.localIP());

  // fingerprint sensor begin and find/setup
  fingerprint:
  fps.begin(57600);
  if(fps.verifyPassword()){
    Serial.println("Active");
  } else {
    Serial.println("Inactive sensor");
    goto fingerprint;
  }


  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

}
