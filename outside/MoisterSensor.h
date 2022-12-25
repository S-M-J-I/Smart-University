#ifndef MOISTERSENSOR_H
#define MOISTERSENSOR_H
#include "Motor.h"

int moisterSensorPin=A0;
double limit=480;
double initMoisterValue = 0.0;


void doMoisterAction(){
    double sensorValue = analogRead(moisterSensorPin);

    Serial.print("Moisture: ");
    Serial.println(sensorValue); 

    delay(1000);

    if (sensorValue < limit) {
      Serial.println("Activating sprinkler");
      turnon();
      // return; 
    }
    else {
      turnoff();
      // return;
    }

  
}


#endif