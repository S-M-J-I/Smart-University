#ifndef ROOFAUTO_H
#define ROOFAUTO_H
#include <Servo.h>

Servo servo;


void closeRoof() {
  Serial.println("CLose roof");
  servo.write(95);
}

void openRoof(){
  Serial.println("OPEN roof");
  servo.write(185);
}

#endif 