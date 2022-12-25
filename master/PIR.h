#ifndef PIR_H
#define PIR_H


#include "LED.h"


#define PIRSensor 8

unsigned long long t = 0.0;


void measurePIR(int *LEDs) {
  if(digitalRead(PIRSensor) == HIGH) {
    t = millis(); // measure delay
    while(millis()<(t+5000)){
      lightUpLEDS(LEDs);
      if((millis()>(t+2300))&&(digitalRead(PIRSensor)==HIGH)) {
        t=millis();
      }
    }
  }
}
#endif
