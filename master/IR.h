#ifndef IR_H
#define IR_H
#include "LED.h"

#define WIRSensor 5  // connect ir welcome sensor to arduino pin 5
#define GIRSensor 6  // connect ir goodbye sensor to arduino pin 6

unsigned long timeWIR = 0;
unsigned long timeGIR = 0;


double WIR = 0.0;
double GIR = 0.0;
double THRESHOLD = 120;
int _count = 0;
bool trigger = 0;

void increaseCount() {
  _count+=1;
}

void decrementCount() {
  if (_count > 0) {
    _count-=1;
  }
}

void IRToggleRoomElec() {

  unsigned long timestamp = millis();

  WIR = digitalRead(WIRSensor);
  GIR = digitalRead(GIRSensor);

  //  Serial.print("GIR (pin 6):");
  //  Serial.println(GIR);
  //  Serial.print("WIR (pin 5):");
  //  Serial.println(WIR);

  // IF LOW THEN ONLY DETECTION
  if (WIR == LOW) {
    // for test
    Serial.println("Detected, counting");
    increaseCount();
    delay(500);
  }

  if (GIR == LOW) {
    // for test    
    Serial.println("Detected, decreasing");
    decrementCount();
    delay(500);
  }

}


#endif
