// OUTSIDE ARDUINO
/**
A1 for piezo sensor
7 toggler for water sensor, A4 for read
A0 moister analog; 13 moister digial
12 for LED

9  ROOF MOTOR
10 BATTERY MOTOR

*/
#include "RoofAuto.h"
#include "LED.h"
#include "Piezo.h"
#include "WaterSensor.h"
#include "MoisterSensor.h"
#include "Piezo.h"
#include "Motor.h"

int LEDs[] = {12};

void setup() {

  Serial.begin(9600);
  pinMode(sensorToggler, OUTPUT); 
  digitalWrite(sensorToggler, LOW);
  // pinMode(relay, OUTPUT);
  servo.attach(9);
  serv2.attach(10);


  // for all leds, make them output  
  for (int i : LEDs) {
    pinMode(i, OUTPUT);
  }

}

void loop() {
  
  // ROOF
  if(readWaterS() > 20.00) {
    Serial.println(readWaterS());
    closeRoof();
  }

  if(readWaterS() <= 20.0) {
    Serial.println(readWaterS());
    openRoof();
  }


// HIGH-INACTIVE === LOW-ACTIVE
  // digitalWrite(relay, LOW);

  doMoisterAction();

  // //PIEZO PART
  double pressure = readPiezo();
  Serial.println(pressure);
  if(pressure >= THRESHOLDP) {
    Serial.println("There's pressure");
    lightUpLEDS(LEDs);
    delay(2000);
    dimDownLEDS(LEDs);
  }

  delay(1000);
}